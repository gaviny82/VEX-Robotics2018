#include "main.h"
#include "lib/event_handler.hpp"
#include "lib/chassis.hpp"
#include "robot.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
using namespace pros;

Button accel_compensation_switch(master, DIGITAL_X, [] { IsAccelCompensationEnabled = !IsAccelCompensationEnabled; });
Button autoshoot_switch(master, DIGITAL_UP, [] { IsAutoShootEnabled = !IsAutoShootEnabled; });
Button click_to_shoot(master, DIGITAL_LEFT, [] { ShootSignal = SIG_SHOOT; });
//Button reverse_switch(master, DIGITAL_DOWN, []{chassis.IsReversed = !chassis.IsReversed;});

void opcontrol()
{
	EventHandler::EnableButtonEvents();

	while (true)
	{
		//motion control
		int currentVelocity = master.get_analog(ANALOG_LEFT_Y);
		int accel = currentVelocity - chassis.CurrentSpeed;
		if ((accel > 12 || accel < -12) && IsAccelCompensationEnabled)
		{
			currentVelocity = chassis.CurrentSpeed + accel * 0.2;
		}
		chassis.Drive(currentVelocity, master.get_analog(ANALOG_RIGHT_X));

		//shoot control
		int shoot_m;
		if (IsAutoShootEnabled)
		{
			//auto shoot
			if (ShootSignal == SIG_SHOOT && IsReady)
			{
				shoot_m = 100;
				IsReady = false;
			}
			else if (shoot_switch_a.get_value() == HIGH || shoot_switch_b.get_value() == HIGH || shoot_switch_c.get_value() == HIGH)
			{
				IsReady = true;
				shoot_m = VOLT_SHOOT_HOLD;
			}
			else
			{
				ShootSignal = SIG_STANDBY;
				IsReady = false;
				shoot_m = 100;
			}
			shoot1.move(shoot_m);
			shoot2.move(shoot_m);
		}
		else
		{
			//manual shoot
			if (master.get_digital(DIGITAL_X))
			{
				shoot1.move(100);
				shoot2.move(100);
			}
			else
			{
				shoot1.move(0);
				shoot2.move(0);
			}
		}

		//manual collector control
		if (master.get_digital(DIGITAL_R1))
		{
			collector.move(100);
		}
		else if (master.get_digital(DIGITAL_R2))
		{
			collector.move(-100);
		}
		else
		{
			collector.move(0);
		}

		//arm control
		if (master.get_digital(DIGITAL_L2) && arm_switch.get_value() == LOW)
		{
			arm.move(127);
		}
		else if (master.get_digital(DIGITAL_L1))
		{
			arm.move(-127);
		}
		else
		{
			arm.move(0);
		}

		//debug messages for operator control session
		lcd::print(0, "Forward(%.3fx): %d, Yaw(%.3fx): %d, %s", chassis.ForwardCoefficient, chassis.CurrentSpeed, chassis.TurningCoefficient, chassis.CurrentYaw, chassis.IsReversed ? "Reversed" : "Forward");
		lcd::print(1, "Compensation: %s, Accel: %d", IsAccelCompensationEnabled ? "on" : "Off", accel);
		lcd::print(2, "Shoot: DEG: %s, Voltage: %d", ShootSignal == SIG_STANDBY ? "Standby" : "Shoot", shoot_m);
		lcd::print(3, "Collector state: %s%s, Collector temperature: %f", IsCollectorOn ? "On," : "Off,", IsCollectorReverse ? "Reverse" : "Collecting", collector.get_temperature());

		delay(20); /* DO NOT DELETE! If the loop goes too tight LCD will die */
	}
}

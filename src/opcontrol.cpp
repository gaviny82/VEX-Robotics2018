#include "main.h"
#include "lib/event_handler.hpp"
#include "lib/button.hpp"
#include "lib/chassis.hpp"
#include "pros/rtos.hpp"
//#include "lib/robot.hpp"

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

#define DEBUG

//configuration
#define reverse true
Motor left_f_mtr(15, MOTOR_GEARSET_18);
Motor left_b_mtr(20, MOTOR_GEARSET_18);
Motor right_f_mtr(1, MOTOR_GEARSET_18, reverse);
Motor right_b_mtr(18, MOTOR_GEARSET_18, reverse);

Motor collector(2, MOTOR_GEARSET_36, reverse);
Motor shoot1(17, MOTOR_GEARSET_6);
Motor shoot2(19, MOTOR_GEARSET_6, reverse);

Chassis chassis({ left_f_mtr, left_b_mtr }, { right_f_mtr, right_b_mtr });


ADIAnalogIn shoot_sensor('A');

bool IsCollectorOn;
bool IsCollectorReverse;

bool IsAutoShootEnabled = true;
#define POSITION_READY 3700	//TODO: Don't know if it works
bool IsReady;

#define SIG_STANDBY false
#define SIG_SHOOT true
bool ShootSignal = SIG_STANDBY;

#ifdef DEBUG
uint32_t shootCount = 0;
#endif

void autoshoot_switch_callback() {
	IsAutoShootEnabled = !IsAutoShootEnabled;
}

void collector_switch_callback() {
	IsCollectorOn = !IsCollectorOn;
}

void shoot_callback() {
	ShootSignal = SIG_SHOOT;
	shootCount++;
}
void reverse_callback() {
	chassis.IsReversed=!chassis.IsReversed;
}

void opcontrol() {
	//initialization
	Controller master(CONTROLLER_MASTER);
	chassis.TurningCoefficient = 0.7;

	Button autoshoot_switch(master, DIGITAL_UP, autoshoot_switch_callback);
	Button collector_switch(master, DIGITAL_R1, collector_switch_callback);
	Button click_to_shoot(master, DIGITAL_B, shoot_callback);
	Button reverse_switch(master, DIGITAL_DOWN, reverse_callback);
	EventHandler::EnableButtonEvents();

	int shoot_m;
	while (true) {
		//motion control
		chassis.Drive(master.get_analog(ANALOG_LEFT_Y), -master.get_analog(ANALOG_RIGHT_X));

		//shoot control
		int deg = shoot_sensor.get_value();
		if (IsAutoShootEnabled) {
			//auto shoot
			if (ShootSignal == SIG_SHOOT && IsReady) {
				shoot_m = 127;
				IsReady = false;
			}
			else if (deg < POSITION_READY && deg > 1000) {
				IsReady = true;
				shoot_m = 10;
			}
			else {
				ShootSignal = SIG_STANDBY;
				IsReady = false;
				shoot_m = 127;
			}
				shoot1.move(shoot_m);
				shoot2.move(shoot_m);
		}
		else {
			//manual shoot
			if (master.get_digital(DIGITAL_X)) {
				shoot1.move(127);
				shoot2.move(127);
			}
			else {
				shoot1.move(0);
				shoot2.move(0);
			}
		}

		//collector control
		IsCollectorReverse = master.get_digital(DIGITAL_R2);
		if (IsCollectorOn) {
			if (IsReady) {
				collector.move(127 * (IsCollectorReverse ? -1 : 1));
			}
			else {
				collector.move(-20);
			}
		}
		else {
			collector.move(0);
		}

#ifdef DEBUG
		int line = 0;
		lcd::print(line++, "Forward(%.3fx): %d, Yaw(%.3fx): %d, %s", chassis.ForwardCoefficient, chassis.CurrentSpeed, chassis.TurningCoefficient, chassis.CurrentYaw, chassis.IsReversed ? "Reversed" : "Forward");
		lcd::print(line++, "Shoot: DEG: %d, SIG: %s, Voltage: %d, Count: %ul", deg, ShootSignal == SIG_STANDBY ? "Standby" : "Shoot", shoot_m, shootCount);
		lcd::print(line++, "Collector state: %s%s, Collector temperature: %f", IsCollectorOn ? "On," : "Off,", IsCollectorReverse ? "Reverse" : "Collecting", collector.get_temperature());
#endif
		delay(20); /* DO NOT DELETE! If the loop goes too tight LCD will die */
	}
}

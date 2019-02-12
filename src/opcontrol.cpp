#include "main.h"
#include "lib/event_handler.hpp"
#include "lib/button.hpp"
#include "lib/chassis.hpp"
#include "pros/rtos.hpp"
#include "robot.hpp"
#include "lib/auto_move.hpp"

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

bool first_run = true;

#define DEBUG

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

#ifdef DEBUG
void accel_compensation_callback() {
	IsAccelCompensationEnabled = !IsAccelCompensationEnabled;
}
#endif

#ifdef DEBUG
Button accel_compensation_switch(master, DIGITAL_X, accel_compensation_callback);
#endif
Button autoshoot_switch(master, DIGITAL_UP, autoshoot_switch_callback);
//Button collector_switch(master, DIGITAL_L1, collector_switch_callback);
Button click_to_shoot(master, DIGITAL_LEFT, shoot_callback);
Button reverse_switch(master, DIGITAL_DOWN, reverse_callback);

void opcontrol() {
	//initialization
	chassis.TurningCoefficient = 0.7;
	if(first_run){
	first_run = false;
	}
	EventHandler::EnableButtonEvents();

	while (true) {
	//motion control
	int currentVelocity = master.get_analog(ANALOG_LEFT_Y);
		int accel = currentVelocity - chassis.CurrentSpeed;
		if (IsAccelCompensationEnabled) {
			if (accel > 12) {
				currentVelocity = chassis.CurrentSpeed + accel*0.1;
			}else if(accel<-12){
				currentVelocity = chassis.CurrentSpeed + accel*0.1;
			}
		}
		chassis.Drive(currentVelocity, master.get_analog(ANALOG_RIGHT_X));

		//shoot control
		int shoot_m;
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
		/*IsCollectorReverse = master.get_digital(DIGITAL_L2);
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
		}*/
		if(master.get_digital(DIGITAL_R1)){
			if (IsReady) {
				collector.move(127);
			}
			else {
				collector.move(0);//TODO: Test if the collector wroks properly when shooting
			}
		}else if(master.get_digital(DIGITAL_R2)){
				collector.move(-127);
		}else{
				collector.move(0);
		}

		if(master.get_digital(DIGITAL_L1)){
			arm.move(127);
		}else if(master.get_digital(DIGITAL_L2)){
			arm.move(-127);
		}else{
			arm.move(127);
		}

#ifdef DEBUG
		int line = 0;
		lcd::print(line++, "Forward(%.3fx): %d, Yaw(%.3fx): %d, %s", chassis.ForwardCoefficient, chassis.CurrentSpeed, chassis.TurningCoefficient, chassis.CurrentYaw, chassis.IsReversed ? "Reversed" : "Forward");
		lcd::print(line++,"Compensation: %s, Accel: %d",IsAccelCompensationEnabled?"on":"Off", accel);
		lcd::print(line++, "Shoot: DEG: %d, %s, Voltage: %d, Count: %ul", deg, ShootSignal == SIG_STANDBY ? "Standby" : "Shoot", shoot_m, shootCount);
		lcd::print(line++, "Collector state: %s%s, Collector temperature: %f", IsCollectorOn ? "On," : "Off,", IsCollectorReverse ? "Reverse" : "Collecting", collector.get_temperature());
#endif
		delay(20); /* DO NOT DELETE! If the loop goes too tight LCD will die */
	}
}

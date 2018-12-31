#include "main.h"
#include "lib/event_handler.hpp"
#include "lib/button.hpp"
#include "lib/chassis.hpp"
#include "pros/rtos.hpp"

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
Motor left_f_mtr(15, MOTOR_GEARSET_18, reverse);
Motor left_b_mtr(20, MOTOR_GEARSET_18, reverse);
Motor right_f_mtr(1, MOTOR_GEARSET_18);
Motor right_b_mtr(18, MOTOR_GEARSET_18);

Motor collector(11, MOTOR_GEARSET_36);
Motor shoot1(17, MOTOR_GEARSET_6);
Motor shoot2(19, MOTOR_GEARSET_6, reverse);

ADIAnalogIn shoot_sensor('A');

bool IsCollectorOn;
bool IsCollectorReverse;

bool IsAutoShootEnabled = true;
#define POSITION_READY 1000	//TODO: measure the ready position
bool IsReady;

#define SIG_STANDBY false
#define SIG_SHOOT true
bool ShootSignal = SIG_STANDBY;


#ifdef DEBUG
int shootCount = 0;

//[Test method]
int test = 0;
void callback_test() {
	pros::lcd::print(2, "callback test %d", ++test);
	chassis.Drive(50, 0);
	delay(1000);
	chassis.Stop();
}

void autoshoot_switch_callback() {
	IsCollectorOn = !IsCollectorOn;
}
#endif

void collector_switch_callback() {
	IsCollectorOn = !IsCollectorOn;
}

void shoot_callback() {
	ShootSignal = SIG_SHOOT;
}

void opcontrol() {
	//initialization
	Controller master(CONTROLLER_MASTER);
	Chassis chassis({ left_f_mtr, left_b_mtr }, { right_f_mtr, right_b_mtr });

#ifdef DEBUG
	Button test_btn(master, DIGITAL_L1, callback_test);
	Button autoshoot_switch(master, DIGITAL_DOWN, autoshoot_switch_callback);
#endif
	Button collector_switch(master, DIGITAL_R1, collector_switch_callback);
	Button click_to_shoot(master, DIGITAL_B, shoot_callback);
	EventHandler::EnableButtonEvents();

	while (true) {
		//motion control
		chassis.Drive(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_X));

		//shoot control
		if (IsAutoShootEnabled) {
			//auto shoot
			int deg = shoot_sensor.get_value();
			if (ShootSignal == SIG_SHOOT && IsReady) {
				shoot_sig = SIG_STANDBY;
				shoot1.move(100);
				shoot2.move(100);
				IsReady = false;
			}
			else if (deg > POSITION_READY) {
				IsReady = true;
				shoot1.move(60);
				shoot2.move(60);
			}
			else {
				IsReady = false;
				shoot1.move(100);
				shoot2.move(100);
			}
		}
		else {
			//manual shoot
			if (master.get_digital(DIGITAL_X)) {
				shoot1.move(100);
				shoot2.move(100);
			}
			else {
				shoot1.move(0);
				shoot2.move(0);
			}
		}

		//collector control
		IsCollectorReverse = master.get_digital(DIGITAL_R2);
		collector.move((int)IsCollectorOn * 127 * ((int)IsCollectorReverse * 2 - 1));

#ifdef DEBUG
		lcd::print(0, "Is KeyL1 down: %d", master.get_digital(DIGITAL_L1));
		lcd::print(1, "Forward(%fx): %d, Yaw(%fx): %d", chassis.ForwardCoefficient, forward, chassis.TurningCoefficient, yaw);
		lcd::print(2, "Shoot signal: %s, Shoot motor velocity: %f, Count: %s", ShootSignal == SIG_STANDBY ? "Standby" : "Shoot", shoot1.get_actual_velocity(), ++count);
		lcd::print(3, "Collector state: %s%s, Collector temperature: %f", IsCollectorOn ? "On," : "Off,",IsCollectorReverse?"Reverse":"Collecting",collector.get_temperature());
#endif
		delay(20);
	}
}

#include "main.h"
#include "lib/event_handler.hpp"
#include "lib/button.hpp"
#include "lib/chassis.hpp"
#include "lib/collector.h"
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

#define reverse true

//configuration
Motor left_f_mtr(15, MOTOR_GEARSET_18, reverse);
Motor left_b_mtr(20, MOTOR_GEARSET_18, reverse);
Motor right_f_mtr(1, MOTOR_GEARSET_18);
Motor right_b_mtr(18, MOTOR_GEARSET_18);

Motor collector(11, MOTOR_GEARSET_36);
Motor shoot1(17, MOTOR_GEARSET_6);
Motor shoot2(19, MOTOR_GEARSET_6, reverse);

int test = 0;

bool IsCollectorOn;
bool IsCollectorReverse;

void callback_test() {
	pros::lcd::print(2, "callback test %d", ++test);
	chassis.Drive(50, 0);
	delay(1000);
	chassis.Stop();
}

void collector_switch_callback() {
	IsCollectorOn = !IsCollectorOn;
}

void opcontrol() {
	//initialization
	Controller master(CONTROLLER_MASTER);
	Chassis chassis({ left_f_mtr, left_b_mtr }, { right_f_mtr, right_b_mtr });

	Button test_btn(master, DIGITAL_L1, callback_test);
	Button collector_switch(master, DIGITAL_R1, collector_switch_callback);
	EventHandler::EnableButtonEvents();

	while (true) {
		int forward = master.get_analog(ANALOG_LEFT_Y);
		int yaw = master.get_analog(ANALOG_RIGHT_X);

		chassis.Drive(forward, yaw);
		pros::lcd::print(0, "Is KeyA down %d", master.get_digital(DIGITAL_A));

		if (master.get_digital(DIGITAL_X)) {
			shoot1.move(100);
			shoot2.move(100);
		}
		else {
			shoot1.move(0);
			shoot2.move(0);
		}

		//collector control
		IsCollectorReverse = master.get_digital(DIGITAL_DOWN);
		collector.move((int)IsCollectorOn * 127 * ((int)IsCollectorReverse * 2 - 1));

		delay(20);
	}
}

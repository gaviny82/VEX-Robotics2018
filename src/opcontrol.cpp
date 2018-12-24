#include "main.h"
#include "lib/event_handler.hpp"
#include "lib/button.hpp"
#include "lib/chassis.hpp"
#include "lib/smart_controller.hpp"
#include "test.hpp"
#include "pros/rtos.hpp"

//#define UNIT_TEST

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

Motor left_f_mtr(15, MOTOR_GEARSET_18, reverse);
Motor left_b_mtr(20, MOTOR_GEARSET_18, reverse);
Motor right_f_mtr(1, MOTOR_GEARSET_18);
Motor right_b_mtr(18, MOTOR_GEARSET_18);

Motor collector(11, MOTOR_GEARSET_36);
Motor shoot1(17, MOTOR_GEARSET_6);
Motor shoot2(19, MOTOR_GEARSET_6, reverse);

Chassis chassis({ left_f_mtr, left_b_mtr }, { right_f_mtr, right_b_mtr });

int test=0;

void callback_test() {
	pros::lcd::print(2, "callback test %d", ++test);
	chassis.Drive(50,0);
	delay(1000);
	chassis.Stop();
}

void opcontrol() {
	Controller master(pros::E_CONTROLLER_MASTER);
	//SmartController master_smart();

	Button b1(master, DIGITAL_L1);
	b1.SetClickedEvent(callback_test);
	EventHandler::EnableButtonEvents();

#ifdef UNIT_TEST
	//Test::ChassisTest(chassis);
	//Test::ControllerEventTest();
	return;
#endif

	while (true) {
		int forward = master.get_analog(ANALOG_LEFT_Y);
		int yaw = master.get_analog(ANALOG_RIGHT_X);

		chassis.Drive(forward, yaw);
		pros::lcd::print(0, "Is KeyA down %d", master.get_digital(DIGITAL_A));

		if(master.get_digital(DIGITAL_A)){
			collector.move(127);
		}else if(master.get_digital(DIGITAL_B)){
			collector.move(-127);
		}else{
			collector.move(0);
		}


		if(master.get_digital(DIGITAL_X)){
			shoot1.move(100);
			shoot2.move(100);
		}else{
			shoot1.move(0);
			shoot2.move(0);
		}

		delay(20);
	}
}

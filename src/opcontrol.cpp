#include "main.h"
#include "lib/key_notify_event.hpp"
#include "lib/key_notify.hpp"
#include "lib/event_handler.hpp"
#include "lib/button.hpp"
#include "lib/chassis.hpp"
#include "lib/smart_controller.hpp"
#include "test.hpp"

#define UNIT_TEST

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

Motor left_f_mtr(18);
Motor left_b_mtr(9);
Motor right_f_mtr(17);
Motor right_b_mtr(7);

void callback_test() {
	printf("callback test");
	left_b_mtr.move(30);
	delay(1000);
	left_b_mtr.move(0);
}

void opcontrol() {
	Controller master(pros::E_CONTROLLER_MASTER);
	//SmartController master_smart();

	Button b1(master, DIGITAL_L1);
	b1.SetClickedEvent(callback_test);
	EventHandler::EnableButtonEvents();
	Chassis chassis({ left_f_mtr, left_b_mtr }, { right_f_mtr, right_b_mtr });

#ifdef UNIT_TEST
	Test::ChassisTest(chassis);
	//Test::ControllerEventTest();
	//KeyNotify test(master, DIGITAL_L1, callback_test);
	//KeyNotifyEvent::Register(test);
	while (true){
		delay(20);
	}
	return;
#endif

	while (true) {
		lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
			(lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
			(lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
			//chassis.Drive(master.get_analog(ANALOG_LEFT_X), master.get_analog(ANALOG_RIGHT_Y));

		int forward = master.get_analog(ANALOG_LEFT_Y);
		int yaw = master.get_analog(ANALOG_RIGHT_X);

		chassis.Drive(forward, yaw);

		delay(20);
	}
}

#include "main.h"
#include "lib/key_notify_event.hpp"
#include "lib/key_notify.hpp"
#include "lib/event_handler.hpp"
#include "lib/button.hpp"

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

Motor left_mtr(1);
Motor right_mtr(2);

void callback_test() {
	printf("callback test");
	left_mtr.move(30);
	delay(1000);
	left_mtr.move(0);
}

void opcontrol() {
	Controller master(pros::E_CONTROLLER_MASTER);

	KeyNotify test(master, DIGITAL_L1, callback_test);
	KeyNotifyEvent::Register(test);

	//Button b1(master, DIGITAL_L1);
	//b1.SetClickedEvent(callback_test);
	//EventHandler::EnableButtonEvents();

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
			(pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
			(pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);

		left_mtr = left;
		right_mtr = right;

		pros::delay(20);
	}
}

/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "API.h"
#include "motion.h"
#include "config.h"
#include "claw.h"
#include "keynotify.h"
#include "shoot.h"

void operatorControl() {
#if 0
	while (true) {
		int deg = analogRead(1);
		DBG_PRINT("PS_ARMdeg: %d \n", deg);
		delay(1000);
	}
#endif
	//initialising
	resetConfig();
	taskRunLoop(keynotify_loop, 20);
	//register key events
	set_keynotify(0, MASTER_JOYSTICK, 8, JOY_UP, callback_reverse);//reverse
	set_keynotify(1, MASTER_JOYSTICK, 7, JOY_RIGHT, callback_highSpeed);//switch to low speed
	set_keynotify(2, MASTER_JOYSTICK, 7, JOY_LEFT, callback_normalSpeed);//switch to normal speed
	set_keynotify(3, MASTER_JOYSTICK, 5, JOY_UP, callback_switchBallCollector);//switch on/off ball collector
	set_keynotify(4, MASTER_JOYSTICK, 7, JOY_DOWN, callback_autoshoot);

	while (true) {
		manualmotion_loop();
		autoshoot_loop();
		bc_joy_loop();
		motorSet(MOTOR_COLLECTOR, collectorState);
		//TODO: claw
	}
}

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
#include "shoot.h"
#include "config.h"
#include "keynotify.h"

void callback_ls() {
	ls_enabled = !ls_enabled;
}

void operatorControl() {
	//initialising
	char vertical, angular;
	resetConfig();
	taskRunLoop(keynotify_loop, 20);
	//register key events
	set_keynotify(0, MASTER_JOYSTICK, 8, JOY_UP, callback_reverse);//reverse
	set_keynotify(1, MASTER_JOYSTICK, 7, JOY_RIGHT, callback_highSpeed);//switch to low speed
	set_keynotify(2, MASTER_JOYSTICK, 7, JOY_LEFT, callback_normalSpeed);//switch to normal speed
	set_keynotify(3, MASTER_JOYSTICK, 5, JOY_UP, callback_switchBallCollector);//switch on/off ball collector
	set_keynotify(4, MASTER_JOYSTICK, 8, JOY_RIGHT, callback_ls);//limit ls
	#ifdef GLOBAL_DEBUG
	set_keynotify(5, MASTER_JOYSTICK, 7, JOY_DOWN, callback_switchAutoShoot);
	#endif

	//set_keynotify(2, MASTER_JOYSTICK, 8, JOY_DOWN, callback_shoot);//TODO: one key shoot

	while (true) {
		//motion control
		vertical = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_VERTICAL_CH);
		angular = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_ANGULAR_CH);

		if (abs(vertical) <= JOYSTICK_THROT_START) {
			vertical = 0;
		}
		if (abs(angular) <= JOYSTICK_THROT_START) {
			angular = 0;
		}
		motorSet(MOTOR_COLLECTOR, collectorState);
		setMovement(vertical, angular);

		//switch ball collector
		if (collectorState != COLLECTOR_STOP) {
			if (joystickGetDigital(MASTER_JOYSTICK, 5, JOY_DOWN)) {
				collectorState = COLLECTOR_REVERSE;
			} else {
				collectorState = COLLECTOR_ON;
			}
		}

		//rotate claw
		if (joystickGetDigital(MASTER_JOYSTICK, 6, JOY_UP)) {
			if (analogRead(POTENTIALMETER_CLAW) < 4095 && ls_enabled){
				motorSet(MOTOR_CLAW, -30);
			} else {
				motorSet(MOTOR_CLAW, 127);
			}
		}
		else if (joystickGetDigital(MASTER_JOYSTICK, 6, JOY_DOWN)) {
			motorSet(MOTOR_CLAW, -127);
		} else {
			motorSet(MOTOR_CLAW, 0);
		}

		//manual shoot
		if (joystickGetDigital(MASTER_JOYSTICK, 8, JOY_DOWN)) {
			SET_SHOOT_MOTORS(127);
		} else {
			SET_SHOOT_MOTORS(autoShoot ? 30 : 0);
		}
	}
}

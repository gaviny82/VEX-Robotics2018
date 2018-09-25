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

#include "main.h"
#include "init.h"
#include "control.h"
#include "config.h"
#include "keynotify.h"

 /* Callback function for direction */
void callback_direction() {
	direction = -direction;
}
void callback_switchBallCollector(){
	if (collectorState != COLLECTOR_STOP) {
		collectorState = COLLECTOR_STOP;
	}
	else{
		collectorState = COLLECTOR_ON;
	}
	//pending optimization
}
void callback_shoot(){

}

void operatorControl() {
	//initialising
	char vertical, angular;
	resetConfig();
	taskRunLoop(keynotify_loop, 20);
	//set key events
	set_keynotify(0, MASTER_JOYSTICK, 8, JOY_UP, callback_direction);
	set_keynotify(1, MASTER_JOYSTICK, 7, JOY_UP, callback_switchBallCollector);
	set_keynotify(2, MASTER_JOYSTICK, 8, JOY_DOWN, callback_shoot);

	while (true) {
		vertical = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_VERTICAL_CH) * 0.8;
		angular = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_ANGULAR_CH) * 0.8;
		/* JOYSTICK_THROT to prevent errors */
		if (abs(vertical) <= JOYSTICK_THROT_START) {
			vertical = 0;
		}
		if (abs(angular) <= JOYSTICK_THROT_START) {
			angular = 0;
		}

		//button functions pooling
		if (collectorState!=COLLECTOR_STOP) {
			if (joystickGetDigital(MASTER_JOYSTICK, 7, JOY_DOWN)) {
				collectorState = COLLECTOR_REVERSE;
			}
			else {
				collectorState = COLLECTOR_ON;
			}
		}

		//execute motors
		motorSet(MOTOR_COLLECTOR, collectorState);
		setMovement(vertical, angular);
	}
}

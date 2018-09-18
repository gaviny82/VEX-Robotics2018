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
#include "control.h"
#include "config.h"
#include "keynotify.h"

/* Callback function for reverseDirection */
void callback_reverseDirection() {
	reverseDirection = -reverseDirection;
}


void operatorControl() {
	char vertical, angular;
	reverseDirection = 1;

	taskRunLoop(keynotify_loop, 20);

	set_keynotify(0, MASTER_JOYSTICK,
		8, JOY_UP, callback_reverseDirection);


	while (true) {
		vertical = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_VERTICAL_CH)*0.8;
  	angular = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_ANGULAR_CH)*0.8;
    /* JOYSTICK_THROT to prevent fake values */
    if (abs(vertical) <= JOYSTICK_THROT_START) {
      vertical = 0;
    }
    if (abs(angular) <= JOYSTICK_THROT_START) {
      angular = 0;
    }
    setMovement(vertical, angular);
    //button functions pooling
  }
}

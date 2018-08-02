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

void operatorControl() {
  printf("Hello World!\n");
	char vertical, angular;
  taskRunLoop(pickballtask, 200);
	while (1) {
		vertical = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_VERTICAL_CH);
  	angular = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_ANGULAR_CH);

    /* JOYSTICK_THROT to prevent fake values */
    if (vertical <= JOYSTICK_THROT_START && vertical >= -JOYSTICK_THROT_START) {
      vertical = 0;
    }
    if (angular <= JOYSTICK_THROT_START && angular >= -JOYSTICK_THROT_START) {
      angular = 0;
    }
    setMovement(vertical, angular);
    shoot();
	} /* end main loop */
}

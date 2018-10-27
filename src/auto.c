/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "API.h"
#include "pid.h"
#include "motion.h"
#include "config.h"
#include "shoot.h"

void autonomous() {
	resetConfig();
	/*#if 0
		setMovement(-127, 0);
		delay(300);
		setMovement(0, 0);
		SET_SHOOT_MOTORS(127);
		delay(2000);
		SET_SHOOT_MOTORS(0);
		setMovement(-127, 0);
		delay(3000);
		setMovement(0, 0);
		setMovement(127, 0);
		delay(1000);
		setMovement(0, 0);
	#else
		SET_SHOOT_MOTORS(127);
		delay(2000);
		SET_SHOOT_MOTORS(0);
		setMovement(127, 0);
		delay(1000);
		setMovement(0, 0);
	#endif*/
	DBG_PRINT("autonomous started");
	goForward(1000, 127, 3000);
}

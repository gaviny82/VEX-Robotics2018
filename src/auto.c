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

#include "main.h"
#include "pid.h"
#include "control.h"
#include "config.h"
#include "init.h"

void autonomous() {
	resetConfig();
	#ifdef AUTONOMOUS_RED_FRONT

	#else
	#ifdef AUTONOMOUS_RED_BACK

	#else
	#ifdef AUTONOMOUS_BLUE_FRONT

	#else
	#ifdef AUTONOMOUS_BLUE_BACK

	#endif
	#endif
	#endif
	#endif
}

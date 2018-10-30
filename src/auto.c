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
	//TODO: set claw position
	motorSet(MOTOR_COLLECTOR, COLLECTOR_ON);
	go(1530, 127, 1900);
	go(-1335, 127, 1600);
	rotate(450, 127, 1000);
	go(630, 80, 1000);
	SET_SHOOT_MOTORS(127);
	delay(2200);
	SET_SHOOT_MOTORS(0);
	motorSet(MOTOR_COLLECTOR, COLLECTOR_STOP);
	rotate(50, 127, 1000);
	go(1000, 90, 1300);
	go(-1800, 127, 2000);
	rotate(-500, 127, 800);
	go(900, 127, 1000);
	rotate(-450, 127, 800);

	setMovement(127, 0);
	delay(2000);
	setMovement(0, 0);
	//rotate(200, 127, 1000);
}

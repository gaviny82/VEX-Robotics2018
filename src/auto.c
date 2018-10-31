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
#include "control.h"
#include "tasks.h"

void shoot_autonomous() {
	if (shoot_stage == STAGE_ZERO_POSITION)
		shoot_sig = SIG_SHOOT;
	delay(2500);//TODO: test average shoot time
}

void autonomous() {
	//initialisation
	resetConfig();
	autoShoot = taskCreate(autoshoot_loop, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	//TODO: set claw position

	//collect the ball under the leaning cap
	motorSet(MOTOR_COLLECTOR, COLLECTOR_ON);
	go(1530, 127, 1900);

	//go back and rotate anti-clockwise, then move to the shoot position
	go(-1335, 127, 1600);
	rotate(450, 127, 1000);
	go(630, 80, 1000);

	//shoot
	shoot_autonomous();
	motorSet(MOTOR_COLLECTOR, COLLECTOR_STOP);

	//adjust direction, then hit the low flag
	rotate(50, 127, 1000);
	go(1000, 90, 1300);

	//navigate to alliance parking
	go(-1800, 127, 2000);
	rotate(-500, 127, 800);
	go(900, 127, 1000);
	rotate(-450, 127, 800);

	setMovement(127, 0);
	delay(2000);

	//disposition
	setMovement(0, 0);
	taskDelete(autoShoot);
	motorSet(MOTOR_COLLECTOR, COLLECTOR_STOP);
	SET_SHOOT_MOTORS(0);
}

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

#define RED

void shoot_autonomous() {
	shoot_sig = SIG_SHOOT;
	delay(2500);//TODO: test average shoot time
}

void autonomous() {

	//initialisation
	resetConfig();
	taskRunLoop(autoshoot_loop, 100);
	//TODO: set claw position
	//collect the ball under the leaning cap
	motorSet(MOTOR_COLLECTOR, COLLECTOR_ON);
	go(1530, 127, 1900);

	//go back and rotate anti-clockwise, then move to the shoot position
	go(-1335, 127, 1600);
	rotate(-450, 127, 1000);
	go(630, 80, 1000);

	//shoot
	shoot_autonomous();
	motorSet(MOTOR_COLLECTOR, COLLECTOR_STOP);

	//adjust direction, then hit the low flag
	rotate(-70, 127, 1000);
	go(1000, 90, 1300);
// go back
	go(-800, 90, 800);
// turn right
	rotate(470, 127, 1000);
	go(1600, 90, 2300);
	rotate(-460, 127, 1000);
	go(800, 90, 1200);
	go(-850, 90, 1200);
	rotate(460, 127, 1000);
	go(1600, 90, 2300);
	rotate(-460, 127, 1000);
	go(600, 90, 1200);
	go(-1600, 90, 2300);
	//disposition
	setMovement(0, 0);
	motorSet(MOTOR_COLLECTOR, COLLECTOR_STOP);


}

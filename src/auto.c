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

#define BLUE
#define BACK

void shoot_autonomous() {
	shoot_sig = SIG_SHOOT;
	delay(2500);//TODO: test average shoot time
}

void autonomous() {
	//initialisation
	resetConfig();
	taskRunLoop(autoshoot_loop, 100);
	//collect the ball under the leaning cap
	motorSet(MOTOR_COLLECTOR, COLLECTOR_ON);
	go(1500, 60, 2000);//go back and rotate anti-clockwise, then move to the shoot position
#ifdef RED
go(-1200, 80, 1900);
rotate(-470, 127, 1000);
#else
go(-1300, 80, 1900);
rotate(480, 127, 1000);
#endif

#ifdef BACK
delay(3000);
return;
#endif

#ifdef RED
	go(560, 80, 1000);
#else
	go(570, 80, 1000);
#endif
	//shoot
	shoot_autonomous();
	//adjust direction, then hit the low flag
#ifdef RED
	rotate(-55, 127, 500);
#else
	rotate(60, 127, 500);
#endif

#ifdef RED
	go(860, 90, 1300);
#else
	go(850, 90, 1300);
#endif
	//navigate to alliance parking
	go(-1700, 127, 2000);
	motorSet(MOTOR_COLLECTOR, COLLECTOR_STOP);
#ifdef RED
	rotate(500, 127, 800);
#else
	rotate(-500, 127, 800);
#endif
	go(960, 127, 1000);
#ifdef RED
	rotate(480, 127, 800);
#else
	rotate(-480, 127, 800);
#endif
	setMovement(127, 0);
	delay(2000);

	//disposition
	setMovement(0, 0);
	motorSet(MOTOR_COLLECTOR, COLLECTOR_STOP);


}

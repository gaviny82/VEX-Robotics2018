#ifndef OPCONTROL_H_
#define OPCONTROL_H_

#include "API.h"
#include "iodefinitions.h"
Encoder leftEncoder;
Encoder rightEncoder;

/*
* Set the motor speed values for left/Right side wheels
*
* @param left side
*
*/
extern void setMotorsL(signed char speed);
extern void setMotorsR(signed char speed);

/*
* Set the relative movement speed for directions
*
* @param Vertical speed
*
* @param Angular speed
*
*/
extern void setMovement(signed char vertical, signed char angular);

/*
* detect shoot key, should be execuated in every loops
*
*/
extern void shoot();
extern void kickloop();

/*
* task to enable and disenable pickball motor, please delay between execuate
*
*/

extern void runBallCollector();

extern bool reverseBallCollector();

//extern void rise();

extern void claw();

//extern void clawRotate();

extern void reverse();
#endif

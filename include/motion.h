#ifndef MOTION_H_
#define MOTION_H_

#include "API.h"
#include "config.h"

/*
* Set the speed of motors for left/right side wheels
*
* @param Speed of motors on left/right side
*/
extern void setMotorsL(signed char speed);
extern void setMotorsR(signed char speed);

/*
* Set the relative movement speed for directions
*
* @param Vertical speed
*
* @param Angular speed
*/
extern void setMovement(signed char vertical, signed char angular);

/*
* To reverse the direction of the robot
*/
extern void callback_reverse();

/*
* turn on/off the ball collector
*/
extern void callback_switchBallCollector();

/*
* switch to high/normal speed
*/
extern void callback_highSpeed();
extern void callback_normalSpeed();


#endif

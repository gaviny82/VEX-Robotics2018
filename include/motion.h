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
* switch to high/normal speed
*/
extern void callback_highSpeed();
extern void callback_normalSpeed();

extern void manualmotion_loop();

extern signed char limit(int limit,int value);

#endif

#ifndef MOTION_H_
#define MOTION_H_

#include "API.h"
#include "config.h"

/*
* Set the speed of motors for left/right side wheels
*
* @param speed: speed of motors on left/right side
*/
extern void setMotorsL(signed char speed);
extern void setMotorsR(signed char speed);

/*
* Set the relative movement speed for directions
*
* @param vertical: vertical speed
*
* @param angular: angular speed
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

/*
* motion control using joystick 
*/
extern void manualmotion_loop();

/*
* limit a value to a certain range
*
* @param input: the value needed to be limited
*
* @param value: the maximum value
*/
extern signed char limit(int input, int value);

#endif

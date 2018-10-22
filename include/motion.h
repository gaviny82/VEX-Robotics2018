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
*
*/
extern void setMovement(signed char vertical, signed char angular);

extern void callback_reverse();

extern void callback_ls();

extern void callback_switchBallCollector();

extern void callback_highSpeed();

extern void callback_normalSpeed();

#define SET_SHOOT_MOTORS(...) do { motorSet(MOTOR_SHOOT1, __VA_ARGS__); motorSet(MOTOR_SHOOT2, __VA_ARGS__); } while (false)

#endif

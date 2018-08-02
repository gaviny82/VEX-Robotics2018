#ifndef OPCONTROL_H_
#define OPCONTROL_H_

#include "API.h"

#define MASTER_JOYSTICK 1


#define ENCODER_LEFT_TOP 1
#define ENCODER_LEFT_BOTTOM 2
#define ENCODER_RIGHT_TOP 3
#define ENCODER_RIGHT_BOTTOM 4

Encoder leftEncoder;
Encoder rightEncoder;


#define MOTOR_L_M 1
#define MOTOR_L_2 2
#define MOTOR_R_M 10
#define MOTOR_R_2 9
#define MOTOR_SHOOT 3
#define MOTOR_BALL_COLLECTOR 4
#define MOTOR_LIFT_LEFT 5
#define MOTOR_LIFT_RIGHT 6

#define JOYSTICK_ANGULAR_CH 1
#define JOYSTICK_VERTICAL_CH 3
#define JOYSTICK_THROT_START 10

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

/*
* task to enable and disenable pickball motor, please delay between execuate
*
*/

extern void runBallCollector();

extern bool reverseBallCollector();

extern void rise();
#endif

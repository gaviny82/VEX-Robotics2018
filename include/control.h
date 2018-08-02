#ifndef OPCONTROL_H_
#define OPCONTROL_H_

#define MASTER_JOYSTICK 1

#define MOTOR_L_M 1
#define MOTOR_L_2 2
#define MOTOR_R_M 10
#define MOTOR_R_2 9
#define MOTOR_SHOOT 3
#define MOTOR_PICKBALL 4

#define JOYSTICK_ANGULAR_CH 1
#define JOYSTICK_VERTICAL_CH 3
#define JOYSTICK_THROT_START 10

/*
* Set the motor speed values for left side and right side wheels
*
* @param left side
*
* @param right side
*
*/
extern void setMotorsLR(int left, int right);

/*
* Set the relative movement speed for directions
*
* @param Vertical speed
*
* @param Angular speed
*
*/
extern void setMovement(char vertical, char angular);

/*
* detect shoot key, should be execuated in every loops
*
*/
extern void shoot();

/*
* task to enable and disenable pickball motor, please delay between execuate
*
*/

extern void pickballtask();


#endif

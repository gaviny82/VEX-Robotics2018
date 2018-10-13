#ifndef CONFIG_H_
#define CONFIG_H_

#include "API.h"

bool ls_enabled;

//motors
#define MOTOR_L_FRONT 1
#define MOTOR_L_BACK 9
#define MOTOR_2L 4
#define MOTOR_R_FRONT 10
#define MOTOR_R_BACK 8
#define MOTOR_2R 5

#define MOTOR_SHOOT1 7
#define MOTOR_SHOOT2 6
#define MOTOR_COLLECTOR 2
#define MOTOR_CLAW 3


//encoders
Encoder leftEncoder;
#define ENCODER_LEFT_TOP 1
#define ENCODER_LEFT_BOTTOM 2

Encoder rightEncoder;
#define ENCODER_RIGHT_TOP 3
#define ENCODER_RIGHT_BOTTOM 4

#define POTENTIALMETER_SHOOT 1//TODO: config here after deploying sensors
#define POTENTIALMETER_CLAW 2

//joystick
#define MASTER_JOYSTICK 1

#define JOYSTICK_ANGULAR_CH 4
#define JOYSTICK_VERTICAL_CH 2
#define JOYSTICK_THROT_START 10


//configurations
#define GLOBAL_DEBUG

//autonomous positions
#define AUTONOMOUS_RED_FRONT
//#define AUTONOMOUS_RED_BACK
//#define AUTONOMOUS_BLUE_FRONT
//#define AUTONOMOUS_BLUE_BACK

extern bool isReversed;

#define COLLECTOR_STOP 0
#define COLLECTOR_REVERSE -127
#define COLLECTOR_ON 127
extern char collectorState;

#define MOTORSPEED_NORMAL 1
#define MOTORSPEED_LOW 0.35
extern float motorSpeed;

#endif

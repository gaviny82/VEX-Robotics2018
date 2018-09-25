#ifndef CONFIG_H_
#define CONFIG_H_

#include "API.h"

//motors
#define MOTOR_L1 1
#define MOTOR_2L 2
#define MOTOR_R1 10
#define MOTOR_2R 3

#define MOTOR_SHOOT 4
#define MOTOR_COLLECTOR 5
#define MOTOR_CLAW1 6
#define MOTOR_CLAW2 7


//encoders
Encoder leftEncoder;
#define ENCODER_LEFT_TOP 1
#define ENCODER_LEFT_BOTTOM 2

Encoder rightEncoder;
#define ENCODER_RIGHT_TOP 3
#define ENCODER_RIGHT_BOTTOM 4


//joystick
#define MASTER_JOYSTICK 1

#define JOYSTICK_ANGULAR_CH 1
#define JOYSTICK_VERTICAL_CH 2
#define JOYSTICK_THROT_START 10


//digital
#define DIGITAL_LIMIT_SWITCH_PIN 5


//configurations
#define GLOBAL_DEBUG

#define DIRECTION_NORMAL 1
#define DIRECTION_REVERSE -1
char direction;

#define COLLECTOR_STOP 0
#define COLLECTOR_REVERSE -127
#define COLLECTOR_ON 127
char collectorState;

#endif

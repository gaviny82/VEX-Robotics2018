#ifndef CONFIG_H_
#define CONFIG_H_

#include "API.h"

bool ls_enabled;

/*
* reset the direction and speed of motion and stop the collector
*/
extern void resetConfig();

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

#define POTENTIALMETER_CLAW 1
#define POTENTIALMETER_SHOOT 2

//joystick
#define MASTER_JOYSTICK 1

#define JOYSTICK_ANGULAR_CH 1
#define JOYSTICK_VERTICAL_CH 3
#define JOYSTICK_THROT_START 10


//debug
#define GLOBAL_DEBUG

#ifdef GLOBAL_DEBUG
#define DBG_PRINT(...) do{ fprintf(uart1,  __VA_ARGS__ ); } while( false )
#else
#define DBG_PRINT(...) do{ } while ( false )
#endif

//autonomous positions
#define AUTONOMOUS_RED_FRONT
//#define AUTONOMOUS_RED_BACK
//#define AUTONOMOUS_BLUE_FRONT
//#define AUTONOMOUS_BLUE_BACK

extern bool clawAsForward;

#define COLLECTOR_STOP 0
#define COLLECTOR_REVERSE -127
#define COLLECTOR_ON 127
extern char collectorState;

#define TURNING_NORMAL 1
#define TURNING_LOW 0.6
extern float turningSpeed;
#define SPEED_HIGH 1
#define SPEED_NORMAL 0.9
extern float verticalSpeed;

#define FREE_POSITION 0
#define LOW_POSITION 1
#define HOLD_POSITION 2

int claw_position = FREE_POSITION;

//pid tasks
extern TaskHandle leftPIDTask;
extern TaskHandle rightPIDTask;

extern void startLeftPID(int target);

extern void stopLeftPID();

extern void startRightPID(int target);

extern void stopRightPID();

#endif

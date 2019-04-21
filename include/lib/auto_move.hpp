#pragma once
#include "main.h"
#include "robot.hpp"

#define MAX_STEPS 64
#define INI_VELO 20
#define DENO_VELO 500
#define BRAKE_TIME 350
#define PID_CUT 250


typedef struct {
	float nSetPos;
	float nActPos;
	float nErr;
	float nErr_last;
	float Kp, Ki, Kd;
	float nIntegral;
	float nDiffer;
	float nPowerOut;
	float VelocityRate;
} pidctrl_t;


extern uint8_t move_state[MAX_STEPS];
extern uint32_t move_start_time[MAX_STEPS];
extern uint32_t move_brake_time[MAX_STEPS];

extern pidctrl_t pid_left;
extern pidctrl_t pid_right;

static int is_neg(int32_t num){
	if(num<0)
		return -1;
	else
		return 1;
}

enum mov_status{
  MOV_FIRST_RUN,
  MOV_WARM_START,
  MOV_RUNNING,
  MOV_WARM_BRAKE,
  MOV_ALREADY_DONE
};

#define _set_movement(MOV_VELOCITY, MOV_LEFT, MOV_RIGHT, MOV_TIME)      \
do {  \
  movecnt++;   \
  if (move_state[movecnt] == MOV_RUNNING){\
    if (millis() - move_start_time[movecnt] >= MOV_TIME){\
      move_state[movecnt] = MOV_ALREADY_DONE;\
      chassis.SetMotorsRelativeL(0, 30);\
      chassis.SetMotorsRelativeR(0, 30);\
    }\
    goto __end;\
  }\
  if (move_state[movecnt] == MOV_FIRST_RUN){\
    move_state[movecnt] = MOV_RUNNING;\
    move_start_time[movecnt] = millis();\
    chassis.ClearEncoderL();\
    chassis.ClearEncoderR();\
    chassis.SetMotorsRelativeL(MOV_LEFT, MOV_VELOCITY);\
    chassis.SetMotorsRelativeR(MOV_RIGHT, MOV_VELOCITY);\
    goto __end; \
  }\
} while (0);

#define _set_movement_warm(MOV_VELOCITY, MOV_LEFT, MOV_RIGHT, MOV_TIME)      \
do {  \
  movecnt++;   \
	if(move_state[movecnt] != MOV_ALREADY_DONE){\
  if (move_state[movecnt] == MOV_RUNNING){\
		if(abs((int32_t)(abs(chassis.GetEncoderL()) - abs(MOV_LEFT))) < PID_CUT){\
			move_state[movecnt] = MOV_WARM_BRAKE;\
			move_brake_time[movecnt] = millis();\
			chassis.SetMotorsLeft(is_neg(MOV_LEFT)*20);\
			chassis.SetMotorsRight(is_neg(MOV_RIGHT)*20);\
		}\
    if (millis() - move_start_time[movecnt] >= MOV_TIME){\
      move_state[movecnt] = MOV_ALREADY_DONE;\
      chassis.SetMotorsLeft(is_neg(MOV_LEFT)*-2);\
      chassis.SetMotorsRight(is_neg(MOV_RIGHT)*-2);\
    }\
    goto __end;\
  }\
  if (move_state[movecnt] == MOV_FIRST_RUN){\
    move_state[movecnt] = MOV_WARM_START;\
    move_start_time[movecnt] = millis();\
      chassis.ClearEncoderL();\
      chassis.ClearEncoderR();\
      chassis.SetMotorsLeft(is_neg(MOV_LEFT) * INI_VELO);\
      chassis.SetMotorsRight(is_neg(MOV_RIGHT) * INI_VELO);\
   }\
   if (move_state[movecnt] == MOV_WARM_START){\
		uint32_t time = (millis() - move_start_time[movecnt]);\
    chassis.SetMotorsLeft(is_neg(MOV_LEFT)*(MOV_VELOCITY * time / DENO_VELO + INI_VELO));\
    chassis.SetMotorsRight(is_neg(MOV_LEFT)*(MOV_VELOCITY * time / DENO_VELO + INI_VELO));\
    if(millis() - move_start_time[movecnt] >= 300){\
      move_state[movecnt] = MOV_RUNNING;\
      chassis.SetMotorsLeft(is_neg(MOV_LEFT) * MOV_VELOCITY);\
      chassis.SetMotorsRight(is_neg(MOV_RIGHT) * MOV_VELOCITY);\
    }\
   }\
	 if(move_state[movecnt] == MOV_WARM_BRAKE){\
		 if(millis() - move_brake_time[movecnt] > BRAKE_TIME || abs((int32_t)(abs(chassis.GetEncoderL()) - abs(MOV_LEFT))) < 30 ){\
			 move_state[movecnt] = MOV_ALREADY_DONE;\
			 chassis.SetMotorsLeft(is_neg(MOV_LEFT) * -2);\
			 chassis.SetMotorsRight(is_neg(MOV_LEFT) * -2);\
		 }\
	 }\
    goto __end; \
	}\
} while (0);


#define _set_onetime_task(x,cmd) \
do {  \
  movecnt++;   \
  if (move_state[movecnt] == MOV_RUNNING){\
    if (millis() - move_start_time[movecnt] >= x){\
      move_state[movecnt] = MOV_ALREADY_DONE;\
    }\
    goto __end;\
  }\
  if (move_state[movecnt] == MOV_FIRST_RUN){\
    move_state[movecnt] = MOV_RUNNING;\
    move_start_time[movecnt] = millis();\
    cmd; \
    goto __end; \
  }\
} while (0);

#define _set_delayed_task(x,cmd) \
do {  \
  movecnt++;   \
    if (move_state[movecnt] == MOV_FIRST_RUN){\
    move_state[movecnt] = MOV_RUNNING;\
    move_start_time[movecnt] = millis();\
    goto __end; \
  }\
  if (move_state[movecnt] == MOV_RUNNING){\
    if (millis() - move_start_time[movecnt] >= x){\
      move_state[movecnt] = MOV_ALREADY_DONE;\
      cmd; \
    }\
  }\
} while (0);

#define _arm_back  arm_move(127)

#define _arm_up arm.move_absolute(-2900, 500)

#define _arm_down arm.move_absolute(-3750, 500)
#define _arm_pan arm.move_absolute(-3510,500)

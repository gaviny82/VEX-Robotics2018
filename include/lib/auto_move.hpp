#pragma once
#include "main.h"
#include "robot.hpp"

#define MAX_STEPS 64

typedef struct {
	int nSetPos;
	int nActPos;
	int nErr;
	int nErr_last;
	float Kp, Ki, Kd;
	float nIntegral;
	float nDiffer;
	float nPowerOut;
	float VelocityRate;
} pidctrl_t;


extern uint8_t move_state[MAX_STEPS];
extern uint32_t move_start_time[MAX_STEPS];

extern pidctrl_t pid_left;
extern pidctrl_t pid_right;

#define PID_KP 1
#define PID_KI 0
#define PID_KD 0

#define MOV_FIRST_RUN 0
#define MOV_RUNNING 1
#define MOV_ALREADY_DONE 2

void pid_init(pidctrl_t *pid, int target)
{
	pid->Kp = PID_KP;
	pid->Ki = PID_KI;
	pid->Kd = PID_KD;
	pid->nSetPos = 0;
	pid->nActPos = 0;
	pid->nErr = 0;
	pid->nErr_last = 0;
	pid->nIntegral = 0;
	pid->nDiffer = 0;
	pid->nPowerOut = 0.0;
  pid->nSetPos = 0;
}

int pid_process(pidctrl_t *pid, int posAct)
{
	pid->nActPos = posAct;
	pid->nErr = pid->nSetPos - pid->nActPos;
	pid->nIntegral = pid->nErr_last + pid->nErr;
	pid->nDiffer = pid->nErr_last - pid->nErr;
	pid->nPowerOut = pid->Kp*pid->nErr + pid->Ki*pid->nIntegral + pid->Kd*pid->nDiffer;
	pid->nErr_last = pid->nErr;
  
	return (int)pid->nPowerOut;
}

#define _set_movement(MOV_VELOCITY, MOV_LEFT, MOV_RIGHT, MOV_TIME)      \
do {  \
  movecnt++;   \
  if (move_state[movecnt] == MOV_RUNNING){\
    if (millis() - move_start_time[movecnt] >= MOV_TIME){\
      move_state[movecnt] = MOV_ALREADY_DONE;\
      chassis.SetMotorsLeft(0);\
      chassis.SetMotorsRight(0);\
    }\
    chassis.SetMotorsLeft(pid_process(&pid_left, chassis.GetEncoderL()));\
    chassis.SetMotorsRight(pid_process(&pid_right, chassis.GetEncoderR()));\
    goto __end;\
  }\
  if (move_state[movecnt] == MOV_FIRST_RUN){\
    move_state[movecnt] = MOV_RUNNING;\
    move_start_time[movecnt] = millis();\
    chassis.ClearEncoderL();\
    chassis.ClearEncoderR();\
    pid_init(&pid_left, MOV_LEFT); \
    pid_init(&pid_right, MOV_RIGHT); \
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

#define _shoot _set_onetime_task(2000, ShootSignal = SIG_SHOOT)
#define _collector_start _set_onetime_task(0, collector.move(127))
#define _collector_reverse _set_onetime_task(0, collector.move(-127))
#define _collector_stop _set_onetime_task(0, collector.move(0))


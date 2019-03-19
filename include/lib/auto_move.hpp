#pragma once
#include "main.h"
#include "robot.hpp"

#define MAX_STEPS 64

extern uint8_t move_state[MAX_STEPS];
extern uint32_t move_start_time[MAX_STEPS];

#define MOV_FIRST_RUN 0
#define MOV_RUNNING 1
#define MOV_ALREADY_DONE 2

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


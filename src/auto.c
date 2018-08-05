/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "pid.h"
#include "control.h"
#include "iodefinitions.h"

TaskHandle leftPIDTask;
TaskHandle rightPIDTask;

static void leftPIDLoop (void *tgt) {
  int target = (int32_t)tgt;
  pid_ctrl_t pid_left;
  int pid_output;
  encoderReset(leftEncoder);

  pid_init(&pid_left);
  pid_set_gains(&pid_left, 5, 0, 1);

  while(true){
    pid_output = (int)pid_process(&pid_left, encoderGet(leftEncoder) - target);
    printf("encoder: %d", encoderGet(leftEncoder));
    setMotorsL((char)pid_output);
    taskDelay(100);
  }
}


void startLeftPID(int target) {
  if (leftPIDTask && taskGetState(leftPIDTask) == TASK_RUNNING) {
    printf("PANIC: LeftPIDTask is still running! \n");
    return;
  }
  leftPIDTask = taskCreate(leftPIDLoop, TASK_DEFAULT_STACK_SIZE, (void *)target, TASK_PRIORITY_DEFAULT + 1);
}

void stopLeftPID() {
    if (!leftPIDTask) {
      printf("INFO: Double deleting LeftPIDTask! \n");
    }
    taskDelete(leftPIDTask);
      printf("task (left wheels) stopped");
    setMotorsL(0);
}

static void rightPIDLoop (void *tgt) {
  int target = (int32_t)tgt;
  pid_ctrl_t pid_left;
  int pid_output;
  encoderReset(leftEncoder);

  pid_init(&pid_left);
  pid_set_gains(&pid_left, 5, 0, 1);

  while(true){
    pid_output = (int)pid_process(&pid_left, encoderGet(leftEncoder) - target);
    printf("encoder: %d", encoderGet(leftEncoder));
    setMotorsR((char)pid_output);
    taskDelay(100);
  }
}

void startRightPID(int target) {
  if (rightPIDTask && taskGetState(rightPIDTask) == TASK_RUNNING) {
    printf("PANIC: rightPIDTask is still running! \n");
    return;
  }
  rightPIDTask = taskCreate(rightPIDLoop, TASK_DEFAULT_STACK_SIZE, (void *)target, TASK_PRIORITY_DEFAULT + 1);
}

void stopRightPID() {
    if (!rightPIDTask) {
      printf("INFO: Double deleting rightPIDTask! \n");
    }
    taskDelete(rightPIDTask);
      printf("task (right wheels) stopped");
    setMotorsR(0);
}

void autonomous() {
  /* A test here */
  startLeftPID(1000);
  startRightPID(1000);
  taskDelay(5000);
  stopLeftPID();
  stopRightPID();
  setMovement(0,0);
}

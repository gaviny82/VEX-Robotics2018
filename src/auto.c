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

TaskHandle leftPIDTask;
TaskHandle rightPIDTask;

static void leftPIDLoop (void *tgt) {
  int target = (int32_t)tgt;
  pid_ctrl_t pid_left;
  int pid_err;
  int pid_current;
  int pid_output;
  encoderReset(leftEncoder);
  pid_init(&pid_left);
  pid_set_gains(&pid_left, 10, 0.1, 0.2);
  while(true){
    pid_current = encoderGet(leftEncoder);
    pid_err = target - pid_current;
    pid_output = pid_process(&pid_left, -pid_err);
    setMotorsL(pid_output);
    taskDelay(20);
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
    setMotorsL(0);
}

static void rightPIDLoop (void *tgt) {
  int target;
  target = (int32_t) tgt;
  pid_ctrl_t pid_right;
  int pid_err;
  int pid_current;
  int pid_output;
  encoderReset(rightEncoder);
  pid_init(&pid_right);
  pid_set_gains(&pid_right, 10., 0.1, 0.2);
  while(1){
    pid_current = encoderGet(rightEncoder);
    pid_err = target - pid_current;
    pid_output = pid_process(&pid_right, -pid_err);
    setMotorsR(pid_output);
    taskDelay(20);
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
    setMotorsR(0);
}

void autonomous() {
  /* A test here */
  startLeftPID(2000);
  startRightPID(2000);
  taskDelay(5000);
  stopLeftPID();
  stopRightPID();
}

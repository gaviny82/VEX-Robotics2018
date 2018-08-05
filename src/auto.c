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
#include "math.h"

TaskHandle leftPIDTask;
TaskHandle rightPIDTask;

static void leftPIDLoop (void *tgt) {
  int target = (int32_t)tgt;
  struct _pidctrl pid_left;
  int pid_output, pid_input;
  encoderReset(leftEncoder);
  pid_init(pid_left,1.28,0.1,0.001);

  while(true){
    pid_input =  encoderGet(leftEncoder);
    pid_output = pid_process(pid_left ,target ,pid_input);
    printf("encoderL: %d \n", pid_input);
    setMotorsL((char)pid_output);
    taskDelay(200);
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
  struct _pidctrl pid_right;
  int pid_output, pid_input;
  encoderReset(rightEncoder);
  pid_init(pid_right,1.28,0.1,0.001);

  while(true){
    pid_input =  encoderGet(rightEncoder);
    pid_output = pid_process(pid_right ,target ,pid_input);
    printf("encoderR: %d \n", pid_input);
    setMotorsR((char)pid_output);
    taskDelay(200);
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
void rotate(const int degree){

}
void move(const int horizontal, const int vertical){
  rotate(atan(vertical/horizontal));
  double dst=sqrt(pow(horizontal,2)+pow(vertical,2));
  startLeftPID(dst);
  startRightPID(dst);
}

void autonomous() {
  /* A test here */
  move(0,1000);
  taskDelay(5000);
  stopLeftPID();
  stopRightPID();
  setMovement(0,0);
}

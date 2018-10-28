/** @file config.c
 * @brief File for configuration
 *
 * This file should contain the global variables and configuration to the robot
 */
 #include "config.h"
 #include "pid.h"
 #include "motion.h"

//motion config
bool clawAsForward = false;
float turningSpeed = TURNING_NORMAL;
float verticalSpeed =  SPEED_NORMAL;

//ball collector states
char collectorState = COLLECTOR_STOP;


void resetConfig() {
	clawAsForward = false;
	collectorState = COLLECTOR_STOP;
  verticalSpeed=SPEED_NORMAL;
	turningSpeed = TURNING_LOW;
	claw_position = FREE_POSITION;
}

TaskHandle leftPIDTask;
TaskHandle rightPIDTask;

void startRightPID(int target) {
	if (rightPIDTask && taskGetState(rightPIDTask) == TASK_RUNNING) {
		DBG_PRINT("PANIC: rightPIDTask is still running! \n");
		return;
	}
	encoderReset(rightEncoder);
	rightPIDTask = taskCreate(rightPIDLoop, TASK_DEFAULT_STACK_SIZE, (void *)target, TASK_PRIORITY_DEFAULT + 1);
}

void stopRightPID() {
	if (!rightPIDTask) {
		DBG_PRINT("INFO: Double deleting rightPIDTask! \n");
	}

	taskDelete(rightPIDTask);
	DBG_PRINT("task (right wheels) stopped \n");
	setMotorsR(0);
}


void startLeftPID(int target) {
	if (leftPIDTask && taskGetState(leftPIDTask) == TASK_RUNNING) {
		DBG_PRINT("PANIC: LeftPIDTask is still running! \n");
		return;
	}
	encoderReset(leftEncoder);
	leftPIDTask = taskCreate(leftPIDLoop, TASK_DEFAULT_STACK_SIZE, (void *)target, TASK_PRIORITY_DEFAULT + 1);
}

void stopLeftPID() {
	if (!leftPIDTask) {
		DBG_PRINT("INFO: Double deleting LeftPIDTask! \n");
	}
	taskDelete(leftPIDTask);
	DBG_PRINT("task (left wheels) stopped \n");
	setMotorsL(0);
}

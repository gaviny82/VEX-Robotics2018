#include "API.h"
#include "control.h"
#include "motion.h"

TaskHandle autoShoot;

TaskHandle leftPIDTask;
TaskHandle rightPIDTask;

void startRightPID(PIDCtrl *pid) {
	if (rightPIDTask && taskGetState(rightPIDTask) == TASK_RUNNING) {
		DBG_PRINT("PANIC: rightPIDTask is still running! \n");
		return;
	}
	encoderReset(rightEncoder);
	rightPIDTask = taskCreate(rightPIDLoop, TASK_DEFAULT_STACK_SIZE, (void*)pid, TASK_PRIORITY_DEFAULT + 1);
}

void stopRightPID() {
	if (!rightPIDTask) {
		DBG_PRINT("INFO: Double deleting rightPIDTask! \n");
	}

	taskDelete(rightPIDTask);
	DBG_PRINT("task (right wheels) stopped \n");
	setMotorsR(0);
}

void startLeftPID(PIDCtrl *pid) {
	if (leftPIDTask && taskGetState(leftPIDTask) == TASK_RUNNING) {
		DBG_PRINT("PANIC: LeftPIDTask is still running! \n");
		return;
	}
	encoderReset(leftEncoder);
	leftPIDTask = taskCreate(leftPIDLoop, TASK_DEFAULT_STACK_SIZE, (void *)pid, TASK_PRIORITY_DEFAULT + 1);
}

void stopLeftPID() {
	if (!leftPIDTask) {
		DBG_PRINT("INFO: Double deleting LeftPIDTask! \n");
	}
	taskDelete(leftPIDTask);
	DBG_PRINT("task (left wheels) stopped \n");
	setMotorsL(0);
}
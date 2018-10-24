/** @file shoot.c
 * @brief File for shooting
 *
 * This file should contain functions to shoot the ball.
 */
#include "shoot.h"
#include "main.h"
#include "motion.h"

TaskHandle taskH_shoot;
bool autoShoot = false;

void shoot_task() {
	unsigned long start;
	start = millis();

	motorSet(MOTOR_SHOOT1, 127);
	motorSet(MOTOR_SHOOT2, 127);

	for (; (start - millis()) >= 2000;) delay(1);
	/* TODO: Use analog encoder to control the rotation of gears */

	motorSet(MOTOR_SHOOT1, 0);
	motorSet(MOTOR_SHOOT2, 0);
	taskSuspend(NULL);
}


void callback_shoot() {
	DBG_PRINT("Shoot Callback.");
	/* We're going to create a task here since it should not be blocked */
	if (!taskH_shoot)
		taskH_shoot = taskRunLoop(shoot_task, 0); /* Don't know if task will
																									delete itself by the end */
	if (taskGetState(taskH_shoot) != TASK_RUNNING)
		taskResume(taskH_shoot);
}

void callback_switchAutoShoot(){
	DBG_PRINT("Auto shoot switched");
	autoShoot =! autoShoot;
}

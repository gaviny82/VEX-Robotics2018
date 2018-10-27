/** @file pid.c
 * @brief File for PID control
 *
 * This file should contain PID algorithms
 */
#include "pid.h"
#include "math.h"
#include "config.h"
#include "motion.h"
#include "API.h"

void pid_init(pidctrl pid, float Kp, float Ki, float Kd)
{
	pid.Kp = Kp;
	pid.Ki = Ki;
	pid.Kd = Kd;
	pid.nSetPos = 0;
	pid.nActPos = 0;
	pid.nErr = 0;
	pid.nErr_last = 0;
	pid.nIntegral = 0;
	pid.nDiffer = 0;
	pid.nPowerOut = 0.0;
}

int pid_process(pidctrl pid, int posInput, int posAct)
{
	pid.nSetPos = posInput;
	pid.nActPos = posAct;
	pid.nErr = pid.nSetPos - pid.nActPos;
	pid.nIntegral = pid.nErr_last + pid.nErr;
	pid.nDiffer = pid.nErr_last - pid.nErr;
	pid.nPowerOut = pid.Kp*pid.nErr + pid.Ki*pid.nIntegral + pid.Kd*pid.nDiffer;
	pid.nErr_last = pid.nErr;
	return (int)pid.nPowerOut;
}

void goForward(int distance, unsigned char speed, signed int estimateTime){
	startLeftPID(distance);
	stopRightPID(distance);
	delay(estimateTime);
	stopLeftPID();
	stopRightPID();
//TODO: start pid to move to target postion
}

void rotate(int degree, unsigned char speed, signed int estimateTime){

//TODO: rotate the robot about the center
}


static void leftPIDLoop(void *tgt) {
	int target = (int32_t)tgt;
	struct _pidctrl pid_left;
	int pid_output, pid_input;
	encoderReset(leftEncoder);
	pid_init(pid_left, 1.28, 0.1, 0.001); /* Left wheel PID params here */

	while (true) {
		pid_input = encoderGet(leftEncoder);
		pid_output = pid_process(pid_left, target, pid_input);
		DBG_PRINT("encoderL: %d \n", pid_input);
		setMotorsL((char)pid_output);
		taskDelay(50);
	}
}

static void rightPIDLoop(void *tgt) {
	int target = (int32_t)tgt;
	struct _pidctrl pid_right;
	int pid_output, pid_input;
	encoderReset(rightEncoder);
	pid_init(pid_right, 1.28, 0.1, 0.001);  /* Right wheel PID params here */

	while (true) {
		pid_input = encoderGet(rightEncoder);
		pid_output = pid_process(pid_right, target, pid_input);
		DBG_PRINT("encoderR: %d \n", pid_input);
		setMotorsR((char)pid_output);
		taskDelay(50);
	}
}

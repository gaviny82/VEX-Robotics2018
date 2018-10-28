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

void pid_init(PIDCtrl *pid, float Kp, float Ki, float Kd)
{
	pid->Kp = Kp;
	pid->Ki = Ki;
	pid->Kd = Kd;
	pid->nSetPos = 0;
	pid->nActPos = 0;
	pid->nErr = 0;
	pid->nErr_last = 0;
	pid->nIntegral = 0;
	pid->nDiffer = 0;
	pid->nPowerOut = 0.0;
}

int pid_process(PIDCtrl *pid, int posInput, int posAct)
{
	pid->nSetPos = posInput;
	pid->nActPos = posAct;
	pid->nErr = pid->nSetPos - pid->nActPos;
	pid->nIntegral = pid->nErr_last + pid->nErr;
	pid->nDiffer = pid->nErr_last - pid->nErr;
	pid->nPowerOut = pid->Kp*pid->nErr + pid->Ki*pid->nIntegral + pid->Kd*pid->nDiffer;
	pid->nErr_last = pid->nErr;
	return (int)pid->nPowerOut;
}

void go(int distance, unsigned char speed, signed int estimateTime) {
	PIDCtrl arg;
	arg.max = speed;
	arg.target = -distance;
	pid_init(&arg, 0.15, 0.05, 0);

	DBG_PRINT("Going forward %d \n", distance);
	startLeftPID(&arg);
	startRightPID(&arg);
	delay(estimateTime);
	DBG_PRINT("Stopped\n");
	stopLeftPID();
	stopRightPID();
}

void rotate(int degree, unsigned char speed, signed int estimateTime) {
	PIDCtrl argsL,argsR;
	pid_init(&argsL, 0.6, 0, 0);
	pid_init(&argsR, 0.6, 0, 0);

	argsL.max = speed;
	argsR.max = speed;

	argsL.target = degree;
	argsR.target = -degree;

	startLeftPID(&argsL);
	startRightPID(&argsR);
	delay(estimateTime);
	stopLeftPID();
	stopRightPID();
	//TODO: test the pid arguments
}

void leftPIDLoop(void *tgt) {
	PIDCtrl *pid=(PIDCtrl *)tgt;
	int target = pid->target, pid_output, pid_input;
	/* Left wheel PID params here 1.28, 0.1, 0.001 */

	while (true) {
		pid_input = -encoderGet(leftEncoder);
		pid_output = pid_process(pid, target, pid_input);

		DBG_PRINT("Encoder Left: %d	", pid_input);
		char motorL = limit(pid->max, pid_output);
		DBG_PRINT("Motor Left: %d \n",motorL);
		setMotorsL(motorL);
		taskDelay(30);
	}
}

void rightPIDLoop(void* tgt) {
	PIDCtrl *pid=(PIDCtrl *)tgt;
	int target = pid->target, pid_output, pid_input;
	/* Right wheel PID params here 1.28, 0.1, 0.001 */
	while (true) {
		pid_input = -encoderGet(rightEncoder);
		pid_output = pid_process(pid, target, pid_input);
		DBG_PRINT("Encoder right: %d	", pid_input);
		char motorR = limit(pid->max, pid_output);
		DBG_PRINT("Motor right: %d\n", motorR);
		setMotorsR(motorR);
		taskDelay(30);
	}
}

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

void goForward(int distance, unsigned char speed, signed int estimateTime) {
	PIDCtrl arg;
	pid_init(&arg, 1.28, 0.1, 0);
	arg.max = speed;
	arg.target = distance;

	DBG_PRINT("Going forward %d \n", distance);
	startLeftPID(&arg);
	startRightPID(&arg);
	delay(estimateTime);
	DBG_PRINT("Stopped\n");
	stopLeftPID();
	stopRightPID();
	//TODO: test the pid arguments
}

void rotate(int degree, unsigned char speed, signed int estimateTime) {
	PIDCtrl *pidArgs;
	pid_init(pidArgs, 1.28, 0.1, 0);

	/*PIDTaskArg argLeft, argRight;
	argLeft.max = speed;
	argRight.max = speed;
	argLeft.pid = pidArgs;
	argRight.pid = pidArgs;

	argLeft.target = degree;
	argRight.target = -degree;

	startLeftPID(&argLeft);
	startRightPID(&argRight);
	delay(estimateTime);
	stopLeftPID();
	stopRightPID();*/
	//TODO: test the pid arguments
}

void leftPIDLoop(void *tgt) {
	PIDCtrl *pid=(PIDCtrl *)tgt;
	int target = pid->target, pid_output, pid_input;
	/* Left wheel PID params here 1.28, 0.1, 0.001 */

	while (true) {
		pid_input = -encoderGet(rightEncoder);
		pid_output = pid_process(pid, target, pid_input);

		DBG_PRINT("Encoder Left: %d", pid_input);
		//DBG_PRINT("Left: %d \n",pid_input);
		setMotorsL((char)(pid_output > pid->max ? pid->max : pid_output));
		taskDelay(50);
	}
}

void rightPIDLoop(void* tgt) {
	PIDCtrl *pid=(PIDCtrl *)tgt;
	int target = pid->target, pid_output, pid_input;
	/* Right wheel PID params here 1.28, 0.1, 0.001 */
	while (true) {
		pid_input = -encoderGet(rightEncoder);
		pid_output = pid_process(pid, target, pid_input);
		DBG_PRINT("Encoder right: %d", pid_input);
		//DBG_PRINT("Right: %d \n",pid_input);
		setMotorsR((char)(pid_output > pid->max ? pid->max : pid_output));
		taskDelay(50);
	}
}

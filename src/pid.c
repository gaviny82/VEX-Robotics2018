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

void pid_init(PIDCtrl pid, float Kp, float Ki, float Kd)
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

int pid_process(PIDCtrl pid, int posInput, int posAct)
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

void goForward(int distance, unsigned char speed, signed int estimateTime) {
	PIDCtrl pidArgs;
	pid_init(pidArgs, 1.28, 0.1, 0);

	PIDTaskArg arg;
	arg.max = speed;
	arg.target = distance;
	arg.pid = pidArgs;

	startLeftPID(arg);
	startRightPID(arg);
	delay(estimateTime);
	stopLeftPID();
	stopRightPID();
	//TODO: test the pid arguments
}

void rotate(int degree, unsigned char speed, signed int estimateTime) {
	PIDCtrl pidArgs;
	pid_init(pidArgs, 1.28, 0.1, 0);

	PIDTaskArg argLeft, argRight;
	argLeft.max = speed;
	argRight.max = speed;
	argLeft.pid = pidArgs;
	argRight.pid = pidArgs;

	argLeft.target = degree;
	argRight.target = -degree;

	startLeftPID(argLeft);
	startRightPID(argRight);
	delay(estimateTime);
	stopLeftPID();
	stopRightPID();
	//TODO: test the pid arguments
}

void leftPIDLoop(void *tgt) {
	PIDTaskArg arg = (PIDTaskArg)tgt;
	PIDCtrl pid_left = arg.pid;
	int target = arg.target, pid_output, pid_input;
	encoderReset(rightEncoder);/* Left wheel PID params here 1.28, 0.1, 0.001 */

	while (true) {
		pid_input = encoderGet(rightEncoder);
		pid_output = pid_process(pid_left, target, pid_input);
		DBG_PRINT("Encoder Left: %d \n", pid_input);
		setMotorsR((char)(pid_output > arg.max ? arg.max : pid_output));
		taskDelay(50);
	}
}

void rightPIDLoop(void *tgt) {
	PIDTaskArg arg = (PIDTaskArg)tgt;
	PIDCtrl pid_right = arg.pid;
	int target = arg.target, pid_output, pid_input;
	encoderReset(rightEncoder);/* Right wheel PID params here 1.28, 0.1, 0.001 */

	while (true) {
		pid_input = encoderGet(rightEncoder);
		pid_output = pid_process(pid_right, target, pid_input);
		DBG_PRINT("Encoder Right: %d \n", pid_input);
		setMotorsR((char)(pid_output > arg.max ? arg.max : pid_output));
		taskDelay(50);
	}
}

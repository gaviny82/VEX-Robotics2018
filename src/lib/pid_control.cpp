#include "lib/pid_control.hpp"

void PidControl::Pidinit(float kP, float kI, float kD) {
	Kp = kP;
	Ki = kI;
	Kd = kD;
	nSetPos = 0;
	nActPos = 0;
	nErr = 0;
	nErr_last = 0;
	nIntegral = 0;
	nDiffer = 0;
	nPowerOut = 0.0;
}

double PidControl::PidProcess(int posTarget, int posCurrent) {
	nSetPos = posTarget;
	nActPos = posCurrent;
	nErr = nSetPos - nActPos;
	nIntegral = nErr_last + nErr;
	nDiffer = nErr_last - nErr;
	nPowerOut = Kp * nErr + Ki * nIntegral + Kd * nDiffer;
	nErr_last = nErr;
	return nPowerOut;
}

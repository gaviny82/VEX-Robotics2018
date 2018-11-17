#pragma once

class PidControl {
public:
	float Kp, Ki, Kd;
	float nPowerOut;
	float max;
	float target;

	explicit PidControl(float kP, float kI, float kD);

	/*
	* return the output of a pid
	*
	* @param posTarget: target value
	* @param posCurrent: current value
	*/
	float PidProcess(int posTarget, int posCurrent);
	private:
		int nErr, nErr_last;
		int nSetPos, nActPos;
		float nIntegral;
		float nDiffer;
};

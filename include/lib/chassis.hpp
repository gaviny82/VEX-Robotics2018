#pragma once

#include "pros/motors.hpp"
#include <vector>

using namespace pros;
using namespace std;

class Chassis
{
  public:
	double ForwardCoefficient , TurningCoefficient ;
	int MaxSpeed = 127;
	bool IsReversed = false;
	int CurrentSpeed, CurrentYaw;
	vector<Motor> LeftMotors, RightMotors;

	Chassis(const initializer_list<Motor> left, const initializer_list<Motor> right, const int &maxSpeed = 0);
	void Drive(const int &forward, const int &yaw);
	void Stop();
	void SetMotorsLeft(const int &speed);
	void SetMotorsRight(const int &speed);
	void SetMotorsRelativeL(double position, int32_t speed);
	void SetMotorsRelativeR(double position, int32_t speed);
	void SetMotorsAbsoluteL(double position, int32_t speed);
	void SetMotorsAbsoluteR(double position, int32_t speed);
	void ClearEncoderL();
	void ClearEncoderR();
	double GetEncoderL();
	double GetEncoderR();
};

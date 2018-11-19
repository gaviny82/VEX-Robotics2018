#include "lib/chassis.hpp"
#include <vector>

int limit(int limit, int value) {
	if (value < -limit) {
		return -limit;
	}
	else if (value > limit) {
		return limit;
	}
	else {
		return value;
	}
}

Chassis::Chassis(const initializer_list<Motor> left, const initializer_list<Motor> right, const int &maxSpeed) {
	for (Motor mtr : left) {
		LeftMotors.push_back(mtr);
	}
	for (Motor mtr : right) {
		RightMotors.push_back(mtr);
	}
	MaxSpeed = maxSpeed;
}

void Chassis::Drive(const int &forward, const int &yaw) {
	int realforward = forward * (IsReversed ? 1 : -1);
	int left = ForwardCoefficient * realforward + TurningCoefficient * yaw;
	int right = ForwardCoefficient * realforward - TurningCoefficient * yaw;

	SetMotorLeft(limit(127, left));
	SetMotorRight(limit(127, right));
}

void Chassis::Stop() {
	SetMotorLeft(0);
	SetMotorRight(0);
}

void Chassis::SetMotorLeft(const int &speed) {
	for (Motor mtr : LeftMotors) {
		mtr.move(speed);
	}
}

void Chassis::SetMotorRight(const int &speed) {
	for (Motor mtr : RightMotors) {
		mtr.move(speed);
	}
}

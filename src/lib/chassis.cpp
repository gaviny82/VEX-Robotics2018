#include "main.h"
#include "lib/chassis.hpp"
#include <vector>

int limit(const int &limit, const int &value)
{
	if (value < -limit)
	{
		return -limit;
	}
	else if (value > limit)
	{
		return limit;
	}
	else
	{
		return value;
	}
}

Chassis::Chassis(const initializer_list<Motor> left, const initializer_list<Motor> right,  const int &maxSpeed)
{
	for (Motor mtr : left)
	{
		LeftMotors.push_back(mtr);
	}
	for (Motor mtr : right)
	{
		RightMotors.push_back(mtr);
	}
	MaxSpeed = maxSpeed;
}

void Chassis::Drive(const int &forward, const int &yaw)
{
	CurrentSpeed = limit(127, forward);
	CurrentYaw = limit(127, yaw);
	ForwardCoefficient = 0.9;
	TurningCoefficient = 0.7;
	int left = ForwardCoefficient * CurrentSpeed * (IsReversed ? -1 : 1) + TurningCoefficient * CurrentYaw;
	int right = ForwardCoefficient * CurrentSpeed * (IsReversed ? -1 : 1) - TurningCoefficient * CurrentYaw;

	SetMotorsLeft(limit(127, left));
	SetMotorsRight(limit(127, right));
}

void Chassis::Stop()
{
	SetMotorsLeft(0);
	SetMotorsRight(0);
}

void Chassis::SetMotorsLeft(const int &speed)
{
	for (Motor mtr : LeftMotors)
	{
		mtr.move(speed);
	}
}

void Chassis::SetMotorsRight(const int &speed)
{
	for (Motor mtr : RightMotors)
	{
		mtr.move(speed);
	}
}

void Chassis::SetMotorsRelativeL(double position, int32_t speed)
{
	for (Motor mtr : LeftMotors)
	{
		mtr.move_relative(position, speed);
	}
}

void Chassis::SetMotorsRelativeR(double position, int32_t speed)
{
	for (Motor mtr : RightMotors)
	{
		mtr.move_relative(position, speed);
	}
}

void Chassis::SetMotorsAbsoluteL(double position, int32_t speed)
{
	for (Motor mtr : LeftMotors)
	{
		mtr.move_absolute(position, speed);
	}
}

void Chassis::SetMotorsAbsoluteR(double position, int32_t speed)
{
	for (Motor mtr : RightMotors)
	{
		mtr.move_absolute(position, speed);
	}
}


void Chassis::ClearEncoderL()
{
	for (Motor mtr : LeftMotors)
	{
		mtr.set_encoder_units(E_MOTOR_ENCODER_COUNTS);
		mtr.tare_position();
	}
}

void Chassis::ClearEncoderR()
{
	for (Motor mtr : RightMotors)
	{
		mtr.set_encoder_units(E_MOTOR_ENCODER_COUNTS);
		mtr.tare_position();
	}
}
//for arm used
/*
void Chassis::clearEncoderArm()
{
for(Motor mtr : Armmotors)
	{
		mtr.set_encodder_units(E_MOTOR_ENCODER_COUNTS);
		mtr.tare_position();
	}
}*/

double Chassis::GetEncoderL()
{
	double total = 0;
	uint16_t cnt = 0;
	for (Motor mtr : LeftMotors)
	{
		total = total + mtr.get_position(); //FIXME: tare position?
		cnt++;
	}
	return total / cnt;
}

double Chassis::GetEncoderR()
{
	double total = 0;
	uint16_t cnt = 0;
	for (Motor mtr : RightMotors)
	{
		total = total + mtr.get_position(); //FIXME: tare position?
		cnt++;
	}
	return total / cnt;
}

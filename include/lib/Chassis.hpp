#pragma once

#include "pros/motors.hpp"
#include <vector>

using namespace pros;
using namespace std;

class Chassis{
public:
  double ForwardCoefficient = 1, TurningCoefficient = 1;
  int MaxSpeed = 127;
  bool IsReversed = false;
  int CurrentSpeed, CurrentYaw;
  vector<Motor> LeftMotors, RightMotors;

  Chassis(const initializer_list<Motor> left, const initializer_list<Motor> right, const int &maxSpeed);
  void Drive(const int &forward, const int &yaw);
  void Stop();
  void SetMotorsLeft(const int &speed);
  void SetMotorsRight(const int &speed);
};

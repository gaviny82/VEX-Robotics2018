#pragma once
#include "pros/misc.hpp"
#include "pros/motors.hpp"

using namespace std;
using namespace pros;

template <typename Input>
class MotorController{
public:
  MotorController(Input &inputSensor){};

  bool IsEnabled(){return isEnabled;}
  void Disable();

  virtual void Reset();
private:
  //Motor motor;
  Input sensor;
  bool isEnabled=false;
};

#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_

#include "main.h"
#include "lib/button.hpp"
#include "lib/chassis.hpp"

using namespace pros;

#define reverse true
extern Motor left_f_mtr;
extern Motor left_b_mtr;
extern Motor right_f_mtr;
extern Motor right_b_mtr;

extern Motor collector;
extern Motor shoot1;
extern Motor shoot2;
extern Motor arm;

extern Chassis chassis;

extern Controller master;

extern ADIAnalogIn shoot_sensor;

//configuration
extern bool IsCollectorOn;
extern bool IsCollectorReverse;

#define POSITION_READY 3750
#define VOLT_SHOOT_HOLD 7

extern bool IsAutoShootEnabled;
extern bool IsReady;

#define SIG_STANDBY false
#define SIG_SHOOT true
extern bool ShootSignal;

extern bool IsAccelCompensationEnabled;

#endif

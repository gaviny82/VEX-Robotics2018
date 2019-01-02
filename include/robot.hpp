#pragma once
#include "main.h"
#include "lib/button.hpp"
#include "lib/chassis.hpp"
#include "lib/robot.hpp"

using namespace pros;

#define reverse true
Motor left_f_mtr(15, MOTOR_GEARSET_18);
Motor left_b_mtr(20, MOTOR_GEARSET_18);
Motor right_f_mtr(1, MOTOR_GEARSET_18, reverse);
Motor right_b_mtr(18, MOTOR_GEARSET_18, reverse);

Motor collector(2, MOTOR_GEARSET_36, reverse);
Motor shoot1(17, MOTOR_GEARSET_6);
Motor shoot2(19, MOTOR_GEARSET_6, reverse);

Chassis chassis({ left_f_mtr, left_b_mtr }, { right_f_mtr, right_b_mtr });

ADIAnalogIn shoot_sensor('A');

//configuration
bool IsCollectorOn;
bool IsCollectorReverse;

bool IsAutoShootEnabled = true;
#define POSITION_READY 3700	//TODO: Don't know if it works
bool IsReady;

#define SIG_STANDBY false
#define SIG_SHOOT true
bool ShootSignal = SIG_STANDBY;

bool IsAccelCompensationEnabled = true;

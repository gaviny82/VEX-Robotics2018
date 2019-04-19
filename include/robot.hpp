#pragma once

#include "main.h"
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

extern ADIDigitalIn shoot_switch_a;
extern ADIDigitalIn shoot_switch_b;
extern ADIDigitalIn shoot_switch_c;

extern ADIDigitalIn arm_switch;

//configuration and status
extern bool IsCollectorOn;
extern bool IsCollectorReverse;

#define VOLT_SHOOT_HOLD 8

extern bool IsAutoShootEnabled;
extern bool IsReady;

#define SIG_STANDBY false
#define SIG_SHOOT true
extern bool ShootSignal;

extern bool IsAccelCompensationEnabled;
//autonomous
extern uint16_t movecnt;

extern void reset_config();

#define PID_KP 0.2
#define PID_KI 0
#define PID_KD 0

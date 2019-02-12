#include "robot.hpp"

#define reverse true
Motor left_f_mtr(15, MOTOR_GEARSET_18);
Motor left_b_mtr(20, MOTOR_GEARSET_18);
Motor right_f_mtr(3, MOTOR_GEARSET_18, reverse);
Motor right_b_mtr(18, MOTOR_GEARSET_18, reverse);

Motor collector(2, MOTOR_GEARSET_36, reverse);
Motor shoot1(17, MOTOR_GEARSET_6);
Motor shoot2(19, MOTOR_GEARSET_6, reverse);
Motor arm(12, MOTOR_GEARSET_18, reverse);

Chassis chassis({ left_f_mtr, left_b_mtr }, { right_f_mtr, right_b_mtr });

Controller master(CONTROLLER_MASTER);

//configuration
bool IsCollectorOn;
bool IsCollectorReverse;

bool IsAutoShootEnabled = true;

bool IsReady;

#define SIG_STANDBY false
#define SIG_SHOOT true
bool ShootSignal = SIG_STANDBY;

ADIAnalogIn shoot_sensor('A');

bool IsAccelCompensationEnabled = true;

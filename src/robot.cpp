#include "robot.hpp"
#include "lib/auto_move.hpp"

Motor left_f_mtr(15, MOTOR_GEARSET_18);
Motor left_b_mtr(20, MOTOR_GEARSET_18);
Motor right_f_mtr(3, MOTOR_GEARSET_18, reverse);
Motor right_b_mtr(18, MOTOR_GEARSET_18, reverse);

Motor collector(8, MOTOR_GEARSET_36, reverse);
Motor shoot1(17, MOTOR_GEARSET_6);
Motor shoot2(19, MOTOR_GEARSET_6, reverse);
Motor arm(14, MOTOR_GEARSET_18, reverse);

Chassis chassis({left_f_mtr, left_b_mtr}, {right_f_mtr, right_b_mtr});

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

void reset_config()
{
    if (pros::competition::is_disabled())
    {
        IsCollectorOn = false;
        IsCollectorReverse = false;
        IsAutoShootEnabled = false;
        IsReady = false;
        IsAccelCompensationEnabled = true;

        movecnt = 0;
        memset((void *)&move_state, 0, sizeof(move_state[MAX_STEPS]));
        memset((void *)&move_start_time, 0, sizeof(move_start_time[MAX_STEPS]));
    }
    else if (pros::competition::is_autonomous())
    {
#if 0
	    motor_pid_full_s_t pid = pros::c::motor_get_pos_pid(1);
	    pid.kp = 0x10;
	    pid.ki = 0x0;
	    pid.kd = 0x0;
	    pros::c::motor_set_pos_pid_full(15, pid);
	    pros::c::motor_set_pos_pid_full(20, pid);
	    pros::c::motor_set_pos_pid_full(1, pid);
	    pros::c::motor_set_pos_pid_full(18, pid);
#endif
        IsCollectorOn = false;
        IsCollectorReverse = false;
        IsAutoShootEnabled = true;
        IsReady = false;
        IsAccelCompensationEnabled = false;
    }
    else
    {
        chassis.TurningCoefficient = 0.7;
        chassis.ForwardCoefficient = 1.0;
        IsCollectorOn = false;
        IsCollectorReverse = false;
        IsAutoShootEnabled = true;
        IsReady = false;
        IsAccelCompensationEnabled = true;
    }
}
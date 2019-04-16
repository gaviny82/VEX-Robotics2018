#include "robot.hpp"
#include "lib/auto_move.hpp"

Motor left_f_mtr(7, MOTOR_GEARSET_18, reverse);
Motor left_b_mtr(6, MOTOR_GEARSET_18);
Motor right_f_mtr(4, MOTOR_GEARSET_18);
Motor right_b_mtr(5, MOTOR_GEARSET_18,reverse);

Motor collector(13, MOTOR_GEARSET_36);
Motor shoot1(12, MOTOR_GEARSET_6);
Motor shoot2(11, MOTOR_GEARSET_6, reverse);
Motor arm(14, MOTOR_GEARSET_18);

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

ADIDigitalIn shoot_switch_a('A');
ADIDigitalIn shoot_switch_b('B');
ADIDigitalIn shoot_switch_c('C');

ADIDigitalIn arm_switch('H');

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

#include "lib/auto_move.hpp"
#include "robot.hpp"
#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

uint8_t move_state[64] = {};
uint32_t move_start_time[64] = {};
uint16_t movecnt;

pidctrl_t pid_left;
pidctrl_t pid_right;

void pid_init(pidctrl_t *pid, int target)
{
	pid->Kp = PID_KP;
	pid->Ki = PID_KI;
	pid->Kd = PID_KD;
	pid->nSetPos = target;
	pid->nActPos = 0;
	pid->nErr = 0;
	pid->nErr_last = 0;
	pid->nIntegral = 0;
	pid->nDiffer = 0;
	pid->nPowerOut = 0.0;
}

int pid_process(pidctrl_t *pid, int posAct)
{
	pid->nActPos = posAct;
	pid->nErr = pid->nSetPos - pid->nActPos;
	pid->nIntegral = pid->nErr_last + pid->nErr;
	pid->nDiffer = pid->nErr_last - pid->nErr;
	pid->nPowerOut = pid->Kp*pid->nErr + pid->Ki*pid->nIntegral + pid->Kd*pid->nDiffer;
	pid->nErr_last = pid->nErr;
  
	return (int)pid->nPowerOut;
}


void autonomous()
{
	memset((void *)&move_state, 0, sizeof(move_state[MAX_STEPS]));
	memset((void *)&move_start_time, 0, sizeof(move_start_time[MAX_STEPS]));

	while (true)
	{
		movecnt = 0;
		pros::lcd::print(0, "EncL: %f  EncR: %f", left_f_mtr.get_position(), right_f_mtr.get_position());

#include "autos/back_red.h"
	__end:;
		//lcd::print(1, "Shoot: DEG: %d, %s, Voltage: %d", deg, ShootSignal == SIG_STANDBY ? "Standby" : "Shoot", shoot_m);
		delay(20);
	}
}

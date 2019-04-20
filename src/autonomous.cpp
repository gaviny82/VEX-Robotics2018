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

uint8_t move_state[MAX_STEPS] = {};
uint32_t move_start_time[MAX_STEPS] = {};
uint32_t move_brake_time[MAX_STEPS] = {};
uint16_t movecnt;
int arm_m = 0;

pidctrl_t pid_left;
pidctrl_t pid_right;

void arm_move(int a){
	arm_m = a;
}

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
	pid->nErr = pid->nActPos - pid->nSetPos;
	pid->nIntegral = pid->nErr_last + pid->nErr;
	pid->nDiffer = pid->nErr_last - pid->nErr;
	pid->nPowerOut = pid->Kp*pid->nErr + pid->Ki*pid->nIntegral + pid->Kd*pid->nDiffer;
	pid->nErr_last = pid->nErr;

	return (int)pid->nPowerOut;
}


void autonomous()
{
	int shoot_m;
	memset((void *)&move_state, 0, sizeof(move_state[MAX_STEPS]));
	memset((void *)&move_start_time, 0, sizeof(move_start_time[MAX_STEPS]));
	arm.tare_position();
	arm.set_zero_position(arm.get_position());

	while (true)
	{
		movecnt = 0;
		pros::lcd::print(0, "EncL: %f  EncR: %f", left_f_mtr.get_position(), right_f_mtr.get_position());
		pros::lcd::print(5, "EncArm:%f", arm.get_position());
#include "autos/pid.h"
	__end:;

		pros::lcd::print(3,"Time: %d", move_start_time[movecnt] - move_start_time[0]);
	//auto shoot
			if (ShootSignal == SIG_SHOOT && IsReady)
			{
				shoot_m = 100;
				IsReady = false;
			}
			else if (shoot_switch_a.get_value() == HIGH || shoot_switch_b.get_value() == HIGH)
			{
				IsReady = true;
				shoot_m = VOLT_SHOOT_HOLD;
			}
			else
			{
				ShootSignal = SIG_STANDBY;
				IsReady = false;
				shoot_m = 100;
			}
			shoot1.move(shoot_m);
			shoot2.move(shoot_m);

			if(arm_m > 0 && arm_switch.get_value() == HIGH){
				arm.tare_position();
				arm.set_zero_position(arm.get_position());
				arm.move(0);
				arm_m = 0;
			}

			if(arm_m != 0){
				arm.move(arm_m);
			}
		delay(20);
	}
}

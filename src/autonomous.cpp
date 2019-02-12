#include "lib/pid_control.hpp"
#include "lib/auto_move.hpp"
#include "main.h"
#include "api.h"
#include "robot.hpp"
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

uint8_t move_state[64]  = {};
uint32_t move_start_time[64] = {};


void autonomous() {
#if 0
	motor_pid_full_s_t pid = pros::c::motor_get_pos_pid(1);
	pid.kp = 0x10;
	pid.ki = 0x0;
	pid.kd = 0x0;
	pros::c::motor_set_pos_pid_full(15,pid);
	pros::c::motor_set_pos_pid_full(20,pid);
	pros::c::motor_set_pos_pid_full(1,pid);
	pros::c::motor_set_pos_pid_full(18,pid);
#endif
	IsCollectorOn = false;
	IsCollectorReverse = false;

	IsAutoShootEnabled = true;

	IsReady = false;
	IsAccelCompensationEnabled = true;

	memset((void *)&move_state, 0, sizeof(move_state));
	memset((void *)&move_start_time, 0, sizeof(move_start_time));

	while (true) {
		uint16_t movecnt = 0;
		pros::lcd::print(0, "EncL: %f  EncR: %f", left_f_mtr.get_position(), right_f_mtr.get_position());
		_set_onetime_task(0, collector.move(127));
		_set_movement(127,3200,3200,3000);
		_set_movement(127,-3000,-3000,2500);
//		_set_onetime_task(2000, ShootSignal = SIG_SHOOT);

		_set_movement(127,-500,500,3000);

		__end:;
		int shoot_m;
		int deg = shoot_sensor.get_value();
			//auto shoot
		if (ShootSignal == SIG_SHOOT && IsReady) {
			shoot_m = 127;
			IsReady = false;
		}
		else if (deg < POSITION_READY && deg > 1000) {
			IsReady = true;
			shoot_m = 10;
		}
		else {
			ShootSignal = SIG_STANDBY;
			IsReady = false;
			shoot_m = 127;
		}
		shoot1.move(shoot_m);
		shoot2.move(shoot_m);
//		lcd::print(1, "Shoot: DEG: %d, %s, Voltage: %d", deg, ShootSignal == SIG_STANDBY ? "Standby" : "Shoot", shoot_m);
		delay(20);
	}
}

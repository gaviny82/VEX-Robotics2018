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

uint8_t move_state[64] = {};
uint32_t move_start_time[64] = {};
uint16_t movecnt;


void autonomous() {
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
	IsAccelCompensationEnabled = true;

	memset((void *)&move_state, 0, sizeof(move_state[MAX_STEPS]));
	memset((void *)&move_start_time, 0, sizeof(move_start_time[MAX_STEPS]));

	while (true) {
		movecnt = 0;
		pros::lcd::print(0, "EncL: %f  EncR: %f", left_f_mtr.get_position(), right_f_mtr.get_position());

#include "autos/front_blue.h"

		__end:;
			  int shoot_m;
			  int deg = shoot_sensor.get_value();
			  if (IsAutoShootEnabled) {
				  //auto shoot
				  if (ShootSignal == SIG_SHOOT && IsReady) {
					  shoot_m = 127;
					  IsReady = false;
				  }
				  else if (deg < POSITION_READY && deg > 1000) {
					  IsReady = true;
					  shoot_m = VOLT_SHOOT_HOLD;
				  }
				  else {
					  ShootSignal = SIG_STANDBY;
					  IsReady = false;
					  shoot_m = 127;
				  }
				  shoot1.move(shoot_m);
				  shoot2.move(shoot_m);
			  }
			  else {
				  //manual shoot
				  if (master.get_digital(DIGITAL_X)) {
					  shoot1.move(127);
					  shoot2.move(127);
				  }
				  else {
					  shoot1.move(0);
					  shoot2.move(0);
				  }
			  }
			  //		lcd::print(1, "Shoot: DEG: %d, %s, Voltage: %d", deg, ShootSignal == SIG_STANDBY ? "Standby" : "Shoot", shoot_m);
			  delay(20);
	}
}
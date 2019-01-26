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


void autonomous() {
	motor_pid_full_s_t pid = pros::c::motor_get_pos_pid(1);
	pid.kp = 0x10;
	pid.ki = 0x0;
	pid.kd = 0x0;
	pros::c::motor_set_pos_pid_full(15,pid);
	pros::c::motor_set_pos_pid_full(20,pid);
	pros::c::motor_set_pos_pid_full(1,pid);
	pros::c::motor_set_pos_pid_full(18,pid);
	while (true) {
		movecnt=0;
		pros::lcd::print(0, "EncL: %f  EncR: %f", left_f_mtr.get_position(), right_f_mtr.get_position());
		_set_movement(100,200,200,3000);


		  //pros::lcd::print(2,"State: %s", move_state[movecnt]);
		__end:;
		delay(20);
	}
}

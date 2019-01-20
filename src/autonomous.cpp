#include "api.h"
#include "lib/pid_control.hpp"
#include "lib/auto_move.hpp"
#include "main.h"
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
    chassis.SetMotorsRelativeL(2000, 127);
        chassis.SetMotorsRelativeR(2000, 127);
    while(true) {
      pros::lcd::print(0,"EncL: %f  EncR: %f", left_f_mtr.get_position(), right_f_mtr.get_position());
 //_set_movement(100,2,2,3000);
//__end:
delay(20);
    }
}

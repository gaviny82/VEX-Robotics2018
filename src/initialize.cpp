#include "main.h"
#include "lib/event_handler.hpp"
#include "lib/button.hpp"
#include "lib/chassis.hpp"
#include "pros/rtos.hpp"
#include "robot.hpp"
#include "lib/auto_move.hpp"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	IsCollectorOn = false;
	IsCollectorReverse = false;

	IsAutoShootEnabled = true;

	IsReady = false;
	IsAccelCompensationEnabled = true;

	memset((void *)&move_state, 0, sizeof(move_state[MAX_STEPS]));
	memset((void *)&move_start_time, 0, sizeof(move_start_time[MAX_STEPS]));

}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/** @file config.c
 * @brief File for configuration
 *
 * This file should contain the global variables and configuration to the robot
 */
 #include "config.h"

//motion config
bool clawAsForward = false;
float turningSpeed = TURNING_NORMAL;
float verticalSpeed =  SPEED_NORMAL;

//ball collector states
char collectorState = COLLECTOR_STOP;


void resetConfig() {
	clawAsForward = false;
	collectorState = COLLECTOR_STOP;
	turningSpeed = TURNING_NORMAL;
	ls_enabled = true;
}

/** @file motion.c
 * @brief File for motion of the robot
 *
 * This file should contain motor control functions and selection of motor speed levels.
 */
#include "motion.h"
#include "config.h"

signed char limit127(int value){
	if (value < -127) {
		return -127;
	} else if (value > 127) {
		return 127;
	} else {
		return (signed char)value;
	}
}

void setMotorsL(signed char speed) {
	motorSet(MOTOR_L_FRONT, speed);
	motorSet(MOTOR_L_BACK, speed);
	motorSet(MOTOR_2L, speed);
}

void setMotorsR(signed char speed) {
	motorSet(MOTOR_R_FRONT, speed);
	motorSet(MOTOR_R_BACK, -speed);
	motorSet(MOTOR_2R, -speed);
}

void setMovement(signed char vertical, signed char turning) {
	int realVertical = vertical * (clawAsForward ? 1 : -1);
	int left, right;
	if(clawAsForward){
		left = 0.7 * realVertical + 0.5 * turning;
		right = 0.7 * realVertical - 0.5 * turning;
	}else{
		left = verticalSpeed * realVertical + turningSpeed * turning;
		right = verticalSpeed * realVertical - turningSpeed * turning;
	}
	setMotorsL(limit127(left));
	setMotorsR(limit127(right));
}

void manualmotion_loop(){
		int vertical = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_VERTICAL_CH);
		int angular = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_ANGULAR_CH);

		if (abs(vertical) <= JOYSTICK_THROT_START) {
			vertical = 0;
		}
		if (abs(angular) <= JOYSTICK_THROT_START) {
			angular = 0;
		}
		motorSet(MOTOR_COLLECTOR, collectorState);
		setMovement(vertical, angular);
}

void callback_reverse() {
	clawAsForward = !clawAsForward;
}

void callback_switchBallCollector() {
	if (collectorState != COLLECTOR_STOP) {
		collectorState = COLLECTOR_STOP;
	}
	else {
		collectorState = COLLECTOR_ON;
	}
}

void callback_highSpeed() {
	DBG_PRINT("Switch to %fx speed", TURNING_LOW);
	turningSpeed = TURNING_NORMAL;
}

void callback_normalSpeed() {
	DBG_PRINT("Switch to %dx speed", TURNING_NORMAL);
	turningSpeed = TURNING_LOW;
}

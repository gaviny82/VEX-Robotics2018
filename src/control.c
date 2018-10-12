#include "control.h"
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

extern void setMotorsL(signed char value) {
	int speed = value * motorSpeed;
	DBG_PRINT("setMotorsL: %d \n", speed);
	motorSet(MOTOR_L_FRONT, speed);
	motorSet(MOTOR_L_BACK, speed);
	motorSet(MOTOR_2L, speed);
}
extern void setMotorsR(signed char value) {
	int speed = value * motorSpeed;
	DBG_PRINT("setMotorsR: %d \n", speed);
	motorSet(MOTOR_R_FRONT, speed);
	motorSet(MOTOR_R_BACK, -speed);
	motorSet(MOTOR_2R, -speed); /* Reverse it here, ugly workaroud. */
}

extern void setMovement(signed char vertical, signed char angular) {
	int realVertical = vertical * (isReversed ? -1 : 1);
	int left = 0.9 * realVertical + 0.8*angular;
	int	right = 0.9 * realVertical - 0.8*angular;
	setMotorsL(limit127(left));
	setMotorsR(limit127(right));
}

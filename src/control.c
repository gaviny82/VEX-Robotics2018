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

extern void setMotorsL(signed char speed) {
	DBG_PRINT("setMotorsL: %d \n", speed);
	motorSet(MOTOR_L_FRONT, speed);
	motorSet(MOTOR_L_BACK, speed);
	motorSet(MOTOR_2L, speed);
}
extern void setMotorsR(signed char speed) {
	DBG_PRINT("setMotorsR: %d \n", speed);
	motorSet(MOTOR_R_FRONT, speed);
	motorSet(MOTOR_R_BACK, -speed);
	motorSet(MOTOR_2R, -speed);
}

extern void setMovement(signed char vertical, signed char turning) {
	int realVertical = vertical * (clawAsForward ? 1 : -1);
	int left, right;
	if(clawAsForward){
		left = 0.7 * realVertical + 0.6 * turning;
		right = 0.7 * realVertical - 0.6 * turning;
	}else{
		left = verticalSpeed * realVertical + turningSpeed * turning;
		right = verticalSpeed * realVertical - turningSpeed * turning;
	}
	setMotorsL(limit127(left));
	setMotorsR(limit127(right));
}

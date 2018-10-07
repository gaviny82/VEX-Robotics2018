#include "control.h"
#include "config.h"

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
	motorSet(MOTOR_2R, -speed); /* Reverse it here, ugly workaroud. */
}

extern void setMovement(signed char vertical, signed char angular) {
	int left = vertical * direction + angular,
		right = vertical * direction - angular;
	setMotorsL((char)(left >= 127 ? 127 : left));
	setMotorsR((char)(right >= 127 ? 127 : right));
}

#include "main.h"
#include "control.h"
#include "config.h"


extern void setMotorsL(signed char speed) {
	DBG_PRINT("setMotorsL: %d \n", speed);
	motorSet(MOTOR_L1, speed);
	motorSet(MOTOR_2L, speed);
}
extern void setMotorsR(signed char speed) {
	DBG_PRINT("setMotorsR: %d \n", speed);
	motorSet(MOTOR_R1, speed);
	motorSet(MOTOR_2R, -speed);
}

extern void setMovement(signed char vertical, signed char angular) {
	int left = vertical * reverseDirection + angular,
		right = vertical * reverseDirection - angular;
	setMotorsL((char)(left >= 127 ? 127 : left));
	setMotorsR((char)(right >= 127 ? 127 : right));
}
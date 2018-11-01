#include "control.h"
#include "config.h"
#include "API.h"

//shoot control

int shoot_sig = 0;
int shoot_stage = 0;

void callback_shoot() {
	DBG_PRINT("Shoot Callback Triggered\n");
	if (shoot_stage == STAGE_ZERO_POSITION)
		shoot_sig = SIG_SHOOT;
}

void autoshoot_loop() {
	int deg = analogRead(POTENTIALMETER_SHOOT);
	if (shoot_sig == SIG_SHOOT && shoot_stage == STAGE_ZERO_POSITION) {
		DBG_PRINT("shoot_stage: STAGE_FINALL_KICK\n");
		shoot_sig = SIG_STDBY;
		SET_SHOOT_MOTORS(MOTOR_SHOOT_CIRCUIT);
		shoot_stage = STAGE_FINALL_KICK;
		return;
	}

	if (shoot_stage == STAGE_FINALL_KICK && deg > 1600) return;

	if (deg > POSITION_READY) {
		shoot_stage = STAGE_ZERO_POSITION;
		SET_SHOOT_MOTORS(MOTOR_FIX_CIRCUIT);
	}
	else {
		shoot_stage = STAGE_PULL;
		SET_SHOOT_MOTORS(MOTOR_SHOOT_CIRCUIT);
	}
}

//claw control
void claw_control_loop() {
	int deg = analogRead(1);
	DBG_PRINT("PS_ARMdeg: %d \n", deg);

#if 1
		if(joystickGetDigital(MASTER_JOYSTICK, 6, JOY_UP)){
			motorSet(MOTOR_CLAW, 127);
		} else if(joystickGetDigital(MASTER_JOYSTICK, 6, JOY_DOWN)){
			motorSet(MOTOR_CLAW, -127);
		} else {
			motorSet(MOTOR_CLAW, 0);
		}
#endif

}

//collector control
void bc_joy_loop() {
	//switch ball collector
	if (collectorState != COLLECTOR_STOP) {
		if (joystickGetDigital(MASTER_JOYSTICK, 5, JOY_DOWN)) {
			collectorState = COLLECTOR_REVERSE;
		}
		else {
			collectorState = COLLECTOR_ON;
		}
	}//TODO:
}

void callback_switchBallCollector() {
	if (collectorState != COLLECTOR_STOP) {
		collectorState = COLLECTOR_STOP;
	}
	else {
		collectorState = COLLECTOR_ON;
	}
}

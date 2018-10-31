#include "control.h"
#include "config.h"
#include "API.h"

//shoot control
#define SIG_SHOOT 1
#define SIG_ONGOING -1
#define SIG_STDBY 0

#define STAGE_ZERO_POSITION 0
#define STAGE_PULL 1
#define STAGE_FINALL_KICK 2

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

	if (deg > POSITION_READY - 20) {
		shoot_stage = STAGE_ZERO_POSITION;
		SET_SHOOT_MOTORS(MOTOR_FIX_CIRCUIT);
	}
	else {
		shoot_stage = STAGE_PULL;
		SET_SHOOT_MOTORS(MOTOR_SHOOT_CIRCUIT);
	}
}

//claw control
void claw_control() {
	bool clicked = joystickGetDigital(MASTER_JOYSTICK, 6, JOY_UP) ||
		joystickGetDigital(MASTER_JOYSTICK, 6, JOY_DOWN);
	int deg = analogRead(POTENTIALMETER_CLAW);
	if (claw_position == FREE_POSITION) {
		goto opcontrol;
	}
	if (claw_position == LOW_POSITION) {
		if (!clicked && deg >= DEG_LOW) {
			motorSet(MOTOR_CLAW, -80);
		}
		if (deg > +DEG_KICK_LOW) {
			motorSet(MOTOR_CLAW, -30);
			return;
		}
		if (claw_position == HOLD_POSITION) {
			if (!clicked) {
				if (deg <= (DEG_HOLD + 80)) {
					motorSet(MOTOR_CLAW, 80);
					return;
				}
				else if (deg >= (DEG_HOLD - 80)) {
					motorSet(MOTOR_CLAW, -30);
					return;
				}
				else {
					motorSet(MOTOR_CLAW, 15);
					return;
				}
			}
		}
	}
opcontrol:
	if (joystickGetDigital(MASTER_JOYSTICK, 6, JOY_UP)) {
		motorSet(MOTOR_CLAW, 127);
	}
	else if (joystickGetDigital(MASTER_JOYSTICK, 6, JOY_DOWN)) {
		motorSet(MOTOR_CLAW, -80);
	}
	else {
		motorSet(MOTOR_CLAW, 0);
	}
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
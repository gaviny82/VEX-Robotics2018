#include "control.h"
#include "config.h"
#include "API.h"

//shoot control

int shoot_sig = 0;
int shoot_stage = 0;
bool shoot_switch = 1;

void detect_shoot_switch_loop(){
	if(joystickGetDigital(MASTER_JOYSTICK, 8, JOY_LEFT)){
		shoot_switch = false;
	} else {
		shoot_switch = true;
	}
}

void callback_shoot() {
	DBG_PRINT("Shoot Callback Triggered\n");
	if (shoot_stage == STAGE_ZERO_POSITION)
		shoot_sig = SIG_SHOOT;
}

void autoshoot_loop() {

	if(shoot_switch){
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
} else {
	SET_SHOOT_MOTORS(0);
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

bool claw_state = 0;
#define CLAW_LIMITED 1
#define CLAW_FREE 0
bool claw_key_pressed = 0;
bool push_back = 0;

void callback_clawstate(){
	claw_state =! claw_state;
	claw_key_pressed = 0;
}

void callback_claw_key_pressed(){
	claw_key_pressed = 1;
}

//claw control
void claw_control_loop() {
	int deg = analogRead(1);
	DBG_PRINT("PS_ARMdeg: %d \n", deg);

	if(claw_state == CLAW_FREE){
	if(joystickGetDigital(MASTER_JOYSTICK, 6, JOY_DOWN)){
		motorSet(MOTOR_CLAW, 127);
	} else if(joystickGetDigital(MASTER_JOYSTICK, 6, JOY_UP)){
	motorSet(MOTOR_CLAW, -127);
	} else {
		motorSet(MOTOR_CLAW, 0);
	}
} else {
	if (push_back && deg > 3600) {
		return;
	} else {
		push_back = 0;
	}
	if(claw_key_pressed && deg >= 4040) {
		claw_key_pressed = 0;
		motorSet(MOTOR_CLAW, 90);
		push_back = 1;
	} else if (claw_key_pressed){
		motorSet(MOTOR_CLAW, -127);
	} else {
		motorSet(MOTOR_CLAW, 0);
	}
}
}

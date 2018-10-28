#include "main.h"
#include "pid.h"
#include "config.h"
#include "API.h"
#include "shoot.h"

#define POSITION_NULL 1550
#define POSITION_READY 2000

#define MOTOR_FIX_CIRCUIT 30
#define MOTOR_SHOOT_CIRCUIT 127

#define SIG_SHOOT 1
#define SIG_ONGOING -1
#define SIG_STDBY 0

int shoot_sig = 0;
int shoot_stage = 0;

#define STAGE_ZERO_POSITION 0
#define STAGE_PULL 1
#define STAGE_FINALL_KICK 2

void callback_autoshoot() {
	DBG_PRINT("Shoot Callback Triggered\n");
	if (shoot_stage == STAGE_ZERO_POSITION)
		shoot_sig = SIG_SHOOT;
}

void autoshoot_loop() {
		int deg = analogRead(POTENTIALMETER_SHOOT);
		if(shoot_sig == SIG_SHOOT && shoot_stage == STAGE_ZERO_POSITION){
		DBG_PRINT("shoot_stage: STAGE_FINALL_KICK\n");
			shoot_sig = SIG_STDBY;
			SET_SHOOT_MOTORS(MOTOR_SHOOT_CIRCUIT);
			shoot_stage = STAGE_FINALL_KICK;
			return;
		}

		if(shoot_stage == STAGE_FINALL_KICK && deg > 1600)
			return;

		if (deg > POSITION_READY - 20) {
			shoot_stage = STAGE_ZERO_POSITION;
			SET_SHOOT_MOTORS(MOTOR_FIX_CIRCUIT);
		}else{
			shoot_stage = STAGE_PULL;
			SET_SHOOT_MOTORS(MOTOR_SHOOT_CIRCUIT);
		}

	}

#include "main.h"
#include "pid.h"
#include "config.h"
#include "API.h"
#include "shoot.h"

#define POSITION_NULL 1550
#define POSITION_READY 2100

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

void shoot_out() {
	printf("call shoot!\n");
	if (shoot_stage == STAGE_ZERO_POSITION)
		shoot_sig = SIG_SHOOT;
}

void autoshoot_loop() {
		int deg = analogRead(POTENTIALMETER_SHOOT);
		if(shoot_sig == SIG_SHOOT && shoot_stage == STAGE_ZERO_POSITION){
		printf("shoot!!!!!\n");
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


		//
		//if (shoot_stage == STAGE_ZERO_POSITION && deg <= DEG_BACK) {
		//	/* Enter STAGE_PULL if in BACK_POSITION */
		//	shoot_stage = STAGE_PULL;
		//}

		//if (shoot_stage == STAGE_PULL) {
		//	shoot_sig = SIG_ONGOING;
		//	if (deg <= DEG_ZEROPOSITION) {
		//		SET_SHOOT_MOTORS(MOTOR_SHOOT_CIRCUIT);
		//		deg = analogRead(POTENTIALMETER_SHOOT);
		//		return;
		//	}
		//	shoot_stage = STAGE_ZERO_POSITION;
		//	shoot_sig = SIG_STDBY;
		//	SET_SHOOT_MOTORS(MOTOR_FIX_CIRCUIT); /* Fix circuit to keep on zero position*/
		//	return;
		//}

		//if (shoot_sig == SIG_SHOOT && shoot_stage == STAGE_ZERO_POSITION) {
		//	shoot_sig = SIG_ONGOING;/* Set signal into ongoing */
		//	shoot_stage = STAGE_FINALL_KICK; /* Time to do FINAL_KICK to shoot the ball out*/
		//	if (deg >= DEG_BACK + 20) {
		//		SET_SHOOT_MOTORS(MOTOR_SHOOT_CIRCUIT);
		//		return;
		//	}
		//	SET_SHOOT_MOTORS(0);
		//	shoot_stage = STAGE_PULL;
		//	return;
		//}

		//if (shoot_sig == STAGE_FINALL_KICK) {
		//	if (deg >= DEG_BACK) {
		//		SET_SHOOT_MOTORS(MOTOR_SHOOT_CIRCUIT);
		//		return;
		//	}
		//	SET_SHOOT_MOTORS(0);
		//	shoot_stage = STAGE_PULL;
		//	return;
		//}

	}

#ifndef CONTROL_H_
#define CONTROL_H_

//shoot conrol
#define POSITION_NULL 1550
#define POSITION_READY 2000

#define MOTOR_FIX_CIRCUIT 30
#define MOTOR_SHOOT_CIRCUIT 127

#define SIG_SHOOT 1
#define SIG_ONGOING -1
#define SIG_STDBY 0

#define STAGE_ZERO_POSITION 0
#define STAGE_PULL 1
#define STAGE_FINALL_KICK 2

extern int shoot_sig;
extern int shoot_stage;

extern void callback_shoot();

extern void autoshoot_loop();

#define SET_SHOOT_MOTORS(x) do { motorSet(MOTOR_SHOOT1, x); motorSet(MOTOR_SHOOT2, x); } while (false)

//claw control
extern void claw_control();

#define DEG_LOW 5200
#define DEG_KICK_LOW 5200
#define DEG_HOLD 4095

//collector control
extern void bc_joy_loop();

/*
* turn on/off the ball collector
*/
extern void callback_switchBallCollector();

extern void claw_control_loop();

#endif

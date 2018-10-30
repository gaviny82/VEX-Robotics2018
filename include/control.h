#ifndef CONTROL_H_
#define CONTROL_H_

//shoot conrol
extern void callback_autoshoot();

extern void autoshoot_loop();

#define SET_SHOOT_MOTORS(x) do { motorSet(MOTOR_SHOOT1, x); motorSet(MOTOR_SHOOT2, x); } while (false)

//claw control
extern void claw_control();

#define DEG_LOW 5200
#define DEG_KICK_LOW 5200
#define DEG_HOLD 4095

//collector control
extern void bc_joy_loop();

#endif
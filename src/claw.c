#include "API.h"
#include "config.h"
#include "claw.h"

void claw_control() {
  bool clicked = joystickGetDigital(MASTER_JOYSTICK, 6, JOY_UP) || \
  joystickGetDigital(MASTER_JOYSTICK, 6, JOY_DOWN);
  int deg = analogRead(POTENTIALMETER_CLAW);
  if(claw_position == FREE_POSITION){
    goto opcontrol;
  }
  if(claw_position == LOW_POSITION){
    if(!clicked && deg >= DEG_LOW){
      motorSet(MOTOR_CLAW, -80);
    }
    if(deg >+ DEG_KICK_LOW){
      motorSet(MOTOR_CLAW, -30);
      return;
    }
    if(claw_position == HOLD_POSITION){
      if(!clicked){
        if(deg <= (DEG_HOLD + 80)){
          motorSet(MOTOR_CLAW, 80);
          return;
        } else if(deg >= (DEG_HOLD - 80)){
          motorSet(MOTOR_CLAW, -30);
          return;
        } else {
          motorSet(MOTOR_CLAW, 15);
          return;
        }
      }
    }
  }
  opcontrol:
  if (joystickGetDigital(MASTER_JOYSTICK, 6, JOY_UP)){
    motorSet(MOTOR_CLAW, 127);
  } else if (joystickGetDigital(MASTER_JOYSTICK, 6, JOY_DOWN)){
    motorSet(MOTOR_CLAW, -80);
  } else {
    motorSet(MOTOR_CLAW, 0);
  }
}

#include "main.h"
#include "control.h"

extern void setMotorsLR(int left, int right) {
  /* motors on left side should be reversed */
  motorSet(MOTOR_R_M, right);
  motorSet(MOTOR_R_2, right);
  motorSet(MOTOR_L_M, -left);
  motorSet(MOTOR_L_2, -left);
}

extern void setMovement(char vertical, char angular) {
 if(vertical!=0)angular/=2;
 if(angular!=0)vertical/=2;
 setMotorsLR(vertical/1.4 + angular/1.4, vertical/1.4 - angular/1.4);
}


extern void shoot() {
  bool shoot = joystickGetDigital(MASTER_JOYSTICK,8 , JOY_UP);
  if (shoot) {
    motorSet(3, 127);
  } else {
    motorSet(3, -2);
  }
}

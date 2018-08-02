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
 if(vertical!=0)angular/=1.4;
 if(angular!=0)vertical/=1.4;
 setMotorsLR(vertical + angular, vertical - angular);
}


extern void shoot() {
  bool shoot = joystickGetDigital(MASTER_JOYSTICK,8 , JOY_UP);
  if (shoot) {
    motorSet(MOTOR_SHOOT, 127);
  } else {
    motorSet(MOTOR_SHOOT, 2);
  }
}

bool pickballPrevClicked = false;
bool pickballEnabled = false;

extern void pickballtask() {
  bool clicked;
  clicked = joystickGetDigital(MASTER_JOYSTICK, 8, JOY_LEFT);
  if (!clicked) {
    pickballPrevClicked = false;
  }

  if (clicked && pickballPrevClicked) {
    pickballEnabled = !pickballEnabled;
    pickballPrevClicked = false;
  } else {
    pickballPrevClicked = true;
  }

if (pickballEnabled) {
  motorSet(MOTOR_PICKBALL, 127);
} else {
  motorSet(MOTOR_PICKBALL, 0);
}

return;

}

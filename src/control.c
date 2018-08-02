#include "main.h"
#include "control.h"


extern void setMotorsL(signed char speed){
  //printf("Motor L: %d \n", speed);
  motorSet(MOTOR_L_M, -speed);
  motorSet(MOTOR_L_2, -speed);
}
extern void setMotorsR(signed char speed){
  //printf("Motor R: %d \n", speed);
  motorSet(MOTOR_R_M, speed);
  motorSet(MOTOR_R_2, speed);
}

extern void setMovement(signed char vertical, signed char angular) {
 int left = vertical - angular, right=vertical + angular;
 setMotorsL((char)(left>=127?127:left));
 setMotorsR((char)(right>=127?127:right));
}

extern void shoot() {
  bool shoot = joystickGetDigital(MASTER_JOYSTICK,7 , JOY_UP);
  motorSet(MOTOR_SHOOT, shoot?127:2);
}

bool isKeyDown=false, isCollecting=false;
void clicked(){
  isCollecting=!isCollecting;
  if(isCollecting){
    motorSet(MOTOR_BALL_COLLECTOR, 127);
  }else{
    motorSet(MOTOR_BALL_COLLECTOR, 0);
  }
}
extern void runBallCollector() {
  bool currentKeyState=joystickGetDigital(MASTER_JOYSTICK, 8, JOY_LEFT);
  if (!isKeyDown&&currentKeyState) {
    clicked();
  }
  isKeyDown=currentKeyState;
}

bool reverseBallCollector(){
  if(joystickGetDigital(MASTER_JOYSTICK, 8, JOY_RIGHT)){
    motorSet(MOTOR_BALL_COLLECTOR, -127);
    return false;
  }
  motorSet(MOTOR_BALL_COLLECTOR,0);
  return true;
}

void rise(){
  if(joystickGetDigital(MASTER_JOYSTICK,6, JOY_UP)){
    motorSet(MOTOR_LIFT_LEFT,127);
    motorSet(MOTOR_LIFT_RIGHT,127);
  }else if(joystickGetDigital(MASTER_JOYSTICK,6,JOY_DOWN)){
    motorSet(MOTOR_LIFT_LEFT,-127);
    motorSet(MOTOR_LIFT_RIGHT,-127);
  }else{
    motorSet(MOTOR_LIFT_LEFT,0);
    motorSet(MOTOR_LIFT_RIGHT,0);
  }

}

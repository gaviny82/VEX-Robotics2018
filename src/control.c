#include "main.h"
#include "control.h"
#include "iodefinitions.h"


extern void setMotorsL(signed char speed){
  //printf("Motor L: %d \n", speed);
  motorSet(MOTOR_L1, speed);
  motorSet(MOTOR_2L, speed);
}
extern void setMotorsR(signed char speed){
  //printf("Motor R: %d \n", speed);
  motorSet(MOTOR_R1, speed);
  motorSet(MOTOR_2R, -speed);
}

extern void setMovement(signed char vertical, signed char angular) {
 int left = vertical*reverseDirection + angular, right = vertical*reverseDirection - angular;
 setMotorsL((char)(left>=127?127:left));
 setMotorsR((char)(right>=127?127:right));
}

extern void shoot() {
  bool shoot = joystickGetDigital(MASTER_JOYSTICK,7 , JOY_UP);
  motorSet(MOTOR_SHOOT, shoot?127:2);
}

bool isKeyDown=false, isCollecting=false;

extern void runBallCollector() {
  bool currentKeyState=joystickGetDigital(MASTER_JOYSTICK, 8, JOY_LEFT);
  if (!isKeyDown&&currentKeyState) {
    printf("%d%d%d\n",isKeyDown,currentKeyState,isCollecting);
    isCollecting=!isCollecting;
    if(isCollecting){
      motorSet(MOTOR_BALL_COLLECTOR, 127);
    }else{
      motorSet(MOTOR_BALL_COLLECTOR, 0);
    }
  }
  isKeyDown=currentKeyState;
}

extern bool reverseBallCollector(){
  if(joystickGetDigital(MASTER_JOYSTICK, 8, JOY_RIGHT)){
    motorSet(MOTOR_BALL_COLLECTOR, -127);
    return false;
  }
  if(!isCollecting){
    motorSet(MOTOR_BALL_COLLECTOR,0);
  }
  else{
  motorSet(MOTOR_BALL_COLLECTOR,127);
  }
  return true;
}
/*
extern void rise(){
  if(joystickGetDigital(MASTER_JOYSTICK,6, JOY_UP)){
    motorSet(MOTOR_LIFT_LEFT,127);
    motorSet(MOTOR_LIFT_RIGHT,127);
  }else if(joystickGetDigital(MASTER_JOYSTICK,6,JOY_DOWN)){
    motorSet(MOTOR_LIFT_LEFT,-127);
    motorSet(MOTOR_LIFT_RIGHT,-127);
  }else{
    motorSet(MOTOR_LIFT_LEFT,10);
    motorSet(MOTOR_LIFT_RIGHT,10);
  }

}
*/

extern void claw(){
  if(joystickGetDigital(MASTER_JOYSTICK, 5, JOY_UP)){
    motorSet(MOTOR_CLAW1, 127);
      motorSet(MOTOR_CLAW2, 127);
  }else if(joystickGetDigital(MASTER_JOYSTICK, 5, JOY_DOWN)){
    motorSet(MOTOR_CLAW1, -127);
      motorSet(MOTOR_CLAW2, -127);
  }else{
    motorSet(MOTOR_CLAW1, 0);
      motorSet(MOTOR_CLAW2, 0);
  }
}

extern void kickloop() {
  /*if (joystickGetDigital(MASTER_JOYSTICK, 5, JOY_DOWN)) {
    motorSet(MOTOR_CLAW, -127);
  } else if (!digitalRead(DIGITAL_LIMIT_SWITCH_PIN)) {
    motorSet(MOTOR_CLAW, -10);
  } else if (joystickGetDigital(MASTER_JOYSTICK, 5, JOY_UP)) {
    motorSet(MOTOR_CLAW, 127);
  } else {
    motorSet(MOTOR_CLAW, -5);
  }*/
}
/*
extern void clawRotate(){
  if(joystickGetDigital(MASTER_JOYSTICK, 7, JOY_LEFT)){
    motorSet(MOTOR_CLAW_ROTATE, 127);
  }else if(joystickGetDigital(MASTER_JOYSTICK,7,JOY_RIGHT)){
    motorSet(MOTOR_CLAW_ROTATE,-127);
  }else{
    motorSet(MOTOR_CLAW_ROTATE,0);
  }

}
*/
bool isKeyDown2;
extern void reverse(){
  bool currentKeyState=joystickGetDigital(MASTER_JOYSTICK, 7, JOY_DOWN);
  if (!isKeyDown2&&currentKeyState) {
    reverseDirection = -reverseDirection;
  }
  isKeyDown2=currentKeyState;
}

#include "API.h"
#include "config.h"

void bc_joy_loop(){
//switch ball collector
if (collectorState != COLLECTOR_STOP) {
  if (joystickGetDigital(MASTER_JOYSTICK, 5, JOY_DOWN)) {
    collectorState = COLLECTOR_REVERSE;
  } else {
    collectorState = COLLECTOR_ON;
  }
}
}

void bc_setmotors_loop(){
  motorSet(MOTOR_COLLECTOR, collectorState);
}

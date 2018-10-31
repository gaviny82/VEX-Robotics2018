#ifndef TASKS_H_
#define TASKS_H

#include "API.h"

//autonomous
extern TaskHandle leftPIDTask;
extern TaskHandle rightPIDTask;

extern void startLeftPID(PIDCtrl *pid);

extern void stopLeftPID();

extern void startRightPID(PIDCtrl *pid);

extern void stopRightPID();

#endif
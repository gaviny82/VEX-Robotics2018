#ifndef SHOOT_H_
#define SHOOT_H

#include "main.h"

extern TaskHandle taskH_shoot;
extern bool autoShoot;

extern void shoot_task();

extern void callback_shoot();

extern void callback_switchAutoShoot();

#endif

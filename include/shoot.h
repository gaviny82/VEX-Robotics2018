#ifndef SHOOT_H_
#define SHOOT_H

#include "main.h"

extern TaskHandle taskH_shoot;
extern bool autoShoot;

/*
* loop of shoot task
*/
extern void shoot_task();

/*
* start the shoot task
*/
extern void callback_shoot();

/*
* switch on/off auto shoot
* debug use only
*/
extern void callback_switchAutoShoot();

#endif

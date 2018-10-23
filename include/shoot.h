#ifndef SHOOT_H_
#define SHOOT_H

#include "main.h"

extern TaskHandle taskH_shoot;
extern bool autoShoot;

<<<<<<< HEAD
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
=======
extern void shoot_task();

extern void callback_shoot();

>>>>>>> 271a7dd5ba928b240096753c49116678a75ba644
extern void callback_switchAutoShoot();

#endif

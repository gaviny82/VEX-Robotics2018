#ifndef OPCONTROL_H_
#define OPCONTROL_H_

#include "API.h"
#include "iodefinitions.h"
Encoder leftEncoder;
Encoder rightEncoder;

/* Put configs here */
#define GLOBAL_DEBUG

/*
* Set the motor speed values for left/Right side wheels
*
* @param left side
*
*/
extern void setMotorsL(signed char speed);
extern void setMotorsR(signed char speed);

/*
* Set the relative movement speed for directions
*
* @param Vertical speed
*
* @param Angular speed
*
*/
extern void setMovement(signed char vertical, signed char angular);

/*
* detect shoot key, should be execuated in every loops
*
*/
extern void shoot();
extern void kickloop();

/*
* task to enable and disenable pickball motor, please delay between execuate
*
*/

extern void runBallCollector();

extern bool reverseBallCollector();

extern void claw();

extern void reverse();


#ifdef GLOBAL_DEBUG
#define DBG_PRINT(...) do{ printf(  __VA_ARGS__ ); } while( false )
#else
#define DBG_PRINT(...) do{ } while ( false )
#endif

#endif
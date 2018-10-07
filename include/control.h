#ifndef OPCONTROL_H_
#define OPCONTROL_H_

#include "API.h"
#include "config.h"

/*
* Set the speed of motors for left/right side wheels
*
* @param Speed of motors on left/right side
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


#ifdef GLOBAL_DEBUG
#define DBG_PRINT(...) do{ fprintf(uart1,  __VA_ARGS__ ); } while( false )
#else
#define DBG_PRINT(...) do{ } while ( false )
#endif

#define SET_SHOOT_MOTORS(...) do { motorSet(MOTOR_SHOOT1, __VA_ARGS__); motorSet(MOTOR_SHOOT2, __VA_ARGS__); } while (false)

#endif

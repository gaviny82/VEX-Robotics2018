/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "opcontrol.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

 void setMotorsLR(int left, int right) {
   /* motors on left side should be reversed */
	 motorSet(MOTOR_R_M, right);
	 motorSet(MOTOR_R_2, right);
	 motorSet(MOTOR_L_M, -left);
	 motorSet(MOTOR_L_2, -left);
 }

 void setMovement(char vertical, char angular) {
 	if(vertical!=0)angular/=2;
 	if(angular!=0)vertical/=2;
 	setMotorsLR(vertical/1.4 + angular/1.4, vertical/1.4 - angular/1.4);
 }

 void shoot() {
	 bool shoot = joystickGetDigital(MASTER_JOYSTICK,8 , JOY_UP);
	 if (shoot) {
		 motorSet(3, 127);
	 } else {
		 motorSet(3, -2);
	 }
 }


void operatorControl() {
  printf("Hello World!\n");
	int vertical, angular;
	while (1) {
		vertical = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_VERTICAL_CH);
  	angular = joystickGetAnalog(MASTER_JOYSTICK, JOYSTICK_ANGULAR_CH);

    /* JOYSTICK_THROT to prevent fake values */
    if (vertical <= JOYSTICK_THROT_START && vertical >= -JOYSTICK_THROT_START) {
      vertical = 0;
    }
    if (angular <= JOYSTICK_THROT_START && angular >= -JOYSTICK_THROT_START) {
      angular = 0;
    }
    setMovement(vertical, angular);
    shoot();
	} /* end main loop */
}

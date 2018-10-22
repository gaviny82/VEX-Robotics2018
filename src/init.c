/** @file init.c
 * @brief File for initialization code
 *
 * This file should contain the user initialize() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "API.h"
#include "config.h"
#include "init.h"

void initializeIO() {
	/* Init Debug Uart*/
	usartInit(uart1, 9600, SERIAL_8N1);
	DBG_PRINT("INFO: initializeIO() Done \n");
}

void initialize() {
	leftEncoder = encoderInit(ENCODER_LEFT_TOP, ENCODER_LEFT_BOTTOM, false);
	rightEncoder = encoderInit(ENCODER_RIGHT_TOP, ENCODER_RIGHT_BOTTOM, false);
	pinMode(13, INPUT_ANALOG);
	pinMode(14, INPUT_ANALOG);
	resetConfig();
	DBG_PRINT("INFO: initialize() Done \n");
}

void resetConfig() {
	clawAsForward = false;
	collectorState = COLLECTOR_STOP;
	turningSpeed = TURNING_NORMAL;
	ls_enabled = true;
}

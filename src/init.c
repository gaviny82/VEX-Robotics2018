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
#include "control.h"
#include "iodefinitions.h"


void initializeIO() {
  pinMode(DIGITAL_LIMIT_SWITCH_PIN, INPUT);
  DBG_PRINT("INFO: initializeIO() Done \n");
}

void initialize() {
  leftEncoder = encoderInit(ENCODER_LEFT_TOP, ENCODER_LEFT_BOTTOM, false);
  rightEncoder = encoderInit(ENCODER_RIGHT_TOP, ENCODER_RIGHT_BOTTOM, false);
  DBG_PRINT("INFO: initialize() Done \n");
}

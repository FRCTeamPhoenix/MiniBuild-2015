/*
 * Constants.h
 *
 *  Created on: Nov 7, 2015
 *      Author: connortess
 */

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_
#include "WPILib.h"

struct Port{
// Channels for the wheels
   const static uint32_t frontLeftChannel   = 2;
   const static uint32_t rearLeftChannel    = 3;
   const static uint32_t frontRightChannel  = 1;
   const static uint32_t rearRightChannel   = 0;
   const static uint32_t joystickChannel     = 1;
};

enum buttonNames {
	buttonX = 1, buttonA = 2, buttonB = 3, buttonY = 4,
	buttonLB = 5, buttonRB = 6, triggerLT = 7, triggerRT = 8,
	buttonBack = 9, buttonStart = 10, joystickLeftButton = 11,
	joystickRightButton = 12
};


#endif /* SRC_CONSTANTS_H_ */

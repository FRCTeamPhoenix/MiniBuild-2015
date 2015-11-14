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

   const static uint32_t joystickChannel     = 0;
};


#endif /* SRC_CONSTANTS_H_ */

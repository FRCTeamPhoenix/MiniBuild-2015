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

   //encoder ports, not accurate
   static const uint32_t LeftRearDriveEncoderChannelA = 0;
   static const uint32_t LeftRearDriveEncoderChannelB = 1;
   static const uint32_t LeftFrontDriveEncoderChannelA = 2;
   static const uint32_t LeftFrontDriveEncoderChannelB = 3;
   static const uint32_t RightFrontDriveEncoderChannelA = 4;
   static const uint32_t RightFrontDriveEncoderChannelB = 5;
   static const uint32_t RightRearDriveEncoderChannelA = 6;
   static const uint32_t RightRearDriveEncoderChannelB = 7;


};


#endif /* SRC_CONSTANTS_H_ */

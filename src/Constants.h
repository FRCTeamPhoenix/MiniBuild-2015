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
    static const uint32_t frontLeftChannel   = 1;
    static const uint32_t rearLeftChannel    = 0;
    static const uint32_t frontRightChannel  = 2;
    static const uint32_t rearRightChannel   = 3;

   const static uint32_t joystickChannel     = 0;

   //encoder ports
   static const uint32_t LeftRearDriveEncoderChannelA = 0;
   static const uint32_t LeftRearDriveEncoderChannelB = 1;
   static const uint32_t LeftFrontDriveEncoderChannelA = 2;
   static const uint32_t LeftFrontDriveEncoderChannelB = 3;
   static const uint32_t RightFrontDriveEncoderChannelA = 4;
   static const uint32_t RightFrontDriveEncoderChannelB = 5;
   static const uint32_t RightRearDriveEncoderChannelA = 6;
   static const uint32_t RightRearDriveEncoderChannelB = 7;
   //gyro port
   static const int32_t gyroChannel = 0;



};
struct AutoConstants{
    //the number of ticks in one inch
    static constexpr double ticksPerInch=163.573f;
    //radians to degrees 180/pi
    static constexpr double radToDegree = 57.3248f;
    //move speed for auto, TODO tune this
    static constexpr double autoMoveSpeed =.2f;


};





#endif /* SRC_CONSTANTS_H_ */

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
   const static uint32_t gamepadChannel = 0; // placeholder value
};

struct TeleConstants{
   //Shooter Constants
   static constexpr float flywheelSpeed = 1;
   static constexpr float magazineMotorSpeed = 0.5;
   static const int magazineMotorTicksPerRotation = 512;
   static constexpr float motorRunTimeShooter = 3;

   //Loader Constants
   static constexpr float loaderMotorSpeed = 1;
   static constexpr float motorRunTimeLoader = 5;
};

enum buttonNames {
        buttonX = 1,
        buttonA = 2,
        buttonB = 3,
        buttonY = 4,
        buttonLB = 5,
        buttonRB = 6,
        triggerLT = 7,
        triggerRT = 8,
        buttonBack = 9,
        buttonStart = 10,
        joystickLeftButton = 11,
        joystickRightButton = 12
};

struct driveButtons{
   //Buttons for shooter
   const static int loadButton = buttonA;
   const static int fireButton = buttonB;
   //Buttons for loader
   const static int runLoaderMotor = buttonX;
   const static int stopLoaderMotor = buttonY;

};




#endif /* SRC_CONSTANTS_H_ */

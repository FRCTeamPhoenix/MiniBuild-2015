/*
 * DriveTrain.cpp
 *
 *  Created on: Nov 7, 2015
 *      Author: connortess
 */
#include "WPILib.h"
#include "DriveTrain.h"
#include "Joystick.h"
#include "Constants.h"

DriveTrain::DriveTrain() :
   RobotDrive(Port::frontLeftChannel, Port::rearLeftChannel, Port::frontRightChannel, Port::rearRightChannel) {
}


DriveTrain::~DriveTrain() {
   // TODO Auto-generated destructor stub
   //~RobotDrive();
}


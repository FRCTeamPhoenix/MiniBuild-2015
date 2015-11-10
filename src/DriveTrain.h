/*
 * DriveTrain.h
 *
 *  Created on: Nov 7, 2015
 *      Author: connortess
 */

#ifndef SRC_DRIVETRAIN_H_
#define SRC_DRIVETRAIN_H_
#include "RobotDrive.h"
#include "Joystick.h"

class DriveTrain : public RobotDrive {

void automove(int moveDistance, int moveAngle, Gyro * gyro);

void updateEncoder(Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight);

void resetEncoder(Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight);

float distanceCalculate();

float position_x;
float position_y;


public:
   DriveTrain();
   virtual ~DriveTrain();
};

#endif /* SRC_DRIVETRAIN_H_ */

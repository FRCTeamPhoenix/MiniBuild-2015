/*
 * Shooter.h
 *
 *  Created on: Nov 14, 2015
 *      Author: connortess
 */

#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_
#include "WPILib.h"
#include "Constants.h"

class Shooter {
public:
   Encoder* m_encoder;
   Talon* m_magazineMotor;
   Talon* m_flywheelMotorRight;
   Talon* m_flywheelMotorLeft;

   void loadBall();
   void fireBall();

   Shooter(
         Encoder* encoder,
         Talon* magazineMotor,
         Talon* flywheelMotorRight,
         Talon* flywheelMotorLeft);
   virtual ~Shooter();
};

#endif /* SRC_SHOOTER_H_ */

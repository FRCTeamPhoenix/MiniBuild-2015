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
#include "Controllers.h"
#include <Math.h>

class Shooter {
private:
   Encoder* m_encoder;
   Talon* m_magazineMotor;
   Talon* m_flywheelMotorRight;
   Talon* m_flywheelMotorLeft;
   Controllers* m_controllers;

   void loadBall();
   void checkLoader();
   void fireBall();
   void checkButton();

   int ticks = 0;

   Shooter(
         Encoder* encoder,
         Talon* magazineMotor,
         Talon* flywheelMotorRight,
         Talon* flywheelMotorLeft,
         Controllers* controllers);
   virtual ~Shooter();
};

#endif /* SRC_SHOOTER_H_ */

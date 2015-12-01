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
   Talon* m_flywheelMotor;
   Controllers* m_controllers;

public:
   void loadBall();
   void fireBall();

   int ticks = 0;

   Shooter(
         Encoder* encoder,
         Talon* magazineMotor,
         Talon* flywheelMotor,
         Controllers* controllers);
   virtual ~Shooter();
public:
   void checkButton();
   void checkLoader();
};

#endif /* SRC_SHOOTER_H_ */

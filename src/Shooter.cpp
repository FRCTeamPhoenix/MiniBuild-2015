/*
 * Shooter.cpp

 *
 *  Created on: Nov 14, 2015
 *      Author: connortess
 */

#include <Shooter.h>

Shooter::Shooter(
      Encoder* encoder,
      Talon* magazineMotor,
      Talon* flywheelMotorRight,
      Talon* flywheelMotorLeft,
      Controllers* controllers):

      m_encoder(encoder),
      m_magazineMotor(magazineMotor),
      m_flywheelMotorRight(flywheelMotorRight),
      m_flywheelMotorLeft(flywheelMotorLeft),
      m_controllers(controllers)

{

}
   //Function for loading the ball into the shooter
   void Shooter::loadBall(){
      ticks = m_encoder->Get();
      m_magazineMotor->Set(TeleConstants::magazineMotorSpeed);
   }
   //Function for making the flywheel motors spin
   void Shooter::fireBall(){
      m_flywheelMotorRight->Set(TeleConstants::flywheelSpeed);
      m_flywheelMotorLeft->Set(-TeleConstants::flywheelSpeed);
      Wait(TeleConstants::motorRunTimeShooter);
   }
   //Checks if the load button and fire button has been pressed
   //If the button has been pressed it will call the function needed
   void Shooter::checkButton(){
      if (m_controllers->GetGamepadButton(driveButtons::loadButton)){
         loadBall();
      }
      if (m_controllers->GetGamepadButton(driveButtons::fireButton)){
         fireBall();
      }
   }
   //Checks if the wheel that loads the ball has moved all the way it needs to
   void Shooter::checkLoader(){
      if ((abs(ticks - m_encoder->Get())) < (TeleConstants::magazineMotorTicksPerRotation / 2)){
         m_magazineMotor->Set(0);
      }
   }
Shooter::~Shooter() {
   // TODO Auto-generated destructor stub
}


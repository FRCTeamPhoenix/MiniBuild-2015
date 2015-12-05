/*
 * Loader.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: Brin Harper
 *      Possible add a sensor
 */

#include "Loader.h"

Loader::Loader(
      Talon* loadMotor,
      Controllers* controllers,
      DigitalInput* limitSwitch):

      m_loadMotor(loadMotor),
      m_controllers(controllers),
      m_limitSwitch(limitSwitch)
{

}

   void Loader::startLoader(){
      m_loadMotor->Set(TeleConstants::loaderMotorSpeed);
   }

   void Loader::stopLoader(){
      m_loadMotor->Set(0);
   }

   // We are using this variable to keep track of the number of times the
   // updateLoader function has been called.  This way, we can stop the loader
   // motor after a specified number of seconds, as decided in the constants file.
   // int counter = TeleConstants::seconds * TeleConstants::ticksPerSecond;

   // Checks to see if the buttons for starting and stopping the loader
   // have been pressed; acts accordingly
   void Loader::updateLoader(){
	   //counter--;
      if (m_controllers->GetGamepadButton(driveButtons::runLoaderMotor)){
         startLoader();
      }
      else if (m_controllers->GetGamepadButton(driveButtons::stopLoaderMotor)){
         stopLoader();
      }
   }

Loader::~Loader() {
	// TODO Auto-generated destructor stub
}

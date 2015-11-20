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
   void Loader::updateLoader(){
      if (m_controllers->GetGamepadButton(driveButtons::runLoaderMotor)){
         startLoader();
      }
      if (m_controllers->GetGamepadButton(driveButtons::stopLoaderMotor) || m_limitSwitch->Get()){
         stopLoader();
      }
      if (m_limitSwitch->Get()){

      }
   }
Loader::~Loader() {
	// TODO Auto-generated destructor stub
}

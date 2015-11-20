/*
 * Loader.h
 *
 *  Created on: Nov 9, 2015
 *      Author: Brin Harper
 */

#ifndef SRC_LOADER_H_
#define SRC_LOADER_H_
#include "WPILib.h"
#include "Constants.h"
#include "Controllers.h"

class Loader {
private:
   Talon* m_loadMotor;
   Controllers* m_controllers;
   DigitalInput* m_limitSwitch;

   void startLoader();
   void stopLoader();
   void updateLoader();

	Loader(
	      Talon* loadMotor,
	      Controllers* controllers,
	      DigitalInput* limitSwitch);
	virtual ~Loader();
};

#endif /* SRC_LOADER_H_ */

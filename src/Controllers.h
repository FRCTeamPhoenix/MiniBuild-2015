/*
 * Controllers.h
 *
 *  Created on: Nov 9, 2015
 *      Author: Brin Harper
 */

#ifndef SRC_CONTROLLERS_H_
#define SRC_CONTROLLERS_H_
#include "Joystick.h"
#include "Loader.h"

class Controllers {
public:
	Controllers();
	virtual ~Controllers();
private:
	Joystick m_stick;
};

#endif /* SRC_CONTROLLERS_H_ */

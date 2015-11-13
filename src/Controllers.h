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
#include "WPILib.h"
#include "Constants.h"
#include "GenericHID.h"

class Controllers {
public:
	Controllers(Joystick* joystick);
	virtual ~Controllers();
	bool GetJoystickButton(uint32_t joystickButton);
	bool GetGamepadButton(uint32_t gamepadButton);
	float GetTwistWithDeadZone(float deadZone = 0.05);
	float GetXMovement(GenericHID::JoystickHand hand = GenericHID::kRightHand);
private:
	Joystick* m_stick;
};

#endif /* SRC_CONTROLLERS_H_ */

/*
 * Controllers.h
 *
 *  Created on: Nov 9, 2015
 *      Author: Brin Harper
 */

#ifndef SRC_CONTROLLERS_H_
#define SRC_CONTROLLERS_H_

#include "WPILib.h"
#include "Constants.h"

class Controllers {
public:
	Controllers(Joystick* joystick, Joystick* gamepad);
	virtual ~Controllers();

	bool GetJoystickButton(uint32_t joystickButton);
	bool GetGamepadButton(uint32_t gamepadButton);

	float GetTwistWithDeadZone(float deadZone = 0.05);

	float GetStickX();
	float GetStickY();
	float GetStickZ();

	float GetStickThrottle();

	float GetTwistFromSmallJoystick();
	void rumble();

private:
	Joystick* m_stick;
	Joystick* m_gamepad;
};

#endif /* SRC_CONTROLLERS_H_ */

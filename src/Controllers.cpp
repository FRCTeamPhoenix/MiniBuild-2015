/*
 * Controllers.cpp
 *
 *  Created on: Nov 9, 2015
 *      Author: Brin Harper
 *
 * The Controllers class was created in order to simultaneously control the
 * joystick and gamepad as a single unit, rather than as two separate entities.
 *
 */

#include "Controllers.h"

Controllers::Controllers(Joystick* joystick):
	m_stick(joystick)
{

}

// Takes a joystick button and returns whether or not it has been pressed.
bool Controllers::GetJoystickButton(uint32_t joystickButton) {
	return m_stick->GetRawButton(joystickButton);
}

// Takes a gamepad button and returns whether or not it has been pressed.
bool Controllers::GetGamepadButton(uint32_t gamepadButton) {
	return m_stick->GetRawButton(gamepadButton);
}

/*
 * Gets the current twist value of the joystick.
 * A deadzone is built in so that motion will not occur if there has been
 * a small amount of inadvertent rotation.
 */
float Controllers::GetTwistWithDeadZone(float deadZone) {
	float twistValue = m_stick->GetTwist();
	if (fabs(twistValue) <= deadZone) {
		return 0;
	} else {
		return twistValue;
	}
}

float Controllers::GetXMovement(GenericHID::JoystickHand hand) {
	return m_stick->GetX(hand);
}

Controllers::~Controllers() {

}


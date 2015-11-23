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

#include "WPILib.h"

Controllers::Controllers(Joystick* joystick, Joystick* gamepad):
	m_stick(joystick),
	m_gamepad(gamepad)
{

}

   void Controllers::rumble(){
      m_gamepad->SetRumble(Joystick::RumbleType::kRightRumble, 1.0);
      m_gamepad->SetRumble(Joystick::RumbleType::kLeftRumble, 1.0);
   }

// Takes a joystick button and returns whether or not it has been pressed.
bool Controllers::GetJoystickButton(uint32_t joystickButton) {
	return m_stick->GetRawButton(joystickButton);
}

// Takes a gamepad button and returns whether or not it has been pressed.
bool Controllers::GetGamepadButton(uint32_t gamepadButton) {
	return m_gamepad->GetRawButton(gamepadButton);
}

/*
 * Gets the current twist value of the joystick.
 * A deadzone is built in so that motion will not occur if there has been
 * a small amount of inadvertent rotation.
 */
//float Controllers::GetTwistWithDeadZone(float deadZone) {
//	float twistValue = m_stick->GetTwist();
//	if (fabs(twistValue) <= deadZone) {
//		return 0;
//	} else {
//		return twistValue;
//	}
//}

float Controllers::GetTwistFromSmallJoystick() {
	float twistValue = 0.0f;
	// turns right
	if (GetJoystickButton(joystickRightButton)) {
		twistValue += 0.01;
	}
	// turns left
	else if (GetJoystickButton(joystickLeftButton)) {
		twistValue -= 0.01;
	}
	return twistValue;
}

float Controllers::GetStickX() {
	if (fabs(m_stick->GetX()) <= controlsConstants::joystickDeadZone) {
		return 0.0f;
	} else {
		return m_stick->GetX() / 5;
	}
}

float Controllers::GetStickY() {
	if (fabs(m_stick->GetY()) <= controlsConstants::joystickDeadZone) {
		return 0.0f;
	} else {
		return m_stick->GetY() / 5;
	}
}


float Controllers::GetStickZ() {
	if (fabs(m_stick->GetZ()) <= controlsConstants::joystickDeadZone) {
		return 0.0f;
	} else {
		return m_stick->GetZ() / 10;
	}
}


Controllers::~Controllers() {

}


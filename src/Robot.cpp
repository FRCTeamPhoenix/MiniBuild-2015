#include "WPILib.h"
#include "Targeting.h"
#include "DriveTrain.h"
#include "Constants.h"
/**
 * This is a demo program showing how to use Mecanum control with the driveTrain class.
 */
class Robot: public SampleRobot
{   // robot drive system
	DriveTrain driveTrain;
	// only joystick
	Joystick stick;
	AxisCamera *camera;
	Targeting targeting;

public:
	Robot() :		
		driveTrain(),
		stick(Port::joystickChannel),
		camera(),
		targeting(camera)
{
		driveTrain.SetExpiration(0.1);
		// invert the left side motors
		driveTrain.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
		// you may need to change or remove this to match your robot
		driveTrain.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
		camera = new AxisCamera(cameraIP);
		targeting = Targeting(camera);
}

	/**
	 * Runs the motors with Mecanum drive.
	 */
	void OperatorControl()
	{
		driveTrain.SetSafetyEnabled(false);
		while (IsOperatorControl() && IsEnabled())
		{
			// Use the joystick X axis for lateral movement, Y axis for forward movement, and Z axis for rotation.
			// This sample does not use field-oriented drive, so the gyro input is set to zero.
			driveTrain.MecanumDrive_Cartesian(stick.GetX(), stick.GetY(), stick.GetZ());

			// Sends the latest frames to the driver station
			targeting.displaySource();
			// wait 5ms to avoid hogging CPU cycles
			Wait(0.005);
		}
	}
};

START_ROBOT_CLASS(Robot);

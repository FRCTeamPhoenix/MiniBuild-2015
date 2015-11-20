#include "WPILib.h"
#include "DriveTrain.h"
#include "Controllers.h"
#include "Constants.h"
/**
 * This is a demo program showing how to use Mecanum control with the driveTrain class.
 */
class Robot: public SampleRobot
{

   // robot drive system
   DriveTrain m_driveTrain;
   // only joystick
   Joystick m_stick;
   Joystick m_gamepad;
   Controllers m_controller;

public:
   Robot() :
      // these must be initialized in the same order
	  // as they are declared above.
      m_driveTrain(),
	  m_stick(Port::joystickChannel),
	  m_gamepad(Port::gamepadChannel),
      m_controller(&m_stick, &m_gamepad)
   {
	  m_driveTrain.SetExpiration(0.1);
      // invert the left side motors
      m_driveTrain.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
      // you may need to change or remove this to match your robot
      m_driveTrain.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
   }

   /**
    * Runs the motors with Mecanum drive.
    */
   void OperatorControl()
   {
      m_driveTrain.SetSafetyEnabled(false);
      while (IsOperatorControl() && IsEnabled())
      {
    	 /*
         Use the joystick X axis for lateral movement, Y axis for forward movement, and Z axis for rotation.
         This sample does not use field-oriented drive, so the gyro input is set to zero.
         TODO change stick to m_controller
         */
    	 float xMovement = m_controller.GetXMovement();
    	 float yMovement = m_controller.GetYMovement();
    	 float zMovement = m_controller.GetTwistWithDeadZone() + m_controller.GetTwistFromSmallJoystick();
    	 m_driveTrain.MecanumDrive_Cartesian(xMovement, yMovement, zMovement);
         // wait 5ms to avoid hogging CPU cycles
         Wait(0.005);
      }
   }
};

START_ROBOT_CLASS(Robot);

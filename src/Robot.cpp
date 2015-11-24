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
	   m_driveTrain.SetInvertedMotor(RobotDrive::MotorType::kFrontLeftMotor, true);
	   m_driveTrain.SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor, true);
	  //m_driveTrain.SetExpiration(0.1);
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
         */
    	 printf("X:%2.2f  Y:%2.2f  Z:%2.2f\n", m_controller.GetStickX(), m_controller.GetStickY(), m_controller.GetStickZ());
    	 m_driveTrain.MecanumDrive_Cartesian(m_controller.GetStickX(), m_controller.GetStickY(), m_controller.GetStickZ());
         // wait 5ms to avoid hogging CPU cycles
         Wait(0.005);
      }
   }
};

START_ROBOT_CLASS(Robot);

#include "WPILib.h"
#include "DriveTrain.h"
#include "Controllers.h"
#include "Constants.h"
#include "Attachment.h"
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
   Encoder m_shooterEncoder;
   Talon m_magazineMotor;
   Talon m_flywheelMotor;
   Shooter m_shooter;
   Talon m_loaderMotor;
   DigitalInput m_limitSwitch;
   Loader m_loader;
   Attachment m_attachment;

public:
   Robot() :
      // these must be initialized in the same order
	  // as they are declared above.
      m_driveTrain(),
      m_stick(Port::joystickChannel),
      m_gamepad(Port::gamepadChannel),
      m_controller(&m_stick, &m_gamepad),
      m_shooterEncoder(Port::firstEncoderChannel, Port::secondEncoderChannel),
      m_magazineMotor(Port::magazineChannel),
      m_flywheelMotor(Port::flywheelChannel),
      m_shooter(&m_shooterEncoder, &m_magazineMotor, &m_flywheelMotor, &m_controller),
      m_loaderMotor(Port::loaderChannel),
      m_limitSwitch(Port::digitalInputChannel),
      m_loader(&m_loaderMotor, &m_controller, &m_limitSwitch),
      m_attachment(&m_shooter, &m_loader)
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
    	 //printf("X:%2.2f  Y:%2.2f  Z:%2.2f\n", m_controller.GetStickX(), m_controller.GetStickY(), m_controller.GetStickZ());
         printf("T:%2.2f\n", m_controller.GetStickThrottle());
         m_driveTrain.MecanumDrive_Cartesian(m_controller.GetStickX(), m_controller.GetStickY(), m_controller.GetStickZ());
         // wait 5ms to avoid hogging CPU cycles
         m_attachment.checkAllButtons();
         Wait(0.005);
      }
   }
};

START_ROBOT_CLASS(Robot);

#include "WPILib.h"
#include "DriveTrain.h"
#include "Constants.h"
/**
 * This is a demo program showing how to use Mecanum control with the driveTrain class.
 */
class Robot: public SampleRobot
{

   // robot drive system
   DriveTrain driveTrain;
   // only joystick
   Joystick stick;

public:
   Robot() :
      // these must be initialized in the same order
      driveTrain(),
      // as they are declared above.
      stick(Port::joystickChannel)
   {
      driveTrain.SetExpiration(0.1);
      // invert the left side motors
      driveTrain.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
      // you may need to change or remove this to match your robot
      driveTrain.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
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

         // wait 5ms to avoid hogging CPU cycles
         Wait(0.005);
      }
   }
};

START_ROBOT_CLASS(Robot);

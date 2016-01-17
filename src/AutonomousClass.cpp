
#include "WPILib.h"
#include "Constants.h"
#include "AutonomousClass.h"
#include "math.h"



AutonomousClass::AutonomousClass(DriveTrain * driveTrain, Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight, Gyro * gyro):

        m_position_x(0.0f),
        m_position_y(0.0f),
        m_position_xRotate(0.0f),
        m_position_yRotate(0.0f),
        m_currentPosition(0.0f),
        m_finalPosition(0.0f),
        m_time(0.0f),
        m_desiredMoveAngle(0.0),
        m_atPosition(false),
        m_driveTrain(driveTrain),
        m_gyro(gyro),
        adjustedMoveAngle(0),
        rotateAdjust(0)
{
	   //reset all the encoders and the gyro
	   //(this is okay since we are in a constructor and it won't be called during runtime)
       frontRight->Reset();
       frontLeft->Reset();
       backLeft->Reset();
       backRight->Reset();
       m_gyro->InitGyro();
       m_gyro->Reset();

       //Initialize wheel encoder array to args
       wheelEncoders[RF]=frontRight;
       wheelEncoders[LF]=frontLeft;
       wheelEncoders[LR]=backLeft;
       wheelEncoders[RR]=backRight;

       //Initialize encoder ticks and old encoder ticks to all zero for each encoder
       encoderTicks[RF]=0;
       encoderTicks[LF]=0;
       encoderTicks[LR]=0;
       encoderTicks[RR]=0;

       oldEncoderTicks[RF]=0;
       oldEncoderTicks[LF]=0;
       oldEncoderTicks[LR]=0;
       oldEncoderTicks[RR]=0;

       m_ticksPerInch[RF] = AutoConstants::ticksPerInchRF;
       m_ticksPerInch[LF] = AutoConstants::ticksPerInchLF;
       m_ticksPerInch[LR] = AutoConstants::ticksPerInchLR;
       m_ticksPerInch[RR] = AutoConstants::ticksPerInchRR;





}

//moves to desired position
void AutonomousClass::autoMove(int desiredx, int desiredy, double maxTime){
	Timer timer;

    double speed = 0; //The speed with which we move (changed each loop)
    m_atPosition = false; //at first, we're not at our desired position
    m_finalPosition = sqrt((desiredy * desiredy) + (desiredx * desiredx)); //calc magnitude of position vector
    m_desiredMoveAngle = atan2(desiredy, desiredx); //calc angle of position vector (to polar)
    timer.Start(); //start timer for timeout period

    //while we're not at our position and we haven't reached a timeout period
    while (!m_atPosition && !timer.HasPeriodPassed(maxTime)){
    	//if we're within a certain distance of our goal, we're at position
       if (abs(m_currentPosition - m_finalPosition) < AutoConstants::finalPositionTolerance){
            m_atPosition = true;
       }

       //update the encoder!
       updateEncoder();
       //calculate rotated polar distance
       distanceCalculate();
       //if the robot is not 80% of the way to the target location, increase speed to 1
       if (m_currentPosition / m_finalPosition < .8){
           speed = 0.6;
       }
       //if the robot is more than 90% and less than 95% to the target location go at half speed
       else if (m_currentPosition/m_finalPosition > .9 && m_currentPosition/m_finalPosition < .95){
           speed = 0.3;
       }
       // adjust the angle based on calculated distance
       adjustedMoveAngle = (m_desiredMoveAngle + m_desiredMoveAngle - atan2(m_position_yRotate, m_position_xRotate) ) * AutoConstants::radToDegree - 45;
       rotateAdjust = -(((m_gyro->GetAngle()))/360); //mod rotation by 360 degrees
       m_driveTrain->MecanumDrive_Polar(speed, adjustedMoveAngle, rotateAdjust);//drive
       Wait(.005);
    }
    //reset timer to start again
    timer.Stop();
    timer.Reset();
}
//Update wheel encoders
void AutonomousClass::updateEncoder(){
   //This loops over each wheel
    for (int i = RF; i <= RR; i++){
        encoderTicks[i] = ((wheelEncoders[i]->Get())/m_ticksPerInch[i])-oldEncoderTicks[i];
    }
}

//Reset wheel encoders without resetting hardware
void AutonomousClass::resetEncoder(){
   //This loops over each wheel
    for (int i = RF; i <= RR; i++){
           oldEncoderTicks[i]=encoderTicks[i];
       }
}
//Calculate new position based on move angle

void AutonomousClass::distanceCalculate(){
    m_position_xRotate = (encoderTicks[RF]+encoderTicks[LR])/2;
    m_position_yRotate = (-encoderTicks[LF])/2;


    m_currentPosition = sqrt((m_position_yRotate * m_position_yRotate) + ( m_position_xRotate * m_position_xRotate));
}
//main auto drive mode
void AutonomousClass::automode1(){
    autoMove(0,48,15);
    resetEncoder();
    autoMove(-48,0,15);
    resetEncoder();
    autoMove(0,96,15);
    resetEncoder();
    autoMove(-12,0,15);
    resetEncoder();
    autoMove(0,-96,15);
}
//forward drive
void AutonomousClass::automode2(){
    autoMove(0,24,15);
}
//drive left
void AutonomousClass::automode3(){
    autoMove(-24,0,15);
}
//drive up and to the left at 45 degrees
void AutonomousClass::automode4(){
    autoMove(-24,24,15);
}

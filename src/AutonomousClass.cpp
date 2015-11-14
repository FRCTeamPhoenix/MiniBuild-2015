
#include "WPILib.h"
#include "Constants.h"
#include "AutonomousClass.h"
#include "math.h"



AutonomousClass::AutonomousClass(DriveTrain * driveTrain, Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight, Gyro * gyro):

        m_position_x(0.0f),
        m_position_y(0.0f),
        m_position_xRotate(0.0f),
        m_position_yRotate(0.0f),
        m_position(0.0f),
        m_atPosition(false),
        m_driveTrain(driveTrain),
        RFEncoder(frontRight),
        LFEncoder(frontLeft),
        LREncoder(backLeft),
        RREncoder(backRight),
        m_gyro(gyro),
        ajustedMoveAngle(0),
        rotateAdjust(0)




{
       RFEncoder->Reset();
       LFEncoder->Reset();
       LREncoder->Reset();
       RREncoder->Reset();
       m_gyro->InitGyro();
       m_gyro->Reset();

       wheelEncoders[0]=RFEncoder;
       wheelEncoders[1]=LFEncoder;
       wheelEncoders[2]=LREncoder;
       wheelEncoders[3]=RREncoder;

       encoderTicks[0]=0;
       encoderTicks[1]=0;
       encoderTicks[2]=0;
       encoderTicks[3]=0;

       oldEncoderTicks[0]=0;
       oldEncoderTicks[1]=0;
       oldEncoderTicks[2]=0;
       oldEncoderTicks[3]=0;




}

void AutonomousClass::autoMove(double speed,int desiredx, int desiredy, int desiredMoveAngle){
    m_atPosition=false;
    while (!m_atPosition){

       updateEncoder();
       distanceCalculate(desiredMoveAngle);


       if ((m_position_x < desiredx+1)
           && (m_position_x > desiredx-1)
           && (m_position_y < desiredy+1)
           && (m_position_y > desiredy-1)){
           m_atPosition=true;
       }

       ajustedMoveAngle = desiredMoveAngle + atan2(desiredy-m_position_y, desiredx-m_position_x)*AutoConstants::radToDegree;
       rotateAdjust=-(((m_gyro->GetAngle())%360)/360);

       m_driveTrain->MecanumDrive_Polar(speed,desiredMoveAngle,rotateAdjust);

       Wait(.05);


    }
}

void AutonomousClass::updateEncoder(){
    for (int i = RF; i <= RR; i++){
            encoderTicks[i]=wheelEncoders[i]->Get()-oldEncoderTicks[i];
        }




}


void AutonomousClass::resetEncoder(){
    for (int i = RF; i <= RR; i++){
           oldEncoderTicks[i]=encoderTicks[i];
       }
}
void AutonomousClass::distanceCalculate(int desiredMoveAngle){
    m_position_xRotate = ((encoderTicks[RF]+encoderTicks[LR])/2);
    m_position_yRotate = ((encoderTicks[LF]+encoderTicks[RR])/2);
    m_position = sqrt((m_position_yRotate* m_position_yRotate)+( m_position_xRotate* m_position_xRotate));
    m_position_x = (m_position*(sin((desiredMoveAngle/AutoConstants::radToDegree))))/AutoConstants::ticksPerInch;
    m_position_y = (m_position*(cos(desiredMoveAngle/AutoConstants::radToDegree)))/AutoConstants::ticksPerInch;


}
//main auto drive mode
void AutonomousClass::automode1(){
    autoMove(AutoConstants::autoMoveSpeed,0,48,0);
    resetEncoder();
    autoMove(AutoConstants::autoMoveSpeed,-48,0,90);
    resetEncoder();
    autoMove(AutoConstants::autoMoveSpeed,0,96,0);
    resetEncoder();
    autoMove(AutoConstants::autoMoveSpeed,-12,0,90);
    resetEncoder();
    autoMove(AutoConstants::autoMoveSpeed,0,-96,180);
}
//forward drive
void AutonomousClass::automode2(){
    autoMove(AutoConstants::autoMoveSpeed,0,24,0);
}
//drive left
void AutonomousClass::automode3(){
    autoMove(AutoConstants::autoMoveSpeed,-24,0,90);
}
//drive up and to the left at 45 degrees
void AutonomousClass::automode4(){

    autoMove(AutoConstants::autoMoveSpeed,-24,24,45);
}

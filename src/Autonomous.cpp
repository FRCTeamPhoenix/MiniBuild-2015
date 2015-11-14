
#include "WPILib.h"
#include "Constants.h"
#include "Autonomous.h"
#include "math.h"



Autonomous::Autonomous(DriveTrain * driveTrain, Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight):

        m_driveTrain(driveTrain),
        RFEncoder(frontRight),
        LFEncoder(frontLeft),
        LREncoder(backLeft),
        RREncoder(backRight),
        wheelEncoders(RFEncoder, LFEncoder, LREncoder, RREncoder),
        encoderTicks(0,0,0,0),
        oldEncoderTicks(0,0,0,0),

        m_position_x(0.0f),
        m_position_y(0.0f),
        m_position_xRotate(0.0f),
        m_position_yRotate(0.0f),
        m_position(0.0f),
        m_atPosition(false)

{




}

void Autonomous::autoMove(float speed,int desiredx, int desiredy, int moveAngle){
    updateEncoder();
    distanceCalculate(moveAngle);
    if ((m_position_x < desiredx+1)
        && (m_position_x > desiredx-1)
        && (m_position_y < desiredy+1)
        && (m_position_y > desiredy-1)){
        m_atPosition=true;
    }
    else {
        moveAngle = moveAngle + atan2(desiredy-m_position_y, desiredx-m_position_x)*radToDegree;

        if (!m_atPosition){
            m_driveTrain->MecanumDrive_Polar(speed,moveAngle,0);
        }
    }
}

void Autonomous::updateEncoder(){
    for (int i = RF; i <= RR; i++){
            encoderTicks[i]=wheelEncoders[i]->Get()-oldEncoderTicks[i];
        }



}


void Autonomous::resetEncoder(){
    for (int i = RF; i <= RR; i++){
           oldEncoderTicks[i]=encoderTicks[i];
       }
}
void Autonomous::distanceCalculate(int moveAngle){
    m_position_xRotate = ((encoderTicks[RF]+encoderTicks[LR])/2);
    m_position_yRotate = ((encoderTicks[LF]+encoderTicks[RR])/2);
    m_position = sqrt((m_position_yRotate* m_position_yRotate)+( m_position_xRotate* m_position_xRotate));
    m_position_x = (m_position*(sin((moveAngle/radToDegree))))/ticksPerInch;
    m_position_y = (m_position*(cos(moveAngle/radToDegree)))/ticksPerInch;


}

void Autonomous::automode1(){
    autoMove(autoMoveSpeed,0,48,0);
    resetEncoder();
    autoMove(autoMoveSpeed,-48,0,90);
    resetEncoder();
    autoMove(autoMoveSpeed,0,96,0);
    resetEncoder();
    autoMove(autoMoveSpeed,-12,0,90);
    resetEncoder();
    autoMove(autoMoveSpeed,0,-96,180);
}

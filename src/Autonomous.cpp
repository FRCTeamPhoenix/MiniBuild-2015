
#include "WPILib.h"
#include "Constants.h"
#include "Autonomous.h"
#include "math.h"

//the number of ticks in one inch
static const float ticksPerInch=7.6433;
static const float radToDegree = 57.3248;
static const float autoMoveSpeed =1;
Autonomous::Autonomous(Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight){

    position_x =0;
    position_y=0;

    m_frontLeft = frontLeft;
    m_frontRight = frontRight;
    m_backLeft = backLeft;
    m_backRight = backRight;

    atPosition = false;
}

void Autonomous::autoMove(float speed,int desiredx, int desiredy, int moveAngle){
    updateEncoder();
    distanceCalculate();
    if ((position_x < desiredx+1)
        && (position_x > desiredx-1)
        && (position_y < desiredy+1)
        && (position_y > desiredy-1)){
        atPosition=true;
    }
    else {
        moveAngle = atan2(desiredy-position_y, desiredx-position_x)*radToDegree;

        if (!atPosition){
            MecanumDrive_Polar(speed, moveAngle);
        }
    }
}

void Autonomous::updateEncoder(){

    FRencoderTicks=m_frontRight->Get();
    FLencoderTicks=m_frontLeft->Get();
    BRencoderTicks=m_backRight->Get();
    BLencoderTicks=m_backLeft->Get();
}


void Autonomous::resetEncoder(){
    FRencoderTicks=0;
    FLencoderTicks=0;
    BRencoderTicks=0;
    BLencoderTicks=0;
}
void Autonomous::distanceCalculate(){
    position_x = ((FRencoderTicks+BLencoderTicks)/2)/ticksPerInch;
    position_y = ((FLencoderTicks+BRencoderTicks)/2)/ticksPerInch;


}

void Autonomous::automode1(){
    autoMove(autoMoveSpeed,0,48,0);
}

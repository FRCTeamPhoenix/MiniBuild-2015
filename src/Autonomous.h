#ifndef SRC_DRIVETRAIN_H_
#define SRC_DRIVETRAIN_H_
#include "RobotDrive.h"
#include "Joystick.h"

class Autonomous{

public:

    Autonomous(Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight);

    void autoMove(float speed, int desiredx, int desiredy, int moveAngle);

    void updateEncoder();

    void resetEncoder();

    void automode1();

    void distanceCalculate(float FRencoderTicks, float FLencoderTicks, float BRencoderTicks, float BLencoderTicks);

    enum WheelPosition {
        RF,
        LF,
        RR,
        LR
    }
    float FLencoderTicks;
    float FRencoderTicks;
    float BRencoderTicks;
    float BLencoderTicks;
    float position_x;
    float position_y;
    bool atPosition;
    Encoder * m_frontLeft;
    Encoder * m_frontRight;
    Encoder * m_backLeft;
    Encoder * m_backRight;


    virtual ~Autonomous(){};


};





#endif /* SRC_DRIVETRAIN_H_ */

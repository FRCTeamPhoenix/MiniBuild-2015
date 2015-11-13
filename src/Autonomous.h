#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_
#include "DriveTrain.h"
#include "Joystick.h"



class Autonomous{

public:

    Autonomous(DriveTrain * drivetrain, Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight);

    void autoMove(float speed, int desiredx, int desiredy, int moveAngle);

    void updateEncoder();

    void resetEncoder();

    void automode1();

    void distanceCalculate(int moveAngle);

    enum WheelPosition {
        RF,
        LF,
        LR,
        RR
    };
    DriveTrain * m_driveTrain;
    Encoder * RFEncoder;
    Encoder * LFEncoder;
    Encoder * RREncoder;
    Encoder * LREncoder;
    Encoder * wheelEncoders[4];

    int encoderTicks[4];
    int oldEncoderTicks[4];

    float m_position_x;
    float m_position_y;
    float m_position_xRotate;
    float m_position_yRotate;
    float m_position;
    bool m_atPosition;



    virtual ~Autonomous(){};


};





#endif /* SRC_AUTONOMOUS_H_ */

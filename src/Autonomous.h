#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_
#include "DriveTrain.h"
#include "Joystick.h"



class Autonomous{

public:

    Autonomous(DriveTrain * drivetrain, Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight);

    void autoMove(double speed, int desiredx, int desiredy, int moveAngle);

    void updateEncoder();

    void resetEncoder();

    void automode1();

    void distanceCalculate(int moveAngle);

    void automode2();

    void automode3();

    void autmode4();

    enum WheelPosition {
        RF,
        LF,
        LR,
        RR
    };

    float m_position_x;
    float m_position_y;
    float m_position_xRotate;
    float m_position_yRotate;
    float m_position;
    bool m_atPosition;
    DriveTrain * m_driveTrain;
    Encoder * RFEncoder;
    Encoder * LFEncoder;
    Encoder * LREncoder;
    Encoder * RREncoder;

    Encoder * wheelEncoders[4];

    int encoderTicks[4];
    int oldEncoderTicks[4];





    virtual ~Autonomous(){};


};





#endif /* SRC_AUTONOMOUS_H_ */

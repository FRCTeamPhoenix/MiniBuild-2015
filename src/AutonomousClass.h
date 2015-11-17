#ifndef SRC_AutonomousClass_H_
#define SRC_AutonomousClass_H_
#include "DriveTrain.h"
#include "Joystick.h"



class AutonomousClass {

public:

    AutonomousClass(DriveTrain * drivetrain, Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight, Gyro * gyro);

    void autoMove(double speed, int desiredx, int desiredy, int desiredMoveAngle,double maxSpeed);

    void updateEncoder();

    void resetEncoder();

    void automode1();

    void distanceCalculate(int desiredMoveAngle);

    void automode2();

    void automode3();

    void automode4();

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

    float m_currentPosition;

    float m_finalPosition;

    float m_time;

    bool m_atPosition;
    DriveTrain * m_driveTrain;
    Encoder * RFEncoder;
    Encoder * LFEncoder;
    Encoder * LREncoder;
    Encoder * RREncoder;
    Gyro * m_gyro;

    Encoder * wheelEncoders[4];

    int encoderTicks[4];
    int oldEncoderTicks[4];

    int adjustedMoveAngle;
    float rotateAdjust;




    virtual ~AutonomousClass(){};


};





#endif /* SRC_AutonomousClass_H_ */

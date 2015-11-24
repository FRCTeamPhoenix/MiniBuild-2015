#ifndef SRC_AutonomousClass_H_
#define SRC_AutonomousClass_H_
#include "DriveTrain.h"
#include "Joystick.h"



class AutonomousClass {

public:

    AutonomousClass(Timer * m_timer,DriveTrain * drivetrain, Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight, Gyro * gyro);

    void autoMove(int desiredx, int desiredy,double maxSpeed);

    void updateEncoder();

    void resetEncoder();

    void automode1();

    void distanceCalculate(int desiredMoveAngle);

    void automode2();

    void automode3();

    void automode4();

    enum WheelPosition { //enum for the purpose of looping from RF to LF to LR to RR
        RF,
        LF,
        LR,
        RR
    };

 private:
    float m_position_x;
    float m_position_y;

    float m_position_xRotate;  //the x and y for the rotated plane
    float m_position_yRotate;

    float m_currentPosition;

    float m_finalPosition;

    float m_time;

    double m_desiredMoveAngle;

    bool m_atPosition;
    Timer * m_timer;
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

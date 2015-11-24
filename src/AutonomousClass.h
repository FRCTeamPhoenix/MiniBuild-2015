#ifndef SRC_AutonomousClass_H_
#define SRC_AutonomousClass_H_
#include "DriveTrain.h"
#include "Joystick.h"



class AutonomousClass {

public:
	//constructor
    AutonomousClass(DriveTrain * drivetrain, Encoder * frontLeft, Encoder * frontRight, Encoder * backLeft, Encoder * backRight, Gyro * gyro);
    //moves to desired position
    void autoMove(int desiredx, int desiredy,double maxSpeed);
    //Update wheel encoders
    void updateEncoder();
    //Reset wheel encoders without resetting hardware
    void resetEncoder();
    //main auto drive mode
    void automode1();
    //Calculate new position based on move angle
    void distanceCalculate(int desiredMoveAngle);
    //forward drive
    void automode2();
    //drive left
    void automode3();
    //drive up and to the left at 45 degrees
    void automode4();

    enum WheelPosition { //enum for the purpose of looping from RF to LF to LR to RR
        RF,
        LF,
        LR,
        RR
    };

 private:
    //the x and y for the position
    float m_position_x;
    float m_position_y;

    float m_position_xRotate;  //the x and y for the rotated plane
    float m_position_yRotate;

    //the current position
    float m_currentPosition;
    //the final expected position for a movement
    float m_finalPosition;
    //used to track time and check timeout periods
    float m_time;
    //the angle between desired position and given position
    double m_desiredMoveAngle;

    //are we at the desired position during a movement
    bool m_atPosition;

    //here are all the pointers to hardware elements
    Timer * m_timer;
    DriveTrain * m_driveTrain;
    /*Encoder * RFEncoder;
    Encoder * LFEncoder;
    Encoder * LREncoder;
    Encoder * RREncoder;*/
    Gyro * m_gyro;

    //and an array used to iterate over the encoders
    Encoder * wheelEncoders[4];

    //more arrays used to iterate over current and relative encoder ticks
    int encoderTicks[4];
    int oldEncoderTicks[4];

    //adjusted angle of movement and rotation
    int adjustedMoveAngle;
    float rotateAdjust;
};

#endif /* SRC_AutonomousClass_H_ */

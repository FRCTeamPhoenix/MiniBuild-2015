#ifndef SRC_TARGETING_H_
#define SRC_TARGETING_H_

#include "WPILib.h"

class Targeting
{
public:
	Targeting(AxisCamera * camera);
	// Take the latest frame from the camera and send it to the driver station without any processing
	void displaySource();
private:
	ColorImage *m_sourceFrame;
	ColorImage *m_;
	AxisCamera *m_camera;
};

#endif /* SRC_TARGETING_H_ */

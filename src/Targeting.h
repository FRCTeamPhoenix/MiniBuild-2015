#ifndef SRC_TARGETING_H_
#define SRC_TARGETING_H_

#include "WPILib.h"

class Targeting
{
public:
	Targeting(AxisCamera* camera);
	// Takes the latest frame from the camera
	void updateSource();
	// Sends the latest frame to the driver station without any processing
	void runTargeting();
	//Returns a binary image with the target highlighted, inputImage is
	//the source to perform operations on
	BinaryImage* filterImage(ColorImage* inputImage);
	void start();
	void stop();
private:
	ColorImage *m_sourceFrame;
	BinaryImage *m_filteredFrame;
	AxisCamera *m_camera;
	bool m_targetingOn;
};

#endif /* SRC_TARGETING_H_ */

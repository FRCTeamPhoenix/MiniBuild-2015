#include "Targeting.h"

Targeting::Targeting(AxisCamera* camera):
        m_camera(camera), m_sourceFrame(new ColorImage(IMAQ_IMAGE_RGB))
{}

void Targeting::updateSource()
{
	m_camera->GetImage(m_sourceFrame);
}

BinaryImage* Targeting::filterImage(ColorImage* inputImage)
{
      //Should return either all black or all white. Test values
      return inputImage->ThresholdRGB(255, 255, 255, 255, 255, 255);
}

void Targeting::displaySource()
{
	updateSource();
	m_filteredFrame = filterImage(m_sourceFrame);

	CameraServer::GetInstance()->SetImage(filterImage(m_sourceFrame)->GetImaqImage());
}

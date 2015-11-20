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
      return inputImage->ThresholdHSL(100,180,100,255,51,255);
}

void Targeting::displaySource()
{
	updateSource();
	m_filteredFrame = filterImage(m_sourceFrame);
	ColorImage* output = new ColorImage(IMAQ_IMAGE_U8);
	float gv = 255;
	PixelValue pv;
	pv.grayscale = gv;

	imaqMultiplyConstant(output->GetImaqImage(), m_filteredFrame->GetImaqImage(), pv);

	CameraServer::GetInstance()->SetImage(output->GetImaqImage());

	delete m_filteredFrame;
}

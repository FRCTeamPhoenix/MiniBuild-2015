#include "Targeting.h"
#include "WPILib.h"

Targeting::Targeting(AxisCamera* camera):
		m_camera(camera)
{
	m_sourceFrame = new ColorImage(IMAQ_IMAGE_RGB);
	m_filteredFrame = new BinaryImage();
}

void Targeting::updateSource()
{
	m_camera->GetImage(m_sourceFrame);
}

BinaryImage* Targeting::filterImage(ColorImage* inputImage)
{
      //This should threshold for the green that was on Ben's shirt that night (roughly green, tweak this before testing)
    BinaryImage* i1 = inputImage->ThresholdHSL(0,360,0,30,0,30);
    BinaryImage* i2 = inputImage->ThresholdHSL(0,360,0,30,55,75);
    BinaryImage* i3 = inputImage->ThresholdHSL(0,0,0,0,0,0);
    imaqAdd(i3->GetImaqImage(), i1->GetImaqImage(), i2->GetImaqImage());
    return i3;
}

void Targeting::displaySource()
{
	//Update the source and filter the image each frame
	updateSource();
	m_filteredFrame = filterImage(m_sourceFrame);
	m_filteredFrame = m_filteredFrame->RemoveSmallObjects(true, 1);
	ColorImage* output = new ColorImage(IMAQ_IMAGE_U8);
	float gv = 255;
	PixelValue pv;
	pv.grayscale = gv;

	imaqMultiplyConstant(output->GetImaqImage(), m_filteredFrame->GetImaqImage(), pv);

	CameraServer::GetInstance()->SetImage(output->GetImaqImage());
	//Find the total percent of the image which is occupied by the target color (green)
	double total = 0;

	for(int i=0;i<m_filteredFrame->GetNumberParticles();i++){
		total += m_filteredFrame->GetParticleAnalysisReport(i).particleToImagePercent;
	}

	std::cout << "Total: " << total << "\n";

	delete m_filteredFrame;
}

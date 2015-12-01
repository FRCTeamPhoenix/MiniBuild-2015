#include "Targeting.h"
#include "WPILib.h"

Targeting::Targeting()
{
	m_sourceFrame = new ColorImage(IMAQ_IMAGE_RGB);
	m_filteredFrame = new BinaryImage();
}

void Targeting::setupCamera(AxisCamera* camera){
	m_camera = camera;
}

void Targeting::setupCameraServer(CameraServer* cameraServer){
	m_cameraServer = cameraServer;
}

void Targeting::updateSource()
{
	m_camera->GetImage(m_sourceFrame);
}

BinaryImage* Targeting::filterImage(ColorImage* inputImage)
{
	//This should threshold for the green that was on Ben's shirt that night (roughly green, tweak this before testing)
	BinaryImage* inputOne = inputImage->ThresholdHSL(0,360,0,30,0,30);
	BinaryImage* inputTwo = inputImage->ThresholdHSL(0,360,0,30,55,75);
	BinaryImage* result = inputImage->ThresholdHSL(0,0,0,0,0,0);
	imaqAdd(result->GetImaqImage(), inputOne->GetImaqImage(), inputTwo->GetImaqImage());
	return result;
}

void Targeting::runTargeting()
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

        m_cameraServer->SetImage(output->GetImaqImage());

        delete m_filteredFrame;
        delete output;

        Wait(0.005);
}

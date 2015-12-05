#include "Targeting.h"
#include "WPILib.h"
#include "Constants.h"
#include <cmath>

Targeting::Targeting()
{
	m_sourceFrame = new ColorImage(IMAQ_IMAGE_RGB);
	m_filteredFrame = 0;
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

bool Targeting::targetInRange(std::vector<ParticleAnalysisReport>* reports)
{
        double center = reports[0][0].center_mass_x;
        double screenCenter = CameraRes::x / 2;
        double tolerance = reports[0][0].boundingRect.width / 2;
        return std::abs(center - screenCenter) <= tolerance;
}

BinaryImage* Targeting::filterImage(ColorImage* inputImage)
{
	//This should threshold for the green that was on Ben's shirt that night (roughly green, tweak this before testing)
	return inputImage->ThresholdHSL(0,255,0,255,210,255);
}

void Targeting::runTargeting()
{
        //Update the source and filter the image each frame
        updateSource();

        if(m_filteredFrame){
        	delete m_filteredFrame;
        }
        m_filteredFrame = filterImage(m_sourceFrame);
        ColorImage* output = new ColorImage(IMAQ_IMAGE_U8);
        float gv = 255;
        PixelValue pv;
        pv.grayscale = gv;

        imaqMultiplyConstant(output->GetImaqImage(), m_filteredFrame->GetImaqImage(), pv);

    	std::vector<ParticleAnalysisReport>* reports = m_filteredFrame->GetOrderedParticleAnalysisReports();
        if(reports->size()){
        	//TODO: We really hope if we get a report there's gonna be at least one rectangle
			Rect rectangle = reports[0][0].boundingRect;

			imaqDrawShapeOnImage(
				  output->GetImaqImage(),
				  output->GetImaqImage(),
				  rectangle,
				  DrawMode::IMAQ_DRAW_VALUE,
				  ShapeMode::IMAQ_SHAPE_RECT,
				  255);

			m_cameraServer->SetImage(output->GetImaqImage());

			std::string out = "Target ";
			if(targetInRange(reports)){
				out += "Sighted";
			}
			else {
				out += "NOT Sighted";
			}
			SmartDashboard::PutString("DB/String 0", out);
        }

        delete output;

        Wait(0.01);
}

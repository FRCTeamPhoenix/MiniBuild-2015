#include "Targeting.h"

Targeting::Targeting(AxisCamera * camera)
{
	m_camera = camera;
	m_sourceFrame = new ColorImage(IMAQ_IMAGE_RGB);
}

void Targeting::updateSource()
{
	m_camera->GetImage(m_sourceFrame);
}

void Targeting::displaySource()
{
	updateSource();
	CameraServer::GetInstance()->SetImage(m_sourceFrame->GetImaqImage());
}

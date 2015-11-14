#include "Targeting.h"

Targeting::Targeting(AxisCamera * camera)
{
   m_camera = camera;
   m_frame = new ColorImage(IMAQ_IMAGE_RGB);
}



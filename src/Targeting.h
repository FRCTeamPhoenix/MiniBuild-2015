#ifndef SRC_TARGETING_H_
#define SRC_TARGETING_H_

class Targeting
{
public:
   Targeting(AxisCamera * camera);
private:
   ColorImage *m_frame;
   AxisCamera *m_camera;
   //m_camera->GetImage(frame);
   //CameraServer::GetInstance()->SetImage(frame->GetImaqImage());

};

#endif /* SRC_TARGETING_H_ */

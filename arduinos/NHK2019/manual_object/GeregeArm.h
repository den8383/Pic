#ifndef GeregeArm_H
#define GeregeArm_H

#include "Motor.h"

class GeregeArm{
  public:
  GeregeArm(int, int,int, int,float);
  void Grab();
  void Release();
  void Bend();
  void Stretch();
  void Stop();
  
  private:
  int m_pin1;
  int m_pin2;
  int m_JmotorPin1;
  int m_JmotorPin2;
  float m_mode = 0;
  float m_Jmode = 0;;
  Motor *GerMotor;
  Motor *Jmotor;
};

#endif

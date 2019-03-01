#ifndef GeregeArm_H
#define GeregeArm_H

#include "Motor.h"

class GeregeArm{
  public:
  GeregeArm(int, int,int);
  void Grab();
  void Release();
  void Stop();
  
  private:
  int m_pin1;
  int m_pin2;
  int m_mode;
  Motor *GerMotor;
};

#endif

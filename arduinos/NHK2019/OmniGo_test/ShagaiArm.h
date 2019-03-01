#ifndef ShagaiArm_H
#define ShagaiArm_H

#include"AIR.h"
#include"Motor.h"

class ShagaiArm{
  public:
  ShagaiArm(int,int, int, float);
  void Grab();
  void Release();
  void Bend();
  void Stretch();
  void Stop();
  
  
  private:
  int m_AirPin;
  int m_JmotorPin1;
  int m_JmotorPin2;
  float m_mode = 0;
  int OnRATIO = 2;
  int OffRATIO = 1;
  AIR *air;
  Motor *Jmotor;
  
};

#endif

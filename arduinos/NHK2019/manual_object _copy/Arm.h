#ifndef Arm_H
#define Arm_H

#include"AIR.h"
#include"Motor.h"

class Arm{
  public:
  Arm(int,int, int, int);
  void Grab();
  void Release();
  void Bend();
  void Stretch();
  void Stop();
  
  
  private:
  int m_AirPin;
  int m_JmotorPin1;
  int m_JmotorPin2;
  int m_mode = 0;
  AIR *air;
  Motor *Jmotor;
  
};

#endif

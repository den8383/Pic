#ifndef InjectionMachine_H
#define InjectionMachine_H

#include "Motor.h"

class InjectionMachine{
  public:
  InjectionMachine(int, int, float);
  void Inject();
  
  private:
  int m_pin1;
  int m_pin2;
  float m_mode;
  Motor *InjMotor;
};


#endif

#ifndef InjectionMachine_H
#define InjectionMachine_H

#include "Motor.h"

class InjectionMachine{
  public:
  InjectionMachine(int, int, int);
  void Inject();
  
  private:
  int m_pin1;
  int m_pin2;
  int m_mode;
  Motor *InjMotor;
};


#endif

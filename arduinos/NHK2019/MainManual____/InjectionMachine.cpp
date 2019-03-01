#include "Arduino.h"
#include "InjectionMachine.h"

#define onRATIO 1
#define offRATIO 2

InjectionMachine::InjectionMachine(int pin1, int pin2, float mode){
  m_pin1 = pin1;
  m_pin2 = pin2;
  m_mode = mode;
  InjMotor = new Motor(m_pin1, m_pin2, m_mode);
  
}

void InjectionMachine::Inject(){
  InjMotor->onF();
  delay(onRATIO);
  InjMotor->off();
  delay(offRATIO);
}


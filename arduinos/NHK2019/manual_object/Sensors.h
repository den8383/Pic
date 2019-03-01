#ifndef Sensors_H
#define Sensors_H

#include <ArduinoSTL.h>
#include "Tmp.h"
#include "CrSensor.h"



class Sensors{
  public:
  template<class...Args>
  Sensors(Args...args){
    tmp = new Tmp(args...);
    MakeSensor();
    m_val.resize(tmp->Size());
  }
  float Trace(int);
  std::vector<int> val;
  
  private:
  Tmp *tmp;
  std::vector<int> m_val;
  std::vector<CrSensor> crsen;
  void MakeSensor();
  float CalSum();
  //CrSensor crsen;
};

#endif

#ifndef DegSensor_H
#define DegSensor_H

#include <ArduinoSTL.h>
#include "CrSensor.h"



class DegSensor{
  public:
  DegSensor(int,int, ...);
  void trace();
  std::vector<int> val;
  
  private:
  float theta;
  int SenNum = 8;
  std::vector<int> m_val;
  //std::vector<CrSensor> crsen;
  CrSensor crsen[
};

#endif

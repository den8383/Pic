#include "Arduino.h"
#include "DegSensor.h"

DegSensor::DegSensor(int num,int pinNum, ...){
  SenNum = num;
  m_val.resize(SenNum);
  val.resize(SenNum);
  crsen.push_back(CrSensor(pinNum));
}


void DegSensor::trace(){
  val = m_val;
}


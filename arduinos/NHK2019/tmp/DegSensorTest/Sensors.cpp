#include "Arduino.h"
#include "Sensors.h"



float Sensors::Trace(int TraceHold){
  for(int i = 0; i < tmp->Size(); i++){
    m_val[i] = crsen[i].TraceA(TraceHold);
  }
  return CalSum();
}


void Sensors::MakeSensor(){ 
  for(int i = 0; i < tmp->Size(); i++){
    crsen.push_back(CrSensor(tmp->Arg[i]));
  }
}

float Sensors::CalSum(){
  int mult;
  int sum = 0;
  int POW = 1;
  int POWSum = 0;
  float NormalizedSum;
  for(int i = 0; i < tmp->Size(); i++){
    if(i != 0){
      POW *= 2;
    }
    POWSum += POW;
    mult = m_val[i]*POW;
    sum += mult;
  }
  NormalizedSum = sum/POWSum;
  return sum;
//  return NormalizedSum;
  
}



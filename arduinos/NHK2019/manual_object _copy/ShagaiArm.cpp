#include"Arduino.h"
#include"ShagaiArm.h"


ShagaiArm::ShagaiArm(int AirPin,int JmotorPin1,int JmotorPin2, float mode){
  m_AirPin = AirPin;
  m_JmotorPin1 = JmotorPin1;
  m_JmotorPin2 = JmotorPin2;
  m_mode = mode;
  air = new AIR(m_AirPin);
  Jmotor = new Motor(m_JmotorPin1,m_JmotorPin2,m_mode);
}

void ShagaiArm::Grab(){
  air->ONA();
}

void ShagaiArm::Release(){
  air->OFA();
}

void ShagaiArm::Bend(){
  if(m_mode == 0){
    Jmotor->onF();
    delay(OnRATIO);
    Jmotor->off();
    delay(OffRATIO);
  }else if(m_mode == 1){
    Jmotor->onF();
  }
}

void ShagaiArm::Stretch(){
  if(m_mode == 0){
    Jmotor->onR();
    delay(OnRATIO);
    Jmotor->off();
    delay(OffRATIO);
  }else if(m_mode == 1){
    Jmotor->onR();
  }
}

void ShagaiArm::Stop(){
  Jmotor->off();
}




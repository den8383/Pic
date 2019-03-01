#include"Arduino.h"
#include"Arm.h"

#define RATIO 0

Arm::Arm(int AirPin,int JmotorPin1,int JmotorPin2, int mode){
  m_AirPin = AirPin;
  m_JmotorPin1 = JmotorPin1;
  m_JmotorPin2 = JmotorPin2;
  m_mode = mode;
  air = new AIR(m_AirPin);
  Jmotor = new Motor(m_JmotorPin1,m_JmotorPin2,m_mode);
}

void Arm::Grab(){
  air->ONA();
}

void Arm::Release(){
  air->OFA();
}

void Arm::Bend(){
  if(m_mode == 0){
    Jmotor->onF();
    delay(0);
    Jmotor->off();
  }else if(m_mode == 1){
    Jmotor->onF();
  }
}

void Arm::Stretch(){
  if(m_mode == 0){
    Jmotor->onR();
    delay(0);
    Jmotor->off();
  }else if(m_mode == 1){
    Jmotor->onR();
  }
}

void Arm::Stop(){
  Jmotor->off();
}




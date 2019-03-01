#include "Arduino.h"
#include "GeregeArm.h"

#define OnRATIO 1
#define OnRATIOJ 1
#define OffRATIO 2
#define OffRATIOJ 2

GeregeArm::GeregeArm(int pin1, int pin2, int JmotorPin1,int JmotorPin2,float mode){
  m_pin1 = pin1;
  m_pin2 = pin2;
  m_JmotorPin1 = JmotorPin1;
  m_JmotorPin2 = JmotorPin2;
  m_mode = mode;
  GerMotor = new Motor(m_pin1, m_pin2, m_mode);
  Jmotor = new Motor(m_JmotorPin1,m_JmotorPin2,m_mode);
}

void GeregeArm::Grab(){
  if(m_mode == 0){
    GerMotor->onF();
    delay(OnRATIO);
    GerMotor->off();
    delay(OffRATIO);
  }else if(m_mode == 1){
    GerMotor->onF();
  }
}

void GeregeArm::Release(){
  if(m_mode == 0){
    GerMotor->onR();
    delay(OnRATIO);
    GerMotor->off();
    delay(OffRATIO);
  }else if(m_mode == 1){
    GerMotor->onR();
  }
}


void GeregeArm::Bend(){
  if(m_Jmode == 0){
    Jmotor->onF();
    delay(OnRATIOJ);
    Jmotor->off();
    delay(OffRATIOJ);
  }else if(m_Jmode == 1){
    Jmotor->onF();
  }
}

void GeregeArm::Stretch(){
  if(m_Jmode == 0){
    Jmotor->onR();
    delay(OnRATIOJ);
    Jmotor->off();
    delay(OffRATIOJ);
  }else if(m_Jmode == 1){
    Jmotor->onR();
  }
}

void GeregeArm::Stop(){
  GerMotor->off();
  Jmotor->off();
}


#include "Arduino.h"
#include "Mecanum.h"

Mecanum::Mecanum(int pin1A, int pin1B,int pin2A, int pin2B,int pin3A, int pin3B,int pin4A, int pin4B, float mode)
{
  m_pin1A=pin1A;
  m_pin1B=pin1B;
  m_pin2A=pin2A;
  m_pin2B=pin2B;
  m_pin3A=pin3A;
  m_pin3B=pin3B;
  m_pin4A=pin4A;
  m_pin4B=pin4B;
  m_mode=mode;
  motor1 = new Motor(m_pin1A,m_pin1B,m_mode);
  motor2 = new Motor(m_pin2A,m_pin2B,m_mode);
  motor3 = new Motor(m_pin3A,m_pin3B,m_mode);
  motor4 = new Motor(m_pin4A,m_pin4B,m_mode);
}

void Mecanum::Front(){
  motor1->onF();
  motor2->onF();
  motor3->onR();
  motor4->onR();
}

void Mecanum::FRight(){
  motor1->off();
  motor2->onF();
  motor3->off();
  motor4->onR();
  
}
void Mecanum::Right(){
  motor1->onR();
  motor2->onF();
  motor3->onF();
  motor4->onR();
  
}
void Mecanum::BRight(){
  motor1->onR();
  motor2->off();
  motor3->onF();
  motor4->off();
  
}
void Mecanum::Back(){
  motor1->onR();
  motor2->onR();
  motor3->onF();
  motor4->onF();
  
}
void Mecanum::BLeft(){
  motor1->off();
  motor2->onR();
  motor3->off();
  motor4->onF();
  
}
void Mecanum::Left(){
  motor1->onF();
  motor2->onR();
  motor3->onR();
  motor4->onF();
  
}
void Mecanum::FLeft(){
  motor1->onF();
  motor2->off();
  motor3->onR();
  motor4->off();
  
}

void Mecanum::TurnR(){
  motor1->onF();
  motor2->onF();
  motor3->onF();
  motor4->onF();
}
void Mecanum::TurnL(){
  motor1->onR();
  motor2->onR();
  motor3->onR();
  motor4->onR();
  
}
void Mecanum::DriftR(){
  motor1->onF();
  motor2->onF();
  motor3->onF();
  motor4->onR();
  
}
void Mecanum::DriftL(){
  motor1->onF();
  motor2->onR();
  motor3->onR();
  motor4->onR();
  
}

void Mecanum::Stop(){
  motor1->off();
  motor2->off();
  motor3->off();
  motor4->off();
  
}

void Mecanum::Print(){
  motor1->print();
  motor2->print();
  motor3->print();
  motor4->print();
}


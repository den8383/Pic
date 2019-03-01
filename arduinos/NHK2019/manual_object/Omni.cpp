#include "Arduino.h"
#include "Omni.h"

Omni::Omni(int pin1A, int pin1B,int pin2A, int pin2B,int pin3A, int pin3B,int pin4A, int pin4B, float mode)
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
  ChangeBrake(1.5);
  ChangeSpeed(200);
  ChangeInitialVelocityCrrection(1.5);
  ChangeInitialVelocity(100);
}

void Omni::Front(){
  motor1->onF();
  motor2->onF();
  motor3->onR();
  motor4->onR();
}

void Omni::FRight(){
  motor1->off();
  motor2->onF();
  motor3->off();
  motor4->onR();
  
}
void Omni::Right(){
  motor1->onR();
  motor2->onF();
  motor3->onF();
  motor4->onR();
  
}
void Omni::BRight(){
  motor1->onR();
  motor2->off();
  motor3->onF();
  motor4->off();
  
}
void Omni::Back(){
  motor1->onR();
  motor2->onR();
  motor3->onF();
  motor4->onF();
  
}
void Omni::BLeft(){
  motor1->off();
  motor2->onR();
  motor3->off();
  motor4->onF();
  
}
void Omni::Left(){
  motor1->onF();
  motor2->onR();
  motor3->onR();
  motor4->onF();
  
}
void Omni::FLeft(){
  motor1->onF();
  motor2->off();
  motor3->onR();
  motor4->off();
  
}

void Omni::TurnR(){
  motor1->onR();
  motor2->onR();
  motor3->onR();
  motor4->onR();
}
void Omni::TurnL(){
  motor1->onF();
  motor2->onF();
  motor3->onF();
  motor4->onF();
  
}
void Omni::DriftR(){
  motor1->onF();
  motor2->onF();
  motor3->onF();
  motor4->onR();
  
}
void Omni::DriftL(){
  motor1->onF();
  motor2->onR();
  motor3->onR();
  motor4->onR();
  
}

void Omni::Go(float power, float deg){
  motor1->onDeg(power,deg+45 - dirtheta);
  motor2->onDeg(power,deg-45 - dirtheta+180);
  motor3->onDeg(power,deg-135 - dirtheta);
  motor4->onDeg(power,deg+135 - dirtheta+180);
  if(power == 0){
    motor1->off();
    motor2->off();
    motor3->off();
    motor4->off();
  }
}

void Omni::Stop(){
  motor1->off();
  motor2->off();
  motor3->off();
  motor4->off();
  
}

void Omni::ChangeBrake(float correction){
  motor1->ChangeStoppingCorrection(correction);
  motor2->ChangeStoppingCorrection(correction);
  motor3->ChangeStoppingCorrection(correction);
  motor4->ChangeStoppingCorrection(correction);
}

void Omni::ChangeSpeed(float SpeedMax){
  motor1->ChangeSpeed(SpeedMax);
  motor2->ChangeSpeed(SpeedMax);
  motor3->ChangeSpeed(SpeedMax);
  motor4->ChangeSpeed(SpeedMax);
}

void Omni::ChangeInitialVelocityCrrection(float InitialVelocityCrrection){
  motor1->ChangeInitialVelocityCrrection(InitialVelocityCrrection);
  motor2->ChangeInitialVelocityCrrection(InitialVelocityCrrection);
  motor3->ChangeInitialVelocityCrrection(InitialVelocityCrrection);
  motor4->ChangeInitialVelocityCrrection(InitialVelocityCrrection);
  
}

void Omni::ChangeInitialVelocity(float InitialVelocity){
  motor1->ChangeInitialVelocity(InitialVelocity);
  motor2->ChangeInitialVelocity(InitialVelocity);
  motor3->ChangeInitialVelocity(InitialVelocity);
  motor4->ChangeInitialVelocity(InitialVelocity);
}

void Omni::Print(){
  motor1->print();
  motor2->print();
  motor3->print();
  motor4->print();
}


#include "Arduino.h"
#include "Encoder.h"

Encoder::Encoder(int pin1, int pin2){
  pinA = pin1;
  pinB = pin2;
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  encValue = 0;
  oldEncB = digitalRead(pinB);
  preTime = micros();
  dt = (micros() - preTime)/1000000;
}


void Encoder::Count(void){
  int newEncB = digitalRead(pinB);
  int newEncA = digitalRead(pinA);
   
  if (newEncA){
    if (oldEncB && !newEncB) { // up
      ++encValue;
    } else { // down
      --encValue;
    }
  } else {
    if (oldEncB && !newEncB) { // down
      --encValue;
    } else { // up
      ++encValue;
    }
  }
  oldEncB = newEncB;
  task();
}

void Encoder::task(){
  dt = (micros() - preTime)/1000000;
  old_encValue = encValue;
  preTime = micros();
}
int Encoder::Counter(){
  return encValue;
}

double Encoder::DT(){
  return dt;
}


int Encoder::velocity(){
  old_velocity = (encValue - old_encValue)/ dt;
  return old_velocity;
}

int Encoder::acceleration(){
  old_acceleration = (((encValue - old_encValue) - old_velocity)/ dt)/dt;
  return old_acceleration;
}


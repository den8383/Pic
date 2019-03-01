#include "Arduino.h"
#include "Controller.h"

Controller::Controller(int SSPIN){
  spicon = new SpiConM(SSPIN);
}

void Controller::Send(int order){
  spicon->sData = order;
  spicon->RS();
}

void Controller::Print(){
  Serial.print(F("Send:"));
  Serial.print(spicon->sData);
  Serial.print(F("Reply:"));
  Serial.print(spicon->sData);
}


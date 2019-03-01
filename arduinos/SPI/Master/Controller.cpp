#include "Arduino.h"
#include "Controller.h"

Controller::Controller(int board){
  spicon = new SpiConM(board);
  setUp();
}
void Controller::setUp(){
  spicon->setUp();
}

void Controller::End(){
  spicon->End();
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


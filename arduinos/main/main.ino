#include "Motor.h"
#include "Mecanum.h"
#include "PS3Con.h"

PS3Con PS3 = PS3Con();
Mecanum mecanum = Mecanum(13,12,9,6,5,4,3,2,1);

int Fpin = 31;
void smileFace();
void sadFace();

//
//
void setup() {
  PS3.Start();
}
void loop() {
  PS3.Task();
  if (PS3.PS3Connected()) {
    if (PS3.getButtonClick(PS)){//各ボタンの中にモーターを動かしたりトランジスタを動かしたりサーボを動かす処理をかいてください
      Serial.print(F("\r\nPS"));
    }
    else{
    }
    
    if (PS3.getButtonPress(TRIANGLE)){
      Serial.print(F("\r\nTraingle"));
    }
   else if (PS3.getButtonPress(CIRCLE)){
      Serial.print(F("\r\nCircle"));
    }
   else if (PS3.getButtonPress(CROSS)){
      Serial.print(F("\r\nCross"));
    }
    else if (PS3.getButtonPress(SQUARE)){
      Serial.print(F("\r\nSquare"));
    }
    else if (PS3.getButtonPress(UP)) {
      Serial.print(F("\r\nUp"));

    }
    else  if (PS3.getButtonPress(RIGHT)) {
      Serial.print(F("\r\nRight"));

    }
    else  if (PS3.getButtonPress(DOWN)) {
      Serial.print(F("\r\nDown"));
    }
    else  if (PS3.getButtonPress(LEFT)) {
      Serial.print(F("\r\nLeft"));

    }
    else if (PS3.getButtonPress(L1)){
      Serial.print(F("\r\nL1"));
      mecanum.TurnL();
      sadFace();
    }else if (PS3.getButtonPress(L2)) {
      Serial.print(F("\r\nL2"));
      mecanum.DriftL();
      sadFace();
    }
    else if (PS3.getButtonPress(L3)){
      Serial.print(F("\r\nL3"));
    }
    else if (PS3.getButtonPress(R1)){
      Serial.print(F("\r\nR1"));
      mecanum.TurnR();
      sadFace();
    }
    else if (PS3.getButtonPress(R2)){
      Serial.print(F("\r\nR2"));
      mecanum.DriftR();
      sadFace();
    }      
    else if (PS3.getButtonPress(R3)){
      Serial.print(F("\r\nR3"));
    }
    else if (PS3.getButtonPress(SELECT)) {
      Serial.print(F("\r\nSelect"));
    }
    else if (PS3.getButtonPress(START)) {
      Serial.print(F("\r\nStart"));
    }
    else{
      LeftAnalogPad(PS3.LeftAPad());
      Serial.print(F("\r"));
    }
  }
  
}





void LeftAnalogPad(int n){
  switch(n){
    case 6:
//          my_front();
          Serial.print(F("\r\nfront"));
          mecanum.Front();
          sadFace();
          break;
    case 5:
//          my_f_right();
          Serial.print(F("\r\nfront_right"));
          mecanum.FRight();
          sadFace();
          break;
    case 4:
//          my_right();
          Serial.print(F("\r\nright"));
          mecanum.Right();
          sadFace();
          break;
    case 3:
//          my_b_right();
          Serial.print(F("\r\nback_right"));
          mecanum.BRight();
          sadFace();
          break;
    case 2:
//          my_back();
          Serial.print(F("\r\nback"));
          mecanum.Back();
          sadFace();
          break;
    case 1:
//          my_b_left();
          Serial.print(F("\r\nback_left"));
          mecanum.BLeft();
          sadFace();
          break;
    case 8:
//          my_left();
          Serial.print(F("\r\nleft"));
          mecanum.Left();
          sadFace();
          break;
    case 7:
//          my_f_left();
          Serial.print(F("\r\nfront_left"));
          mecanum.FLeft();
          sadFace();
          break;
    case 0:
//          my_stop();
          Serial.print(F("\r\nstop"));
          mecanum.Stop();
          smileFace();
          break;
    default:
//          my_stop();
          Serial.print(F("\r\nstop"));
          mecanum.Stop();
          smileFace();
  }
  
//  Serial.print(F(":motor1{"));
//  motor1.print();
//  Serial.print(F("}motor2{"));
//  motor2.print();
//  Serial.print(F("}\r\n"));
}



void smileFace(){
  pinMode(Fpin,OUTPUT);
  digitalWrite(Fpin,LOW);
}
void sadFace(){
  pinMode(Fpin,OUTPUT);
  digitalWrite(Fpin,HIGH);
}



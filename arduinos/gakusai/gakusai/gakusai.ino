#include <PS3BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include "Motor.h"
#include "PS3Con.h"
#include "ServoM.h"
#include "Mecanum.h"
//
USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd);
PS3Con ps3con = PS3Con();
Motor motor2 = Motor(3,2,0);
Motor motor3 = Motor(30,31,0);
Motor motorUD = Motor(26,27,0);
Motor motorLR = Motor(28,29,0);
ServoM servo1 = ServoM(6,90);
//
void my_front();
void my_f_right();
void my_right();
void my_b_right();
void my_back();
void my_b_left();
void my_left();
void my_f_left();
void my_turn_left();
void my_turn_right();
void my_stop();
void my_up();
void my_LRRight();
void my_LRLeft();
void my_down();
void my_CP_front();
void my_CP_back();
void sweepRight();
void sweepLeft();
void my_left_analog_pad(int n);
//
void setup() {
  Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));

}
void loop() {
  Usb.Task();
  if (PS3.PS3Connected) {
    if (PS3.getButtonClick(PS)){//各ボタンの中にモーターを動かしたりトランジスタを動かしたりサーボを動かす処理をかいてください
      Serial.print(F("\r\nPS"));
    }
    else{
    }
    
    if (PS3.getButtonPress(TRIANGLE)){
      Serial.print(F("\r\nTraingle"));
      my_up();
    }
   else if (PS3.getButtonPress(CIRCLE)){
      Serial.print(F("\r\nCircle"));
      my_LRRight();
    }
   else if (PS3.getButtonPress(CROSS)){
      Serial.print(F("\r\nCross"));
      my_down();
    }
    else if (PS3.getButtonPress(SQUARE)){
      Serial.print(F("\r\nSquare"));
      my_LRLeft();
    }
    else if (PS3.getButtonPress(UP)) {
      Serial.print(F("\r\nUp"));

    }
    else  if (PS3.getButtonPress(RIGHT)) {
      Serial.print(F("\r\nRight"));
      sweepRight();

    }
    else  if (PS3.getButtonPress(DOWN)) {
      Serial.print(F("\r\nDown"));
    }
    else  if (PS3.getButtonPress(LEFT)) {
      Serial.print(F("\r\nLeft"));
      sweepLeft();

    }
    else if (PS3.getButtonPress(L1)){
      Serial.print(F("\r\nL1"));
      my_turn_left();
    }else if (PS3.getButtonPress(L2)) {
      Serial.print(F("\r\nL2"));
      my_CP_front();
      /*my_denjiben(denjiben_count[0],denjiben_pin[0]);
      if(denjiben_count >= 1){
        denjiben_count[0] = 0;
      }else
      {
        denjiben_count[0] = 1;
      }*/
    }
    else if (PS3.getButtonPress(L3)){
      Serial.print(F("\r\nL3"));
    }
    else if (PS3.getButtonPress(R1)){
      Serial.print(F("\r\nR1"));
      my_turn_right();
    }
    else if (PS3.getButtonPress(R2)){
      Serial.print(F("\r\nR2"));
      my_CP_back();
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
    my_left_analog_pad(ps3con.AnalogPadDirection(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY)));
    Serial.print(F("\r"));
    }
//    digitalWrite(motor_pin5[0],LOW);
//    digitalWrite(motor_pin5[1],LOW);
//  digitalWrite(motor_pin6[0],LOW);
//  digitalWrite(motor_pin6[1],LOW);
  }
  
}



void my_front(){
  motor1.onF();
  motor2.onR();
}

void my_f_right(){  
}

void my_right(){
  motor1.onR();
  motor2.onR();
}

void my_b_right(){
}

void my_back(){
  motor1.onR();
  motor2.onF();
}

void my_b_left(){
}

void my_left(){
  motor1.onF();
  motor2.onF();
}


void my_f_left(){
}

void my_stop(){
  motor1.off();
  motor2.off();
  motorUD.off();
  motorLR.off();
  motor3.off();
}

void my_turn_right(){
  motor1.onR();
  motor2.onR();
}

void my_turn_left(){
  motor1.onF();
  motor2.onF();
}

void my_up(){
  motorUD.onF();
  Serial.print(F("}motorUD{"));
  motorUD.print();
}

void my_LRRight(){
  motorLR.onF();
  Serial.print(F("}motorUD{"));
  motorLR.print();
}

void my_LRLeft(){
  motorLR.onR();
  Serial.print(F("}motorUD{"));
  motorLR.print();
}

void my_down(){
  motorUD.onR();
  Serial.print(F("}motorUD{"));
  motorUD.print();
}

void my_CP_front()
{
  motor3.onF();
  Serial.print(F("}motor3{"));
  motor3.print();
}

void my_CP_back()
{
  motor3.onR();
  Serial.print(F("}motor3{"));
  motor3.print();
}





void my_left_analog_pad(int n){
  switch(n){
    case 6:
          my_front();    
          Serial.print(F("\r\nfront"));
          break;
    case 5:
          my_f_right();
          Serial.print(F("\r\nfront_right"));
          break;
    case 4:
          my_right();
          Serial.print(F("\r\nright"));
          break;
    case 3:
          my_b_right();
          Serial.print(F("\r\nback_right"));
          break;
    case 2:
          my_back();
          Serial.print(F("\r\nback"));
          break;
    case 1:
          my_b_left();
          Serial.print(F("\r\nback_left"));
          break;
    case 8:
          my_left();
          Serial.print(F("\r\nleft"));
          break;
    case 7:
          my_f_left();
          Serial.print(F("\r\nfront_left"));
          break;
    case 0:
          my_stop();
          Serial.print(F("\r\nstop"));
          break;
    default:
          my_stop();
      Serial.print(F("\r\nstop1"));
  }
  
  Serial.print(F(":motor1{"));
  motor1.print();
  Serial.print(F("}motor2{"));
  motor2.print();
  Serial.print(F("}\r\n"));
}

void sweepRight()
{
      servo1.onF();
      servo1.print();
}

void sweepLeft()
{
      servo1.onR();
      servo1.print();
}





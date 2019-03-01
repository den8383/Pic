#include <PS3BT.h>
#include <usbhub.h>
#include "PS3Con.h"
#include "Motor.h"
#include "Omni.h"
#include "ShagaiArm.h"
#include "GeregeArm.h"
#include "InjectionMachine.h"

USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd);
PS3Con ps3con = PS3Con();
Omni omni = Omni(2,3,45,46,6,9,4,5,1.3);
ShagaiArm armS = ShagaiArm(31,32,33,0);
GeregeArm armG = GeregeArm(36,37,38,39,0);
InjectionMachine IM = InjectionMachine(40,41,0);

//
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
      armG.Bend();
    }
   else if (PS3.getButtonPress(CIRCLE)){
      Serial.print(F("\r\nCircle"));
      armG.Grab();
    }
   else if (PS3.getButtonPress(CROSS)){
      Serial.print(F("\r\nCross"));
      armG.Stretch();
    }
    else if (PS3.getButtonPress(SQUARE)){
      Serial.print(F("\r\nSquare"));
      armG.Release();
    }
    else if (PS3.getButtonPress(UP)) {
      Serial.print(F("\r\nUp"));
      armS.Bend();
    }
    else  if (PS3.getButtonPress(RIGHT)) {
      Serial.print(F("\r\nRight"));

    }
    else  if (PS3.getButtonPress(DOWN)) {
      Serial.print(F("\r\nDown"));
      armS.Stretch();
    }
    else  if (PS3.getButtonPress(LEFT)) {
      Serial.print(F("\r\nLeft"));

    }
    else if (PS3.getButtonPress(L1)){
      Serial.print(F("\r\nL1"));
      omni.TurnL();
      omni.Print();
    }else if (PS3.getButtonPress(L2)) {
      Serial.print(F("\r\nL2"));
    }
    else if (PS3.getButtonPress(L3)){
      Serial.print(F("\r\nL3"));
    }
    else if (PS3.getButtonPress(R1)){
      Serial.print(F("\r\nR1"));
      omni.TurnR();
      omni.Print();
    }
    else if (PS3.getButtonPress(R2)){
      Serial.print(F("\r\nR2"));
    }      
    else if (PS3.getButtonPress(R3)){
      Serial.print(F("\r\nR3"));
    }
    else if (PS3.getButtonPress(SELECT)) {
      Serial.print(F("\r\nSelect"));
    }
    else if (PS3.getButtonPress(START)) {
      Serial.print(F("\r\nStart"));
      IM.Inject();
    }
    else{
//    my_left_analog_pad(ps3con.AnalogPadDirection(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY)));
    omni.Go(ps3con.AnalogPadDistance(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY)),ps3con.AnalogPadAngle(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY)));
    omni.Print();
    Serial.println(F("\r"));
    }
  }
  
}





void my_left_analog_pad(int n){
  switch(n){
    case ps3con.AnaFront:
          Serial.print(F("\r\nfront"));
          omni.Front();
          break;
    case ps3con.AnaFRight:
          Serial.print(F("\r\nfront_right"));
          omni.FRight();
          break;
    case ps3con.AnaRight:
          Serial.print(F("\r\nright"));
          omni.Right();
          break;
    case ps3con.AnaBRight:
          Serial.print(F("\r\nback_right"));
          omni.BRight();
          break;
    case ps3con.AnaBack:
          Serial.print(F("\r\nback"));
          omni.Back();
          break;
    case ps3con.AnaBLeft:
          Serial.print(F("\r\nback_left"));
          omni.BLeft();
          break;
    case ps3con.AnaLeft:
          Serial.print(F("\r\nleft"));
          omni.Left();
          break;
    case ps3con.AnaFLeft:
          Serial.print(F("\r\nfront_left"));
          omni.FLeft();
          break;
    case ps3con.AnaNeutral:
          Serial.print(F("\r\nstop"));
          omni.Stop();
          break;
    default:
      Serial.print(F("\r\nstop1"));
  } 
}

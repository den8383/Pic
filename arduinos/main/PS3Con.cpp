#include "Arduino.h"
#include "PS3Con.h"

PS3Con::PS3Con()
{
  Usb = new USB;
  Btd = new BTD(Usb);
  PS3 = new PS3BT(Btd);
}

int PS3Con::Init(){
  return Usb->Init();
}

void PS3Con::Start(){
  
  Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  if (Usb->Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));

}

void PS3Con::Task(){
  Usb->Task();
}

int PS3Con::PS3Connected(){
  return PS3->PS3Connected;
}

int PS3Con::getButtonClick(int Button){
  return PS3->getButtonClick(Button);
}
int PS3Con::getButtonPress(int Button){
  return PS3->getButtonPress(Button);
}

double PS3Con::getAnalogHat(int Hat){
  return PS3->getAnalogHat(Hat);
}

int PS3Con::LeftAPad() {
  double deg, rad;
  double x = PS3->getAnalogHat(LeftHatX);
  double y = PS3->getAnalogHat(LeftHatY);
  int pattern = 0;
  x -= 128;
  y = abs(y - 256) - 128;
  rad = atan2((double)y, (double)x);
  deg = rad * 180.0 / (atan(1.0) * 4.0);
  if (abs(x) > 16 || abs(y) > 16)
  {
    pattern = 8;
    deg += 180.0;
    for ( int i = 0; i < 7; i++) {

      if ( deg >= 22.5 + (i * 45.0) && deg < 67.5 + (i * 45.0)) {
        pattern = i + 1;

      }
    }
    Serial.print( deg);
  }
  return pattern;
}
int PS3Con::RightAPad() {
  double deg, rad;
  double x = PS3->getAnalogHat(RightHatX);
  double y = PS3->getAnalogHat(RightHatY);
  int pattern = 0;
  x -= 128;
  y = abs(y - 256) - 128;
  rad = atan2((double)y, (double)x);
  deg = rad * 180.0 / (atan(1.0) * 4.0);
  if (abs(x) > 16 || abs(y) > 16)
  {
    pattern = 8;
    deg += 180.0;
    for ( int i = 0; i < 7; i++) {

      if ( deg >= 22.5 + (i * 45.0) && deg < 67.5 + (i * 45.0)) {
        pattern = i + 1;

      }
    }
    Serial.print( deg);
  }
  return pattern;
}

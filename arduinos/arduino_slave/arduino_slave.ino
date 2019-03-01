/*
arduinoPin-picPin
GND-5
11-7
12-8
13-10
5V-14
*/






#include "SpiConS.h"

SpiConS spicon1 = SpiConS();
void setup()
{
    Serial.begin(115200);
    delay(500);
    digitalWrite(10,HIGH);
}

byte i = 0;

void loop()
{
  spicon1.RS();
  spicon1.sData = spicon1.rData;
  spicon1.Print();
  Serial.println(F(":"));
  
  //spicon1.sData = 255;
  //spicon1.RS();
  //spicon1.Print();
  //Serial.print(F("\n"));

}

/*
arduinoPin-picPin
GND-5
11-7
12-8
13-10
5V-14
*/






#include "SpiConM.h"

SpiConM spicon1 = SpiConM();

void setup()
{
    Serial.begin(115200);
    delay(500);
    digitalWrite(10,HIGH);
}

byte i = 0;

void loop()
{
  spicon1.sData = i;
  spicon1.RS();
  spicon1.Print();
  Serial.println(F(":"));
  
  //spicon1.sData = 255;
  //spicon1.RS();
  //spicon1.Print();
  //Serial.print(F("\n"));
  i++;
  if(i > 255)
  {
    i = 0;
  }
  delay(20);

}

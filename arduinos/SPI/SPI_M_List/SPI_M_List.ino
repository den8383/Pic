/*
arduinoPin-picPin
GND-5
11-7
12-8
13-10
5V-14
*/


#include "Controller.h"
Controller con = Controller(10);


void setup()
{
    Serial.begin(115200);
    delay(500);
}


void loop()
{
  byte i = 0;
  con.Send(i);
  con.Print();
  Serial.println(F("\n"));
  i++;
  if(i > 255)
  {
    i = 0;
  }
  delay(20);

}

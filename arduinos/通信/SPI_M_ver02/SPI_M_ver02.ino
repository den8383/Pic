#include "SpiCon.h"

SpiCon spicon1 = SpiCon(10);

void setup()
{
    Serial.begin(9600);
    delay(500);
}

byte i = 00000000;

void loop()
{
  spicon1.sData = i;
  spicon1.RS();
  spicon1.Print();
  Serial.println(F("\r"));
  i++;
  if(i > 255)
  {
    i = 0;
  }
  delay(20);

}

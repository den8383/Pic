#include "SpiCon.h"

SpiCon spicon1 = SpiCon(10);

void setup()
{
    Serial.begin(9600);
    delay(500);
}


void loop()
{
  delay(100);
  spicon1.sData = 250;
  spicon1.RS();
  spicon1.Print();
  Serial.println(F("\r"));

}

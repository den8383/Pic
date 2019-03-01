#include "SpiCon.h"

SpiCon spicon1 = SpiCon();

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

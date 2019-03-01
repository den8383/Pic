#include "Sensors.h"
Sensors sen = Sensors(A0,A1,A2,A3,A4,A5);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(sen.Trace(1));
//Serial.println(pow(2,5));
  delay(300);

}

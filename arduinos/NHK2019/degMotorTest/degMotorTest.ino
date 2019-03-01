#include "Motor.h"
Motor motor = Motor(2,3,1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 360; i++){
    motor.onDeg(255,-i);
    motor.print();
    Serial.println(sin(-2*PI));
    delay(50);
  }
  Serial.println(F("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
  for(int i = 360; i > 0; i--){
    motor.onDeg(255,-i);
    motor.print();
    Serial.println();
    delay(50); 
  }
  Serial.println(F("ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ"));

}

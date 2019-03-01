#include "Motor.h"

Motor motor = Motor(11,10,0.01);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 256; i++){
    motor.onF();
    motor.print();
    delay(30);
  }
  delay(1000);
  for(int i = 0; i < 125; i++){
    motor.onR();
    motor.print();
    delay(30);
  }
  delay(1000);
  for(int i = 0; i < 256; i++){
    motor.off();
    motor.print();
    delay(30);
  }
  delay(1000);

}

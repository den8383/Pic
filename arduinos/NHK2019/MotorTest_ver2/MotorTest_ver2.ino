#include "Motor.h"

Motor motor1 = Motor(11,10,1);
Motor motor2 = Motor(6, 5, 1);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 256; i++){
    motor1.onF();
//    motor2.onF();
    motor1.print();
    Serial.println();
//    motor2.print();
//    Serial.println();
    delay(50);
  }
  
  for(int i = 0; i < 512; i++){
    motor1.onR();
//    motor2.onR();
    motor1.print();
    Serial.println();
//    motor2.print();
//    Serial.println();
    delay(50);
  }

}

#include <PS3BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include "Motor.h"
#include "PS3Con.h"
#include "ServoM.h"
//
USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd);
PS3Con ps3con = PS3Con();
Motor motor1 = Motor(13,12,1);
Motor motor2 = Motor(11,10,1);
Motor motor3 = Motor(5,4,1);
Motor motor4 = Motor(3,2,1);
void setup() {
  delay(3000);
  Serial.begin(115200);
}

void loop() {
  for(int i = 0; i < 255; i++){
    motor1.onR();
    motor2.onR();
    motor3.onF();
    motor4.onF();
    motor1.print();
    motor2.print();
    motor3.print();
    motor4.print();
    Serial.print(F("\r\n"));
    delay(10);
  }
}

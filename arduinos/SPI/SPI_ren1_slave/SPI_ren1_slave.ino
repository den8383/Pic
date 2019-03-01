/**********************************************
Arduino nano SPI(sleave)
**********************************************/
#include "SpiConS.h"
SpiConS spicon = SpiConS();
void setup() {
  spicon.setUp();
  Serial.print(F("Start\n"));
}
void loop() {
  spicon.task();
}

//    SPI割り込み
ISR(SPI_STC_vect){
  spicon.Inter();
}

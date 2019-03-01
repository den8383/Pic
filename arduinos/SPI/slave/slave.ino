
#include "SpiConS.h"
SpiConS spicon = SpiConS(0);
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

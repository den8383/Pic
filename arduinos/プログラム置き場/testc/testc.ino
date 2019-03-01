#include "LedController.h"
#include "Encoder.h"

LedController ledCont = LedController(13);
Encoder Enc = Encoder(3,2);
void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0,1,CHANGE);

}

void loop() {
  // put your main code here, to run repeatedly:
/*  ledCont.on();
  delay(500);
  ledCont.off();
  delay(500);
*/
}

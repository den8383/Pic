#include "InjectionMachine.h"

InjectionMachine IM = InjectionMachine(11,10, 0);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 255; i++){
    IM.Inject();
  }
  delay(1000);

}

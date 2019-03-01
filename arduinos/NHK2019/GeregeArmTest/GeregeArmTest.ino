#include "GeregeArm.h"

GeregeArm armG = GeregeArm(11,10,0);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    armG.Grab();
  delay(1000);
    armG.Release();
  delay(1000);
}

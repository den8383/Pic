#include"ShagaiArm.h"

ShagaiArm arm = ShagaiArm(13, 10, 11, 1);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
//  arm.Grab();
//  delay(1000);
//  arm.Release();
//  delay(1000);
  for(int i = 0; i < 255; i++){
    arm.Bend();
    delay(10);
  }
  for(int i = 0; i < 255; i++){
    arm.Stretch();
    delay(10);
  }
//  arm.Stop();
  delay(1000000);

//  delay(1000);
//  arm.Stretch();
//  delay(1000);
//  arm.Stop();
//  delay(1000);

}

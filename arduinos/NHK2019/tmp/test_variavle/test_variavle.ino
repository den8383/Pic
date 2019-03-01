
#include "Tmp.h"
//Sum K = Sum(1, 2, 3, 4, 5);
//Sum M = Sum(1);
Tmp W = Tmp(11,3,2,4,5,6,7,8,9,1);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(F("start"));
  delay(2000);

}

  int i= 0;
void loop() {
  // put your main code here, to run repeatedly:
//  Serial.println(K.v);
//  Serial.println(M.v);
  Serial.println(W.Arg[i]);
//  Serial.print(F("i:"));
//  Serial.println(W.i);
//  Serial.print(F("I:"));
//  Serial.println(i);
  i++;
  if(i > 9){
    i = 9;
  }
  delay(500);
}

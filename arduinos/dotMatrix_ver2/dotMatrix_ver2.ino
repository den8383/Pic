#include "dotMatrix.h"

dotMatrix dotM1 = dotMatrix(8);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
//  dotM1.inTurn(0.1);
//  dotM1.draw(0.1);
    if(analogRead(A5) < 514){
      dotM1.smileFace(0.01);
    }else{
      dotM1.sadFace(0.01);
    }
}

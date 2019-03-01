#include "Arduino.h"
#include "Encoder.h"

Encoder::Encoder(int pin1, int pin2)
{
  pinA = pin1;
  pinB = pin2;
  pinMode(pinA,INPUT);
  pinMode(pinB,INPUT); 
}

void Encoder::doCount(void)
{ 
  EncA = analogRead(pinA);
  EncB = analogRead(pinB);
  if (EncA){
    if (oldEncB && !EncB) { // up
      EncCount++;
    } else { // down
      EncCount--;
    }
  } else {
    if (oldEncB && !EncB) { // down
      EncCount--;
    } else { // up
      EncCount++;
    }
  }
  oldEncB = EncB;
}


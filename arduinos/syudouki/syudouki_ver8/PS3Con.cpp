#include "Arduino.h"
#include "PS3Con.h"

PS3Con::PS3Con()
{
  
}

int PS3Con::AnalogPadDirection( int x, int y) {//K_direction(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY))
  double deg, rad;
  int pattern = 0;
  x -= 128;
  y = abs(y - 256) - 128;
  rad = atan2((double)y, (double)x);
  deg = rad * 180.0 / (atan(1.0) * 4.0);
  if (abs(x) > 16 || abs(y) > 16)
  {
    pattern = 8;
    deg += 180.0;
    for ( int i = 0; i < 7; i++) {

      if ( deg >= 22.5 + (i * 45.0) && deg < 67.5 + (i * 45.0)) {
        pattern = i + 1;

      }
    }
    Serial.print( deg);
  }
  return pattern;
}

#ifndef Mecanum_H
#define Mecanum_H

#include "Motor.h"
#include "Arduino.h"



class Mecanum
{
  public:
  Mecanum();
  void Front();
  void Right();
  void Left();
  void Back();
  Motor motor1 = Motor(5,4,0);

  private:
  
};

#endif

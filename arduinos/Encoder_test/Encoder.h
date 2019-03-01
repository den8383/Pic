#ifndef Encoder_H
#define Encoder_H

class Encoder{
  public:
  Encoder(int ,int);
  void Count();
  void task();
  int Counter();
  double DT();
  int velocity();
  int acceleration();
  private:
  // A相ピン割り当て
  int pinA = 2;
  // B相ピン割り当て
  int pinB = 3;
  double dt = 0;
  double preTime = 0;
  double old_velocity = 0;
  double old_acceleration = 0;
  int old_encValue = 0;
 
  // B相の前回値
  volatile int oldEncB;
 
  // エンコーダ値
  volatile long encValue;
};


#endif

#ifndef Encoder_h
#define Encoder_h

class Encoder
{
  public:
  Encoder(int pin1,int pin2);
  void doCount(void);
  
  
  private:
  int pinA;
  int pinB;
  int EncA;
  volatile int oldEncA;
  int EncB;
  volatile int oldEncB;
  int EncCount;
  int EncOldcount;
};


#endif



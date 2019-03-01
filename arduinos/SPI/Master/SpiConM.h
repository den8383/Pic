#ifndef SpiConM_H
#define SpiConM_H

class SpiConM
{
  public:
  SpiConM(int );
  void setUp();
  void End();
  byte sData = 0;
  byte rData = 0;
  void RS();
  void Print();

  private:
  int m_board;
  int m_sendData = 0;
  int m_receiveData = 0;
  int SCK_PIN = 13;
  int MISO_PIN = 12;
  int MOSI_PIN = 11;
  int SSPIN = 10;
  
};

#endif

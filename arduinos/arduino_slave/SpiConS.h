#ifndef SpiConS_H
#define SpiConS_H


#define SS_PIN 10
#define SCK_PIN 13
#define MISO_PIN 12
#define MOSI_PIN 11

class SpiConS
{
  public:
  SpiConS(void);
  int sData = 0;
  int rData = 0;
  void RS();
  void Print();
  void Task();
  int spiFlag = 0;

  private:
  int m_sendData = 0;
  int m_receiveData = 0;
  int m_spiFlag = 0;
  
};

#endif

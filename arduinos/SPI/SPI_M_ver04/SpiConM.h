#ifndef SpiConM_H
#define SpiConM_H

class SpiConM
{
  public:
  SpiConM(void);
  byte sData = 0;
  byte rData = 0;
  void RS();
  void Print();

  private:
  int m_sendData = 0;
  int m_receiveData = 0;
  
};

#endif

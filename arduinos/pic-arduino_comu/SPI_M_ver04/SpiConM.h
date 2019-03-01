#ifndef SpiConM_H
#define SpiConM_H

class SpiConM
{
  public:
  SpiConM(void);
  int sData = 0;
  int rData = 0;
  void RS();
  void Print();

  private:
  int m_sendData = 0;
  int m_receiveData = 0;
  
};

#endif

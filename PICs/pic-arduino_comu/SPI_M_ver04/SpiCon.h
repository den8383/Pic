#ifndef SpiCon_H
#define SpiCon_H

class SpiCon
{
  public:
  SpiCon(void);
  int sData = 0;
  int rData = 0;
  void RS();
  void Print();

  private:
  int m_sendData = 0;
  int m_receiveData = 0;
  
};

#endif

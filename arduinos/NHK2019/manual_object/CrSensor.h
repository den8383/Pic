#ifndef CrSensor_h
#define CrSensor_h

class CrSensor
{
  public:
  CrSensor(int ReadPin);
  void TraceD();
  int TraceA(int TraceHold);
  void PrintA();
  void PrintD();

  private:
  int m_ReadPin;
  int m_mode;
  int m_TrValueD;
  int m_TrValueA;
};

#endif

#ifndef Controller_H
#define Controller_H

#include "SpiConM.h"

class Controller{
  public:
  Controller(int board);
  void setUp();
  void End();
  void Send(int order);
  void Print();
  private:
  SpiConM *spicon;
};

#endif

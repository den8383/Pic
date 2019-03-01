#ifndef Controller_H
#define Controller_H

#include "SpiConM.h"

class Controller{
  public:
  Controller::Controller(int SSPIN);
  void Send(int order);
  void Print();
  private:
  SpiConM *spicon;
};

#endif

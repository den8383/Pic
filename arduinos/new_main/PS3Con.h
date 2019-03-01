#ifndef PS3Con_h
#define PS3Con_h

#include <PS3BT.h>
#include <usbhub.h>

class PS3Con
{
  public:
  PS3Con(); 
  int Init();
  void Start();
  void Task();
  int PS3Connected();
  int getButtonClick(int Button);
  int getButtonPress(int Button);
  double getAnalogHat(int Hat);
  int LeftAPad();
  int RightAPad();
  private:
  USB *Usb;
  BTD *Btd;
  PS3BT *PS3;
};

#endif

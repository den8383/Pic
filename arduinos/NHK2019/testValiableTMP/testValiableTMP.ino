#include "Tmp.h"
class ValiTMP{
  public:
  template<class...Args> 
  ValiTMP(Args...args){
    tmp = new Tmp(args...);
  }
  printV(){
    Serial.print(F("size"));
    Serial.println(tmp->Size);
    Serial.print(F(":"));
    for(i = 0;  i < tmp->Size; i++){ 
      Serial.println(tmp->Arg[i]);
    }
  }
  private:
  int i = 0;
    Tmp *tmp;
};

ValiTMP vt = ValiTMP(1,2,3,4,5,6,7,8,9,0);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print(F("start"));
  delay(3000);

}

void loop() {
  // put your main code here, to run repeatedly:
  vt.printV();
  delay(50);

}

#ifndef Tmp_H
#define Tmp_H

#include <ArduinoSTL.h>


class Tmp {
  private:
  public:
  int Size = 0;
  std::vector<int> Arg;


  // コンストラクタ
  template<class... Args>
  Tmp(Args... args){
    
     tmp(args...);
  }
  
  template<class T>
  int tmp(T TMP) {
    Arg.push_back(TMP);
    Size++;
    return TMP; 
  }
  
  template<class T, class... Args>
  int tmp(T TMP, Args... args) {
    Arg.push_back(TMP);
    Size++;
    return tmp(args...);
  }
  
};


#endif

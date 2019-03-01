#ifndef Tmp_H
#define Tmp_H

#include <ArduinoSTL.h>


class Tmp {
  private:
  int num_i = 0;
  public:
  std::vector<int> Arg;


  // コンストラクタ
  template<class... Args>
  Tmp(Args... args){
    
     tmp(args...);
  }
  
  template<class T>
  int tmp(T TMP) {
    Arg.push_back(TMP);
    return TMP; 
  }
  
  template<class T, class... Args>
  int tmp(T TMP, Args... args) {
    Arg.push_back(TMP);
    return tmp(args...);
  }
  
};


#endif

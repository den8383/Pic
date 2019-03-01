
  template<class T>
  static int iniO(T t){
    pinMode(t, OUTPUT);
    digitalWrite(t, HIGH);
    return t;
  }

  template<class T, class... Args>
  static int iniO(T t, Args... args){
    pinMode(t, OUTPUT);
    digitalWrite(t, HIGH);
    return iniO(args...);
  }




void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

#define PIN_NUMBER 6
#define TR_NUMBER 4 
#define L_NUMBER 4
int pin[PIN_NUMBER] = { 22, 23, 11, 24, 25, 10};
int trPin[TR_NUMBER] = { A0, A1, A2, A3};
int Lpin[L_NUMBER] = { 30, 31, 32, 33};
int PID = 0;
const Kp
const Ki
const Kd
int pwm1 = 0;
int pwm2 = 0;
int trace[TR_NUMBER] = { 0, 0, 0, 0};
int old_trace[TR_NUMBER] = { 0, 0, 0, 0};
int e[3] = { 0, 0, 0];
void reading( int n){
  for( int i; i < n; i++){
    trace[i] = analogRead(trPin[i]);
  }
}
void motor1(int n, int m){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(pin[0],HIGH);
    digitalWrite(pin[1],LOW);
    analogWrite(pin[2],m);
  }
  else if(n<0){
    digitalWrite(pin[0],LOW);
    digitalWrite(pin[1],HIGH);
    analogWrite(pin[2],m);
  }
  else{
    digitalWrite(pin[0],LOW);
    digitalWrite(pin[1],LOW);
    analogWrite(pin[2],m);
  }
}


void motor2(int n, int m){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(pin[3],HIGH);
    digitalWrite(pin[4],LOW);
    analogWrite(pin[5],m);
  }
  else if(n<0){
    digitalWrite(pin[3],LOW);
    digitalWrite(pin[4],HIGH);
    analogWrite(pin[5],m);
  }
  else{
    digitalWrite(pin[3],LOW);
    digitalWrite(pin[4],LOW);
    analogWrite(pin[5],m);
  }
}



void setup() {
  for( int i; i < PIN_NUMBER; i++){
    pinMode(pin[i],OUTPUT);
  }
  for( int j; j < TR_NUMBER; j++){
    pinMode(trPin[j],INPUT);
    pinMode(L_pin[j],OUTPUT);
  }
}

void loop() {
  reading(TR_NUMBER);
  PID = (-2)*trace[0]+(-1)*trace[1]+(1)*trace[2]+(2)*trace[3];
  if(PID > 255){
    PID = 255;
  }else if(PID < 0){
    PID = 0;
  }
  
  pwm1 = Kp*()+Ki*e[2]+Kd((e[2]-e[1]-(e[1]-e[0]));
  pwm2
}

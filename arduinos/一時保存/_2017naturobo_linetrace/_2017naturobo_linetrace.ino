#define PIN_NUMBER 12
int pin[PIN_NUMBER] = { 22, 23, 11, 24, 25, 10, 26, 27, 9, 28, 29, 6};
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


void motor3(int n,int m){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(pin[6],HIGH);
    digitalWrite(pin[7],LOW);
    analogWrite(pin[8],m);
  }
  else if(n<0){
    digitalWrite(pin[6],LOW);
    digitalWrite(pin[7],HIGH);
    analogWrite(pin[8],m);
  }
  else{
    digitalWrite(pin[6],LOW);
    digitalWrite(pin[7],LOW);
    analogWrite(pin[8],m);
  }
}


void motor4(int n, int m){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(pin[9],HIGH);
    digitalWrite(pin[10],LOW);
    analogWrite(pin[11],m);
  }
  else if(n<0){
    digitalWrite(pin[9],LOW);
    digitalWrite(pin[10],HIGH);
    analogWrite(pin[11],m);
  }
  else{
    digitalWrite(pin[9],LOW);
    digitalWrite(pin[10],LOW);
    analogWrite(pin[11],m);
  }
}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

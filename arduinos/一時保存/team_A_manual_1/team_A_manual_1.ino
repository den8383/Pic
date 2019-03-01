//＊いじるところ１
#define p1 20
#define p2 21
#define p2 23
#define p3 24
#define p4 25
#define p5 26
#define p6 27
#define p7 28
#define p8 29
#define p9 30
#define p10 31
#define p11 32
#define p12 33
#define p13 34
#define p14 35
#define p15 36
#define DENJIBENPIN 9
//ここまで１
int mod_val = 0;
int pad_x;
int pad_y;
int denjiben_count;

int my_direction(int x, int y){
  double deg, rad;
  int pattern = 0;
  x -= 128;
  y = abs(y - 256) - 128;
  rad = atan2((double)y,(double)x);
  deg = rad * 180.0 / (atan(1.0)*4.0);
  if(abs(x) > 16 || abs(y) > 16)
  {
    pattern = 8;
    deg += 180.0;
    for(int i = 0; i < 7; i++){
      
      if(deg >= 22.5 + (i * 45.0) && deg < 67.5 + (i * 45.0)){
        pattern = i + 1;
           
      }
    }
    Serial.print(deg);
  }
  return pattern;
}

int my_mod(int n){//ただいちいちうつのがめんどかったため。
  if(n > 0){
    mod_val++;
  }else if(n<0){
    mod_val--;
  }else{
    mod_val = 0;
  }
  return mod_val;
}

void motor1(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(p1,HIGH);
    digitalWrite(p2,LOW);
    analogWrite(p3,my_mod(1));
  }
  else if(n<0){
    digitalWrite(p1,LOW);
    digitalWrite(p2,HIGH);
    analogWrite(p3,my_mod(1));
  }
  else{
    digitalWrite(p1,LOW);
    digitalWrite(p2,LOW);
    analogWrite(p3,my_mod(0));
  }
}

void motor2(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(p4,HIGH);
    digitalWrite(p5,LOW);
    analogWrite(p6,my_mod(1));
  }
  else if(n<0){
    digitalWrite(p4,LOW);
    digitalWrite(p5,HIGH);
    analogWrite(p6,my_mod(1));
  }
  else{
    digitalWrite(p4,LOW);
    digitalWrite(p5,LOW);
    analogWrite(p6,my_mod(0));
  }
}

void motor3(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(p7,HIGH);
    digitalWrite(p8,LOW);
    analogWrite(p9,my_mod(1));
  }
  else if(n<0){
    digitalWrite(p7,LOW);
    digitalWrite(p8,HIGH);
    analogWrite(p9,my_mod(1));
  }
  else{
    digitalWrite(p7,LOW);
    digitalWrite(p8,LOW);
    analogWrite(p9,my_mod(0));
  }
}

void motor4(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(p10,HIGH);
    digitalWrite(p11,LOW);
    analogWrite(p12,my_mod(1));
  }
  else if(n<0){
    digitalWrite(p10,LOW);
    digitalWrite(p11,HIGH);
    analogWrite(p12,my_mod(1));
  }
  else{
    digitalWrite(p10,LOW);
    digitalWrite(p11,LOW);
    analogWrite(p12,my_mod(0));
    }
}

void motor5(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(p13,HIGH);
    digitalWrite(p14,LOW);
    analogWrite(p15,my_mod(1));
  }
  else if(n<0){
    digitalWrite(p13,LOW);
    digitalWrite(p14,HIGH);
    analogWrite(p15,my_mod(1));
  }
  else{
    digitalWrite(p13,LOW);
    digitalWrite(p14,LOW);
    analogWrite(p15,my_mod(0));
    }
}

void my_right(){
  motor1(1);
  motor2(1);
  motor3(-1);
  motor4(-1);
}

void my_upper_right(){
  motor1(0);
  motor2(1);
  motor3(0);
  motor4(-1);
}

void my_front(){
  motor1(-1);
  motor2(1);
  motor3(1);
  motor4(-1);
}


void my_upper_left(){
  motor1(-1);
  motor2(0);
  motor3(1);
  motor4(0);
}

void my_left(){
  motor1(-1);
  motor2(-1);
  motor3(1);
  motor4(1);
}

void my_lower_left(){
  motor1(0);
  motor2(-1);
  motor3(0);
  motor4(1);
}

void my_back(){
  motor1(1);
  motor2(-1);
  motor3(-1);
  motor4(1);
}

void my_lower_right(){
  motor1(1);
  motor2(0);
  motor3(-1);
  motor4(0);
}

void my_turn_right(){
  motor1(1);
  motor2(1);
  motor3(1);
  motor4(1);
}

void my_turn_left(){
  motor1(-1);
  motor2(-1);
  motor3(-1);
  motor4(-1);
}

void my_steer_right_F(){
  motor1(1);
  motor2(1);
  motor3(0);
  motor4(0);
}

void my_steer_right_B(){
  motor1(0);
  motor2(0);
  motor3(-1);
  motor4(-1);
}

void my_steer_left_F(){
  motor1(-1);
  motor2(-1);
  motor3(0);
  motor4(0);
}

void my_steer_left_B(){
  motor1(0);
  motor2(0);
  motor3(1);
  motor4(1);
}

void  my_stop(){
  motor1(0);
  motor2(0);
  motor3(0);
  motor4(0);
}

void my_left_analog_pad(int n){
  switch(n){
    case 6:
          my_front();
          Serial.print(F("\r\nfront"));
          break;
    case 5:
          my_upper_right();
          Serial.print(F("\r\nupper_right"));
          break;
    case 4:
          my_right();
          Serial.print(F("\r\nright"));
          break;
    case 3:
          my_lower_right();
          Serial.print(F("\r\nlower_right"));
          break;
    case 2:
          my_back();
          Serial.print(F("\r\nback"));
          break;
    case 1:
          my_lower_left();
          Serial.print(F("\r\nlower_left"));
          break;
    case 8:
          my_left();
          Serial.print(F("\r\nleft"));
          break;
    case 7:
          my_upper_left();
          Serial.print(F("\r\nupper_right"));
          break;
    case 0:
          my_stop();
          Serial.print(F("\r\nstop"));
          break;
    default:
      my_stop();
      Serial.print(F("\r\nstop"));
  }
}

void my_up_down(int n){
  if(n > 0){
    motor5(1);
  }else if(n < 0){
    motor5(-1);
  }else{
    motor5(0);
  }
}

//ps3コントローラーを扱うための準備　弄らなくてよい
#include <PS3BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif

USB Usb;

BTD Btd(&Usb);
PS3BT PS3(&Btd);

boolean printTemperature;
boolean printAngle;










void setup() {//ここから
  Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
  //ここまではいじらないで良い

  //IOピンの設定　ピン番号を変えたり増やしたりしてください
  pinMode(p1,OUTPUT);//モーター１
  pinMode(p2,OUTPUT);
  pinMode(p3,OUTPUT);
  pinMode(p4,OUTPUT);//モーター２
  pinMode(p5,OUTPUT);
  pinMode(p6,OUTPUT);
  pinMode(p7,OUTPUT);//モーター３
  pinMode(p8,OUTPUT);
  pinMode(p9,OUTPUT);
  pinMode(p10,OUTPUT);//モーター４
  pinMode(p11,OUTPUT);
  pinMode(p12,OUTPUT);
  pinMode(p13,OUTPUT);//モーター５
  pinMode(p14,OUTPUT);
  pinMode(p15,OUTPUT);
  //
}
void loop() {
  Usb.Task();
  if (PS3.PS3Connected) {
    my_left_analog_pad(my_direction(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY)));
    if (PS3.getButtonClick(PS)){//各ボタンの中にモーターを動かしたりトランジスタを動かしたりサーボを動かす処理をかいてください
      Serial.print(F("\r\nPS"));
    }
    else{
    }
    if (PS3.getButtonPress(TRIANGLE)){
      Serial.print(F("\r\nTraingle"));
    }
   else if (PS3.getButtonPress(CIRCLE)){
      Serial.print(F("\r\nCircle"));
      my_up_down(1);
    }
   else if (PS3.getButtonPress(CROSS)){
      Serial.print(F("\r\nCross"));
      my_up_down(-1);
    }
    else{
    }
    if (PS3.getButtonPress(SQUARE)){
      Serial.print(F("\r\nSquare"));
    }
    else{
    }

    if (PS3.getButtonPress(UP)) {
      Serial.print(F("\r\nUp"));

    }
    else  if (PS3.getButtonPress(RIGHT)) {
      Serial.print(F("\r\nRight"));

    }
    else  if (PS3.getButtonPress(DOWN)) {
      Serial.print(F("\r\nDown"));

    }
    else  if (PS3.getButtonPress(LEFT)) {
      Serial.print(F("\r\nLeft"));

    }
    else{

      
    }   
    if (PS3.getButtonPress(L1)){
      Serial.print(F("\r\nL1"));
    }
    else{
    }
    if (PS3.getButtonPress(L2)) {
      Serial.print(F("\r\nL2"));
      my_turn_left();
    }
    else{
    }
    if (PS3.getButtonPress(L3)){
      Serial.print(F("\r\nL3"));
    }
    else{
    }
    if (PS3.getButtonPress(R1)){
      Serial.print(F("\r\nR1"));
      if(denjiben_count == 1){
        digitalWrite(DENJIBENPIN,HIGH);        
        Serial.print(F("open"));
        denjiben_count--;
      }else if(denjiben_count == 0){
        digitalWrite(DENJIBENPIN,LOW);        
        Serial.print(F("close"));
        denjiben_count++;
      }      
    }
    else{
    }
    if (PS3.getButtonPress(R2)){
      Serial.print(F("\r\nR2"));
      my_turn_right();
    }
    else{
    }
    if (PS3.getButtonPress(R3)){
      Serial.print(F("\r\nR3"));
    }
    else{
    }

    if (PS3.getButtonPress(SELECT)) {
      Serial.print(F("\r\nSelect"));
    }
    else{
    }
    if (PS3.getButtonPress(START)) {
      Serial.print(F("\r\nStart"));
    }
    else{
    }
  }
}






/*
void motor1(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  int val = min(val,255);
  if(n>0){
    digitalWrite(,HIGH);
    digitalWrite(,LOW);
    analogWrite(,my_mod(1));
  }
  else if(n<0){
    digitalWrite(,LOW);
    digitalWrite(,HIGH);
    analogWrite(,my_mod(1));
  }
  else{
    digitalWrite(,LOW);
    digitalWrite(,LOW);
    analogWrite(,my_mod(-1););
  }
}
*/


/*
void motor1(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(,HIGH);
    digitalWrite(,LOW);
    analogWrite(,255);
  }
  else if(n<0){
    digitalWrite(,LOW);
    digitalWrite(,HIGH);
    analogWrite(,255);
  }
  else{
    digitalWrite(,LOW);
    digitalWrite(,LOW);
    analogWrite(,0);
  }
}
*/

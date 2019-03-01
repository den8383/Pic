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
 /* pinMode(2,OUTPUT);//モーター１
  pinMode(20,OUTPUT);
  pinMode(21,OUTPUT);
  pinMode(3,OUTPUT);//モーター２
  pinMode(24,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(4,OUTPUT);//モーター３
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
  pinMode(5,OUTPUT);//モーター４
  pinMode(32,OUTPUT);
  pinMode(33,OUTPUT);
  pinMode(6,OUTPUT);//モーター５
  pinMode(36,OUTPUT);
  pinMode(37,OUTPUT);*/
  //
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
}
void loop() {
  Usb.Task();
  if (PS3.PS3Connected) {
    if (PS3.getButtonClick(PS)){//各ボタンの中にモーターを動かしたりトランジスタを動かしたりサーボを動かす処理をかいてください
      Serial.print(F("\r\nPS"));
    }
    else{
    }
    if (PS3.getButtonPress(TRIANGLE)){
      Serial.print(F("\r\nTraingle"));
    }
   else if (PS3.getButtonPress(CIRCLE)){
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      Serial.print(F("\r\nCircle"));
    }
   else if (PS3.getButtonPress(CROSS)){
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
      Serial.print(F("\r\nCross"));
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
    }
    else{
    }
    if (PS3.getButtonPress(R2)){
      Serial.print(F("\r\nR2"));
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

void motor1(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    analogWrite(2,255);
    digitalWrite(20,HIGH);
    digitalWrite(21,LOW);
  }
  else if(n<0){
    analogWrite(2,255);
    digitalWrite(20,LOW);
    digitalWrite(21,HIGH);
  }
  else{
    analogWrite(2,0);
    digitalWrite(20,LOW);
    digitalWrite(21,LOW);
  }
}
void motor2(int n){
  if(n>0){
    analogWrite(3,255);
    digitalWrite(24,HIGH);
    digitalWrite(25,LOW);
  }
  else if(n<0){
    analogWrite(3,255);
    digitalWrite(24,LOW);
    digitalWrite(25,HIGH);
  }
  else{
    analogWrite(3,0);
    digitalWrite(24,LOW);
    digitalWrite(25,LOW);
  }
}
void motor3(int n){
  if(n>0){
    analogWrite(4,255);
    digitalWrite(28,HIGH);
    digitalWrite(29,LOW);
  }
  else if(n<0){
    analogWrite(4,255);
    digitalWrite(28,LOW);
    digitalWrite(29,HIGH);
  }
  else{
    analogWrite(4,0);
    digitalWrite(28,LOW);
    digitalWrite(29,LOW);
  }  
}
void motor4(int n){
  if(n>0){
    analogWrite(5,255);
    digitalWrite(32,HIGH);
    digitalWrite(33,LOW);
  }
  else if(n<0){
    analogWrite(5,255);
    digitalWrite(32,LOW);
    digitalWrite(33,HIGH);
  }
  else{
    analogWrite(5,0);
    digitalWrite(32,LOW);
    digitalWrite(33,LOW);
  }
}





#define tm 10 //右、左に動かすのにPWMが使えないためdelayを使って比率を調整したいのでここは変えやすい用にここに置きました。
#include<PS3BT.h>
#include<usbhub.h>
#ifdef dobougusinclude
#include<spi4teensy3.h>
#endif
#include<Servo.h>

USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd); 
boolean printTemperture;
boolean printAngle;
Servo myservo;//サーボを使うため
int potpin = 0;
int val;

void motor1(int n){
  if(n > 0){
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
  }else if(n < 0){ 
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
  }else{
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
  }
}
void motor2(int n){
  if(n > 0){
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
  }else if(n < 0){
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
  }else{ 
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
}
void motor3(int n){
  if(n > 0){
    digitalWrite(9,HIGH);
    digitalWrite(8,LOW);
  }else if(n < 0){
    digitalWrite(9,LOW);
    digitalWrite(8,HIGH);
  }else{
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }  
}
void motor4(int n){
  if(n > 0){
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
  }else if(n < 0){
    digitalWrite(7,LOW);
    digitalWrite(6,HIGH);
  }else{
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
  }
}

int count = 1;//電磁弁をボタン一つで使うために用意しました

void setup(){
  Serial.begin(115200);
  while(!Serial);
  if (Usb.Init() == -1){
    Serial.print(F("\r\nOSC did not start"));
    while(1);
  }
   Serial.print(F("\r\nPS3 Bluetooth Library Started"));
   //arduinoの右上から順番に割り振りました　　
   pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   pinMode(11,OUTPUT);
   pinMode(10,OUTPUT);
   pinMode(9,OUTPUT);
   pinMode(8,OUTPUT);
   pinMode(7,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(5,OUTPUT);
   pinMode(4,OUTPUT);
   /*
   for(int i = 13;i > 5;i--){
     pinMode(i,OUTPUT);  
   }*/

   myservo.attach(4); 
}

void loop(){
  Usb.Task();
  if (PS3.PS3Connected){
    if (PS3.getButtonClick(PS)){
      Serial.print(F("\r\nPS"));
    }
    
    if (PS3.getButtonPress(TRIANGLE)){
      motor4(1);
      Serial.print(F("\r\nTraingle"));
    }
    else if(PS3.getButtonPress(CIRCLE)){//motor4で持ちあげます
      motor4(-1);
      Serial.print(F("\r\nCircle"));
    }else{
      motor4(0);
    }
    
    if(PS3.getButtonPress(CROSS)){//サーボの角度を減らします
      myservo.write(val);
      val = map(val, 0, 1023, 0, 180);
      val--;
      
      Serial.print(F("\r\nCross"));
    }
    if(PS3.getButtonPress(SQUARE)){//サーボの角度を増やします
      myservo.write(val);
      val = map(val, 0, 1023, 0, 180);
      val++;
      
      Serial.print(F("\r\nSquare"));
    }
    if (PS3.getButtonPress(UP) && PS3.getButtonPress(RIGHT)){//motor1を正転motor3を後転させて右上に進みます
      motor1(1);
      motor2(0);
      motor3(-1);
      Serial.print(F("\r\nupper right diagonal"));
    }
    else if (PS3.getButtonPress(RIGHT) && PS3.getButtonPress(DOWN)){//motor2を正転motor3を後転させて右下に進みます
      motor1(0);
      motor2(1);
      motor3(-1);
      Serial.print(F("\r\nlower right diagonal"));
    }
    else if(PS3.getButtonPress(DOWN) && PS3.getButtonPress(LEFT)){//motor1後転motor3を正転させて左下に進みます
      motor1(-1);
      motor2(0);
      motor3(1);
      Serial.print(F("\r\nlower left diagonal"));
    }
    else if (PS3.getButtonPress(LEFT) && PS3.getButtonPress(UP)){//motor2を後転motor3を正転させて左上に進みます
      motor1(0);
      motor2(-1);
      motor3(1);
      Serial.print(F("\r\nupper left diagonal"));
    }
    else if(PS3.getButtonPress(UP)) {//motor1正転とmotor2後転をさせて前に進みます。同時に動かしたいので押している間はdelayは挟みません
      motor1(1);
      motor2(-1);
      motor3(0);
      Serial.print(F("\r\nUp"));
      delay(10);
    }
    else if(PS3.getButtonPress(RIGHT)) {//motor3を後転motor2正転させて右に進みます。delayでmotor3の駆動時間を少しだけ増やしています
      motor1(0);
      motor2(1);
      motor3(-1);
      delay(tm);
      Serial.print(F("\r\nRight"));
    }
    else  if (PS3.getButtonPress(DOWN)) {//motor１を後転motor2を正転させて下に進みます
      motor1(-1);
      motor2(1);
      motor3(0);
      Serial.print(F("\r\nDown"));
      delay(10);
    }
    else if(PS3.getButtonPress(LEFT)) {//motor3を正転motor1を後転させて左に進みます。delayでmotor3の駆動時間を少しだけ増やしています
     motor1(-1);
     motor3(1);
     delay(tm);
      Serial.print(F("\r\nLeft"));
    }/*else{
      motor1(0);
      motor2(0);
      motor3(0);
      //motor4(0);
    }*/
    else if (PS3.getButtonPress(L1)){//motor1,motor2,motor3,をそれぞれ後転させて左旋回
      motor1(-1);
      motor2(-1);
      motor3(-1);
      Serial.print(F("\r\nL1"));
    }else if (PS3.getButtonPress(L2)) {
      Serial.print(F("\r\nL2"));
    }else if (PS3.getButtonPress(L3)){
      Serial.print(F("\r\nL3"));
    }else if (PS3.getButtonPress(R1)){//motor1,motor2,motor3,をそれぞれ正転させて右旋回
      motor1(1);
      motor2(1);
      motor3(1);
      Serial.print(F("\r\nR1"));
    }else if (PS3.getButtonPress(R3)){
      Serial.print(F("\r\nR3"));
    }else if (PS3.getButtonPress(SELECT)) {
      Serial.print(F("\r\nSelect"));
    }else if (PS3.getButtonPress(START)) {
      Serial.print(F("\r\nStart"));
    }else{
      motor1(0);
      motor2(0);
      motor3(0);
    }
    if (PS3.getButtonPress(R2)){//電磁弁操作用。countの値でHIGH,LOWを切り替えます
      if(count == 1){
        digitalWrite(5,HIGH);
        count--;
      }else if(count == 0){
        digitalWrite(5,LOW);
        count++;
      }
      Serial.print(F("\r\nR2"));
    }
  }
}




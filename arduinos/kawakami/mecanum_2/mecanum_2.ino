#include <kadai_robo.h>



//ps3コントローラーを扱うための準備　弄らなくてよい
#include <PS3BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <Servo.h>

USB Usb;

BTD Btd(&Usb);
PS3BT PS3(&Btd);

boolean printTemperature;
boolean printAngle;

#define MOTOR_NUMBER 2
#define PWM_NUMBER 4
int motor_pin1[MOTOR_NUMBER] = { 13, 12};
int motor_pin2[MOTOR_NUMBER] = { 9, 8};
int motor_pin3[MOTOR_NUMBER] = { 5, 4};
int motor_pin4[MOTOR_NUMBER] = { 3,2};
int pwm[PWM_NUMBER]= { 0, 0, 0, 0};
Servo my_servo;

int servo_pin = 6;
int angle[1] = { 0};

void my_front();
void my_f_right();
void my_right();
void my_b_right();
void my_back();
void my_b_left();
void my_left();
void my_f_left();
void my_turn_left();
void my_turn_right();
void my_stop();
void my_brake();
void all_motor();
void my_left_analog_pad(int n);
void my_Servo(Servo my_servo, int* angle);


void setup() {//ここから
  Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
  //ここまではいじらないで良い

  set_output(MOTOR_NUMBER,motor_pin1);
  set_output(MOTOR_NUMBER,motor_pin2);
  set_output(MOTOR_NUMBER,motor_pin3);
  set_output(MOTOR_NUMBER,motor_pin4);
  my_servo.attach(servo_pin);

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
      Serial.print(F("\r\nCircle"));
    }
   else if (PS3.getButtonPress(CROSS)){
      Serial.print(F("\r\nCross"));
      my_brake();
    }
    else if (PS3.getButtonPress(SQUARE)){
      Serial.print(F("\r\nSquare"));
    }
    else if (PS3.getButtonPress(UP)) {
      Serial.print(F("\r\nUp"));
      accel(angle,1);
      my_Servo(my_servo,angle);
      Serial.print(angle[0]);

    }
    else  if (PS3.getButtonPress(RIGHT)) {
      Serial.print(F("\r\nRight"));

    }
    else  if (PS3.getButtonPress(DOWN)) {
      Serial.print(F("\r\nDown"));
      accel(angle,-1);
      my_Servo(my_servo,angle);
      Serial.print(angle[0]);
    }
    else  if (PS3.getButtonPress(LEFT)) {
      Serial.print(F("\r\nLeft"));

    }
    else if (PS3.getButtonPress(L1)){
      Serial.print(F("\r\nL1"));
      my_turn_left();
      all_motor();
    }else if (PS3.getButtonPress(L2)) {
      Serial.print(F("\r\nL2"));
    }
    else if (PS3.getButtonPress(L3)){
      Serial.print(F("\r\nL3"));
    }
    else if (PS3.getButtonPress(R1)){
      Serial.print(F("\r\nR1"));
      my_turn_right();
      all_motor();
    }
    else if (PS3.getButtonClick(R2)){
      Serial.print(F("\r\nR2"));
    }      
    else if (PS3.getButtonPress(R3)){
      Serial.print(F("\r\nR3"));
    }
    else if (PS3.getButtonPress(SELECT)) {
      Serial.print(F("\r\nSelect"));
    }
    else if (PS3.getButtonPress(START)) {
      Serial.print(F("\r\nStart"));
    }
    else{
    my_left_analog_pad(K_direction(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY)));
    Serial.print(F("\r"));
    }
  }
}



void my_front(){
  accel(&pwm[0],-1);
  accel(&pwm[1],1);
  accel(&pwm[2],1);
  accel(&pwm[3],-1);
}

void my_f_right(){
  accel(&pwm[0],-1);
  accel(&pwm[1],0);
  accel(&pwm[2],1);
  accel(&pwm[3],0);
}

void my_right(){
  accel(&pwm[0],-1);
  accel(&pwm[1],-1);
  accel(&pwm[2],1);
  accel(&pwm[3],1);
}

void my_b_right(){
  accel(&pwm[0],0);
  accel(&pwm[1],-1);
  accel(&pwm[2],0);
  accel(&pwm[3],1);
}

void my_back(){
  accel(&pwm[0],1);
  accel(&pwm[1],-1);
  accel(&pwm[2],-1);
  accel(&pwm[3],1);
}

void my_b_left(){
  accel(&pwm[0],1);
  accel(&pwm[1],0);
  accel(&pwm[2],-1);
  accel(&pwm[3],0);
}

void my_left(){
  accel(&pwm[0],1);
  accel(&pwm[1],1);
  accel(&pwm[2],-1);
  accel(&pwm[3],-1);
}


void my_f_left(){
  accel(&pwm[0],0);
  accel(&pwm[1],1);
  accel(&pwm[2],0);
  accel(&pwm[3],-1);
}

void my_stop(){
  accel(&pwm[0],0);
  accel(&pwm[1],0);
  accel(&pwm[2],0);
  accel(&pwm[3],0);
}

void my_brake(){
  digitalWrite(motor_pin1[0],HIGH);
  digitalWrite(motor_pin1[1],HIGH);
  digitalWrite(motor_pin2[0],HIGH);
  digitalWrite(motor_pin2[1],HIGH);
  digitalWrite(motor_pin3[0],HIGH);
  digitalWrite(motor_pin3[1],HIGH);
  digitalWrite(motor_pin4[0],HIGH);
  digitalWrite(motor_pin4[1],HIGH);
}

void my_turn_right(){
  accel(&pwm[0],1);
  accel(&pwm[1],1);
  accel(&pwm[2],1);
  accel(&pwm[3],1);
}

void my_turn_left(){
  accel(&pwm[0],-1);
  accel(&pwm[1],-1);
  accel(&pwm[2],-1);
  accel(&pwm[3],-1);
}

void all_motor(){
  motor(pwm[0],motor_pin1);
  motor(pwm[1],motor_pin2);
  motor(pwm[2],motor_pin3);
  motor(pwm[3],motor_pin4);
}

void my_Servo(Servo my_servo, int* angle){
  if(angle[0] >= 180){
    angle[0] = 180;
  }else if(angle[0] <= 0){
    angle[0] = 0;
  }
  my_servo.write(angle[0]);
}

void my_left_analog_pad(int n){
  switch(n){
    case 6:
          my_front();    
          Serial.print(F("\r\nfront"));
          break;
    case 5:
          my_f_right();
          Serial.print(F("\r\nfront_right"));
          break;
    case 4:
          my_right();
          Serial.print(F("\r\nright"));
          break;
    case 3:
          my_b_right();
          Serial.print(F("\r\nback_right"));
          break;
    case 2:
          my_back();
          Serial.print(F("\r\nback"));
          break;
    case 1:
          my_b_left();
          Serial.print(F("\r\nback_left"));
          break;
    case 8:
          my_left();
          Serial.print(F("\r\nleft"));
          break;
    case 7:
          my_f_left();
          Serial.print(F("\r\nfront_left"));
          break;
    case 0:
          my_stop();
          Serial.print(F("\r\nstop"));
          break;
    default:
          my_stop();
      Serial.print(F("\r\nstop1"));
  }
  all_motor();
}

void encoder(int number,int *read_pin){
  int enc_n[number];
  *enc_n = trace(number,read_pin);
  for(int i = 0; i < number; i++){
    Serial.print(F("エンコーダー"));
    Serial.print(enc_n[i]);
  }
}



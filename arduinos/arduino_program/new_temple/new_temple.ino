#include <kadai_robo.h>


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

#define MOTOR_NUMBER 8
#define PWM_NUMBER 4
int motor_pin[MOTOR_NUMBER] = { 22, 23, 24, 25, 26, 27, 28, 29};
int pwm_pin[PWM_NUMBER] = { 5, 4, 3, 2};
int pwm[PWM_NUMBER]= { 0, 0, 0, 0};

void my_front();
void my_f_right();
void my_right();
void my_b_right();
void my_back();
void my_b_left();
void my_left();
void my_f_left();
void my_stop();
void my_left_analog_pad(int n);



void setup() {//ここから
  Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));
  //ここまではいじらないで良い

  K_set_motor(MOTOR_NUMBER,motor_pin);
  K_set_pwm(PWM_NUMBER,pwm_pin);

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
    }
    else if (PS3.getButtonPress(SQUARE)){
      Serial.print(F("\r\nSquare"));
    }
    else if (PS3.getButtonPress(UP)) {
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
    else if (PS3.getButtonPress(L1)){
      Serial.print(F("\r\nL1"));
    }else if (PS3.getButtonPress(L2)) {
      Serial.print(F("\r\nL2"));
      
    }
    else if (PS3.getButtonPress(L3)){
      Serial.print(F("\r\nL3"));
    }
    else if (PS3.getButtonPress(R1)){
      Serial.print(F("\r\nR1"));
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
  motor(pwm[0],&motor_pin[0],&pwm_pin[0]);
  acceleration(&pwm[0],-1);
  motor(pwm[1],&motor_pin[2],&pwm_pin[2]);
  acceleration(&pwm[1],1);
  motor(pwm[2],&motor_pin[4],&pwm_pin[4]);
  acceleration(&pwm[2],1);
  motor(pwm[3],&motor_pin[6],&pwm_pin[6]);
  acceleration(&pwm[3],-1);
}

void my_f_right(){  
  motor(pwm[0],&motor_pin[0],&pwm_pin[0]);
  decceleration(&pwm[0],1);
  motor(pwm[1],&motor_pin[2],&pwm_pin[2]);
  acceleration(&pwm[1],1);
  motor(pwm[2],&motor_pin[4],&pwm_pin[4]);
  decceleration(&pwm[2],1);
  motor(pwm[3],&motor_pin[6],&pwm_pin[6]);
  acceleration(&pwm[3],-1);
}

void my_right(){
  motor(pwm[0],&motor_pin[0],&pwm_pin[0]);
  acceleration(&pwm[0],1);
  motor(pwm[1],&motor_pin[2],&pwm_pin[2]);
  acceleration(&pwm[1],1);
  motor(pwm[2],&motor_pin[4],&pwm_pin[4]);
  acceleration(&pwm[2],-1);
  motor(pwm[3],&motor_pin[6],&pwm_pin[6]);
  acceleration(&pwm[3],-1);
}

void my_b_right(){
  motor(pwm[0],&motor_pin[0],&pwm_pin[0]);
  acceleration(&pwm[0],1);
  motor(pwm[1],&motor_pin[2],&pwm_pin[2]);
  decceleration(&pwm[1],1);
  motor(pwm[2],&motor_pin[4],&pwm_pin[4]);
  acceleration(&pwm[2],-1);
  motor(pwm[3],&motor_pin[6],&pwm_pin[6]);
  decceleration(&pwm[3],1);
}

void my_back(){
  motor(pwm[0],&motor_pin[0],&pwm_pin[0]);
  acceleration(&pwm[0],1);
  motor(pwm[1],&motor_pin[2],&pwm_pin[2]);
  acceleration(&pwm[1],-1);
  motor(pwm[2],&motor_pin[4],&pwm_pin[4]);
  acceleration(&pwm[2],-1);
  motor(pwm[3],&motor_pin[6],&pwm_pin[6]);
  acceleration(&pwm[3],1);
}

void my_b_left(){
  motor(pwm[0],&motor_pin[0],&pwm_pin[0]);
  decceleration(&pwm[0],1);
  motor(pwm[1],&motor_pin[2],&pwm_pin[2]);
  acceleration(&pwm[1],-1);
  motor(pwm[2],&motor_pin[4],&pwm_pin[4]);
  decceleration(&pwm[2],1);
  motor(pwm[3],&motor_pin[6],&pwm_pin[6]);
  acceleration(&pwm[3],1);
}

void my_left(){
  motor(pwm[0],&motor_pin[0],&pwm_pin[0]);
  acceleration(&pwm[0],-1);
  motor(pwm[1],&motor_pin[2],&pwm_pin[2]);
  acceleration(&pwm[1],-1);
  motor(pwm[2],&motor_pin[4],&pwm_pin[4]);
  acceleration(&pwm[2],1);
  motor(pwm[3],&motor_pin[6],&pwm_pin[6]);
  acceleration(&pwm[3],1);
}


void my_f_left(){
  motor(pwm[0],&motor_pin[0],&pwm_pin[0]);
  acceleration(&pwm[0],-1);
  motor(pwm[1],&motor_pin[2],&pwm_pin[2]);
  decceleration(&pwm[1],1);
  motor(pwm[2],&motor_pin[4],&pwm_pin[4]);
  acceleration(&pwm[2],1);
  motor(pwm[3],&motor_pin[6],&pwm_pin[6]);
  decceleration(&pwm[3],1);
}

void my_stop(){
  motor(pwm[0],&motor_pin[0],&pwm_pin[0]);
  decceleration(&pwm[0],1);
  motor(pwm[1],&motor_pin[2],&pwm_pin[2]);
  decceleration(&pwm[1],1);
  motor(pwm[2],&motor_pin[4],&pwm_pin[4]);
  decceleration(&pwm[2],1);
  motor(pwm[3],&motor_pin[6],&pwm_pin[6]);
  decceleration(&pwm[3],1);
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
}



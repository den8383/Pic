//＊いじるところ１

#define PIN_NUMBER 12
int pin[PIN_NUMBER] = { 22, 23, 11, 24, 25, 10, 26, 27, 9, 28, 29, 6};
int pwm1 = 125;
int pwm2 = 125;
#define MPIN1_1 22//motor1
#define MPIN1_2 23//motor1
#define MPIN2_1 24//motor2
#define MPIN2_2 25//motor2
#define MPIN3_1 26//motor3
#define MPIN3_2 27//motor3
#define MPIN4_1 28//motor4
#define MPIN4_2 29//motor4
#define MPIN5_1 30//motor5
#define MPIN5_2 31//motor5
#define PWMPIN 6//pwm
#define DENJIBENPIN_O 37
#define DENJIBENPIN_G 38
#define pwm_min 125
#define pwm_add 5
//ここまで１
int pwm_val = constrain(pwm_val, pwm_min, 255);
int pad_x;
int pad_y;
int denjiben_count;
int my_direction(int x, int y) {
  double deg, rad;
  int pattern = 0;
  x -= 128;
  y = abs(y - 256) - 128;
  rad = atan2((double)y, (double)x);
  deg = rad * 180.0 / (atan(1.0) * 4.0);
  if (abs(x) > 16 || abs(y) > 16)
  {
    pattern = 8;
    deg += 180.0;
    for (int i = 0; i < 7; i++) {

      if (deg >= 22.5 + (i * 45.0) && deg < 67.5 + (i * 45.0)) {
        pattern = i + 1;

      }
    }
    Serial.print(deg);
  }
  return pattern;
}
/*
  int my_mod(int n){
  if(n > 0){
    mod_val++;
  }else if(n<0){
    mod_val--;
  }else{
    mod_val = 0;
  }
  return mod_val;
  }
*/

int mod_val = 0;
void motor1(int n) { //モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if (n > 0) {
    digitalWrite(pin[0], HIGH);
    digitalWrite(pin[1], LOW);
    analogWrite(pin[2], pwm1);
  }
  else if (n < 0) {
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], HIGH);
    analogWrite(pin[2], pwm1);
  }
  else {
    digitalWrite(pin[0], LOW);
    digitalWrite(pin[1], LOW);
    analogWrite(pin[2], pwm1);
  }
}


void motor2(int n) { //モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if (n > 0) {
    digitalWrite(pin[3], HIGH);
    digitalWrite(pin[4], LOW);
    analogWrite(pin[5], pwm1);
  }
  else if (n < 0) {
    digitalWrite(pin[3], LOW);
    digitalWrite(pin[4], HIGH);
    analogWrite(pin[5], pwm1);
  }
  else {
    digitalWrite(pin[3], LOW);
    digitalWrite(pin[4], LOW);
    analogWrite(pin[5], pwm1);
  }
}


void motor3(int n) { //モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if (n > 0) {
    digitalWrite(pin[6], HIGH);
    digitalWrite(pin[7], LOW);
    analogWrite(pin[8], pwm1);
  }
  else if (n < 0) {
    digitalWrite(pin[6], LOW);
    digitalWrite(pin[7], HIGH);
    analogWrite(pin[8], pwm1);
  }
  else {
    digitalWrite(pin[6], LOW);
    digitalWrite(pin[7], LOW);
    analogWrite(pin[8], pwm1);
  }
}


void motor4(int n) { //モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if (n > 0) {
    digitalWrite(pin[9], HIGH);
    digitalWrite(pin[10], LOW);
    analogWrite(pin[11], pwm1);
  }
  else if (n < 0) {
    digitalWrite(pin[9], LOW);
    digitalWrite(pin[10], HIGH);
    analogWrite(pin[11], pwm1);
  }
  else {
    digitalWrite(pin[9], LOW);
    digitalWrite(pin[10], LOW);
    analogWrite(pin[11], pwm1);
  }
}

void  my_stop() {
  motor1(0);
  motor2(0);
  //  motor3(0);
  //  motor4(0);
}
void my_front() {
  motor1(-1);
  motor2(1);
  //  motor3(1);
  //  motor4(-1);
}


void my_right() {
  motor1(1);
  motor2(1);
  //  motor3(-1);
  //  motor4(-1);
}


void my_back() {
  motor1(1);
  motor2(-1 );
  //  motor3(-1);
  //  motor4(1);
}

void my_left() {
  motor1(-1);
  motor2(-1);
  //  motor3(1);
  //  motor4(1);
}





/*
  void my_left_analog_pad(int n){
  switch(n){
    case 6:
          my_front();
          pwm1++;
          Serial.print(F("\r\nfront"));
          break;
    case 5:
           my_upper_right();
          pwm_val++;
          Serial.print(F("\r\nupper_right"));
          break;
    case 4:
          my_right();
          pwm1++;
          Serial.print(F("\r\nright"));
          break;
    case 3:
          my_lower_right();
          pwm_val++;
          Serial.print(F("\r\nlower_right"));
          break;
    case 2:
          my_back();
          pwm_val++;
          Serial.print(F("\r\nback"));
          break;
    case 1:
          my_lower_left();
          pwm_val++;
          Serial.print(F("\r\nlower_left"));
          break;
    case 8:
          my_left();
          pwm_val++;
          Serial.print(F("\r\nleft"));
          break;
    case 7:
          my_upper_left();
          pwm_val++;
          Serial.print(F("\r\nupper_right"));
          break;
    case 0:
          my_stop();
          Serial.print(F("\r\nstop"));
          break;
    default:
  //      my_stop();
  //      pwm_val = pwm_min;
      Serial.print(F("\r\nstop1"));
  }
  }
*/

/*void my_up_down(int n){
  if(n > 0){
    motor5(1);
  }else if(n < 0){
    motor5(-1);
  }else{
    motor5(0);
  }
  }
*/


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
  for ( int i; i < PIN_NUMBER; i++) {
    pinMode(pin[i], OUTPUT);
    digitalWrite(pin[i], LOW);
  }
  pinMode(PWMPIN, OUTPUT); //PWM用
  //
  pwm1  = 125;
}
void loop() {
  Usb.Task();
  if (PS3.PS3Connected) {
    if (PS3.getButtonClick(PS)) { //各ボタンの中にモーターを動かしたりトランジスタを動かしたりサーボを動かす処理をかいてください
      Serial.print(F("\r\nPS"));
    }
    else {
    }
    if (PS3.getButtonPress(TRIANGLE)) {
      Serial.print(F("\r\nTraingle"));
    }
    else if (PS3.getButtonPress(CIRCLE)) {
      Serial.print(F("\r\nCircle"));
      //      my_up_down(1);
    }
    else if (PS3.getButtonPress(CROSS)) {
      Serial.print(F("\r\nCross"));
      //      my_up_down(-1);
    }
    else if (PS3.getButtonPress(SQUARE)) {
      Serial.print(F("\r\nSquare"));
    }
    else {
      //      my_up_down(0);
    }

    if (PS3.getButtonPress(UP)) {
      my_front();
      // pwm1++;
      Serial.print(F("\r\nUp"));

    }
    else  if (PS3.getButtonPress(RIGHT)) {
      my_right();
      //pwm1++;
      Serial.print(F("\r\nRight"));

    }
    else  if (PS3.getButtonPress(DOWN)) {
      my_back();
      //pwm1++;
      Serial.print(F("\r\nDown"));

    }
    else  if (PS3.getButtonPress(LEFT)) {
      my_left();
      //pwm1++;
      Serial.print(F("\r\nLeft"));

    } else {
      Serial.print(F("\r\nSTOP"));
      my_stop();
    }

    if (PS3.getButtonPress(L2)) {
      Serial.print(F("\r\nL2"));
    }
    else {

    }
    if (PS3.getButtonPress(L3)) {
      Serial.print(F("\r\nL3"));
    }
    else {
    }

    if (PS3.getButtonPress(L1)) {
      Serial.print(F("\r\nL1"));
      //my_turn_left();
    } else if (PS3.getButtonPress(R1)) {
      Serial.print(F("\r\nR1"));
      //my_turn_right();
    }
    else {
      //    my_left_analog_pad(my_direction(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY)));
    }
    if (PS3.getButtonClick(R2)) {
      Serial.print(F("\r\nR2"));
      if (denjiben_count == 1) {
        digitalWrite(DENJIBENPIN_O, HIGH);
        digitalWrite(DENJIBENPIN_G, LOW);
        Serial.print(F("open"));
        denjiben_count--;
      } else if (denjiben_count == 0) {
        digitalWrite(DENJIBENPIN_O, LOW);
        digitalWrite(DENJIBENPIN_G, LOW);
        Serial.print(F("close"));
        denjiben_count++;
      } else {

      }
    }
    if (PS3.getButtonPress(R3)) {
      Serial.print(F("\r\nR3"));
    }
    else {

    }

    if (PS3.getButtonPress(SELECT)) {
      Serial.print(F("\r\nSelect"));
    }
    else {

    }
    if (PS3.getButtonPress(START)) {
      Serial.print(F("\r\nStart"));
    }
    else {

    }
  }
  /*    if(pwm_val > 255){
        pwm_val = 255;
      }
      Serial.print(F("PWM\n"));
      Serial.print(pwm1);
      Serial.print(F("deg\n"));
    }
  */
  /*
    Serial.print("\r\n");
    Serial.print(F("PWM"));
    Serial.print(pwm_val);
  */
  delay(10);
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

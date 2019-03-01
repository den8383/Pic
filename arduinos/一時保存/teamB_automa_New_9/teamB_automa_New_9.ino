#include<Servo.h>

enum myStatus {
  INIT,   
  PHASE_1,
  PHASE_2,
  PHASE_3,
  PHASE_4,
  PHASE_5,
  PHASE_6,
  PHASE_7,
  PHASE_8,
  PHASE_9,
  PHASE_10,
  PHASE_11,
  PHASE_12,
  PHASE_13,
  PHASE_14,
  PHASE_15,
  PHASE_16,
  GOAL    
};
myStatus gStatus = INIT;

#define PIN_NUMBER 14
int pin[PIN_NUMBER] = { 22, 23, 11, 24, 25, 10, 26, 27, 9, 28, 29, 6, 30,31};
#define NUMBER 8

#define DENJIBENPIN 37
#define ServoPin 3
/*#define p1 22//motor1
#define p2 23//motor1
#define p3 11//motor1
#define p4 24//motor2
#define p5 25//motor2
#define p6 10//motor2
#define p7 26//motor3
#define p8 27//motor3
#define p9 9//motor3
#define p10 28//motor4
#define p11 29//motor4
#define p12 6//motor4
#define p13 30//motor5
#define p14 31//motor5
#define p15 5//motor5
#define p16 36
#define p16 37
#define p17 38
#define p18 39
#define p19 40
*/
#define UP_TIME_1 3000
#define UP_TIME_2 1000
#define UP_TIME_3 3000
#define UP_TIME_4 4000
#define DOWN_TIME_1 3000
#define DOWN_TIME_2 1000
#define DOWN_TIME_3 1500
#define DOWN_TIME_4 3000
#define SUN_TIME 1000
#define STAND_TIME_1 2000
#define STAND_TIME_2 1000
#define servo_val_0 90
#define servo_val_1 60

#define servo_val_2 120

#define STOP 0
#define FRONT 1
#define FRONT_RIGHT 2
#define RIGHT 3
#define BACK_RIGHT 4
#define BACK 5
#define BACK_LEFT 6
#define LEFT 7
#define FRONT_LEFT 8
#define STEER_RIGHT_F 9
#define STEER_RIGHT_B 10
#define STEER_LEFT_F 11
#define STEER_LEFT_B 12
#define TURN_RIGHT 13
#define TURN_LEFT 14
int save_point = 0;


Servo myservo1;
Servo myservo2;

int gflag = 0;

#define THRESHOLD 50
int trPin[NUMBER] = { A0, A1, A2, A3, A4, A5, A6, A7};
int LPIN[NUMBER] = { 46, 47, 48, 49, 50, 51, 52, 53};
int trace(int number, int threshold) { // numberにはNUMBERを、thresholdにはTHRESHOLD
  //Serial.print(F("aaaa"));
  int x[number];//センサーの値を格納します
  int i = 0;
  long int trace_point = 0;
  long int old_trace_point = 0;  
  int r = 0;
  long int s = 1;
  Serial.print(F("\r\n"));
  for ( i = 0; i < number; i++) { //x[0]～x[NUMBER]
    Serial.print(i);
    Serial.print("ban");
    x[i] = analogRead( trPin[i]);
    Serial.print(x[i]);
    delay(2000);
    
    r = i;
    if ( x[i] < threshold) { //trace_point←x[0]x[1]x[2]～x[7] 
      s = 1;
      digitalWrite( LPIN[i], HIGH);
 //   trace_point += pow(2, i)+0.001;
      while(r > 0){
        if(r == 0){
           s = 0;
        }else if(r > 0){
          s=s*10;
          r--;
        }
      }
      trace_point += s;
      old_trace_point = trace_point;
    } else {
      digitalWrite( LPIN[i], LOW);
      old_trace_point = trace_point;
    }
    Serial.print(F(":"));
    Serial.print(F("["));
    Serial.print(s);
    Serial.print(F("]"));
  }
  Serial.print(trace_point);
  Serial.print(F("|"));
//Serial.print(trace_point,BIN);
//  Serial.print(String(trace_point, 2));
  Serial.print("\r\n");
  delay(1000);
  if ( trace_point < 11111111) { //全部１ではないとき
    return trace_point;
  } else if (trace_point == 11111111) { //全部1の時前回の値を返す
    gflag = 1;
    return old_trace_point;
  }
}


int mod_val = 0;
void motor1(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(pin[0],HIGH);
    digitalWrite(pin[1],LOW);
    analogWrite(pin[2],mod_val);
  }
  else if(n<0){
    digitalWrite(pin[0],LOW);
    digitalWrite(pin[1],HIGH);
    analogWrite(pin[2],mod_val);
  }
  else{
    digitalWrite(pin[0],LOW);
    digitalWrite(pin[1],LOW);
    analogWrite(pin[2],mod_val);
  }
}


void motor2(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(pin[3],HIGH);
    digitalWrite(pin[4],LOW);
    analogWrite(pin[5],mod_val);
  }
  else if(n<0){
    digitalWrite(pin[3],LOW);
    digitalWrite(pin[4],HIGH);
    analogWrite(pin[5],mod_val);
  }
  else{
    digitalWrite(pin[3],LOW);
    digitalWrite(pin[4],LOW);
    analogWrite(pin[5],mod_val);
  }
}


void motor3(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(pin[6],HIGH);
    digitalWrite(pin[7],LOW);
    analogWrite(pin[8],mod_val);
  }
  else if(n<0){
    digitalWrite(pin[6],LOW);
    digitalWrite(pin[7],HIGH);
    analogWrite(pin[8],mod_val);
  }
  else{
    digitalWrite(pin[6],LOW);
    digitalWrite(pin[7],LOW);
    analogWrite(pin[8],mod_val);
  }
}


void motor4(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(pin[9],HIGH);
    digitalWrite(pin[10],LOW);
    analogWrite(pin[11],mod_val);
  }
  else if(n<0){
    digitalWrite(pin[9],LOW);
    digitalWrite(pin[10],HIGH);
    analogWrite(pin[11],mod_val);
  }
  else{
    digitalWrite(pin[9],LOW);
    digitalWrite(pin[10],LOW);
    analogWrite(pin[11],mod_val);
  }
}

void motor5(int n){//モーターを扱うための関数　これを使ってもよいし作り直してもよいです
  if(n>0){
    digitalWrite(pin[12],HIGH);
    digitalWrite(pin[13],LOW);
  }
  else if(n<0){
    digitalWrite(pin[12],LOW);
    digitalWrite(pin[13],HIGH);
  }
  else{
    digitalWrite(pin[12],LOW);
    digitalWrite(pin[13],LOW);
  }
}
void my_open(){
  digitalWrite(DENJIBENPIN,HIGH);
  
}

void my_close(){
  digitalWrite(DENJIBENPIN,LOW);
  
}


int closs_count = 0;


void  my_stop(){
  motor1(0);
  motor2(0);
  motor3(0);
  motor4(0);
  save_point = STOP;
}
void my_front(){
  motor1(-1);
  motor2(1);
  motor3(1);
  motor4(-1);
  save_point = FRONT;
}

void my_front_right(){
  motor1(0);
  motor2(1);
  motor3(0);
  motor4(-1);
  
  save_point = FRONT_RIGHT;
}

void my_right(){
  motor1(1);
  motor2(1);
  motor3(-1);
  motor4(-1);
  save_point = RIGHT;
}

void my_back_right(){
  motor1(1);
  motor2(0);
  motor3(-1);
  motor4(0);
  save_point = BACK_RIGHT;
}

void my_back(){
  motor1(1);
  motor2(-1);
  motor3(-1);
  motor4(1);
  save_point = BACK;
}

void my_back_left(){
  motor1(0);
  motor2(-1);
  motor3(0);
  motor4(1);
  save_point = BACK_LEFT;
}

void my_left(){
  motor1(-1);
  motor2(-1);
  motor3(1);
  motor4(1);
  save_point = LEFT;
}


void my_front_left(){
  motor1(-1);
  motor2(0);
  motor3(1);
  motor4(0);
  save_point = FRONT_LEFT;
}

void my_steer_right_F(){
  motor1(1);
  motor2(1);
  motor3(0);
  motor4(0);
  save_point = STEER_RIGHT_F;
}

void my_steer_right_B(){
  motor1(0);
  motor2(0);
  motor3(-1);
  motor4(-1);
  save_point = STEER_RIGHT_B;
}

void my_steer_left_F(){
  motor1(-1);
  motor2(-1);
  motor3(0);
  motor4(0);
  save_point = STEER_LEFT_F;
}

void my_steer_left_B(){
  motor1(0);
  motor2(0);
  motor3(1);
  motor4(1);
  save_point = STEER_LEFT_B;
}


void my_turn_right(){
  motor1(1);
  motor2(1);
  motor3(1);
  motor4(1);
  save_point = TURN_RIGHT;
}

void my_turn_left(){
  motor1(-1);
  motor2(-1);
  motor3(-1);
  motor4(-1);
  save_point = TURN_LEFT;
}

void my_save(int n){
  if(n == 0){
    my_stop();
  }else if( n == 1){
    my_front();
  }else if( n == 2){
    my_front_right();
  }else if( n == 3){
    my_right();
  }else if( n == 4){
    my_back_right();
  }else if( n == 5){
    my_back();
  }else if( n == 6){
    my_back_left();
  }else if( n == 7){
    my_left();
  }else if( n == 8){
    my_front_left();
  }else if( n == 9){
    my_steer_right_F();
  }else if( n ==10){
    my_steer_right_B();
  }else if( n== 11){
    my_steer_left_F();
  }else if( n == 12){
    my_steer_left_B();
  }else if( n == 13){
    my_turn_right();
  }else if( n == 14){
    my_turn_left();
  }
}

void my_up( int n){
  if(n == 1){
    motor5(1);
    delay(UP_TIME_1);
  }else if(n == 2){
    motor5(1);
    delay(UP_TIME_2);
  }else if(n == 3){
    motor5(1);
    delay(UP_TIME_3);
  }else if(n  == 4){
    motor5(1);
    delay(UP_TIME_4);
  }else{
    motor5(0);
  }
}

void my_down( int n){
  if(n == 0){
    motor5(-1);
    delay(DOWN_TIME_1);
  }else if(n == 2){
    motor5(-1);
    delay(DOWN_TIME_2);
  }else if(n == 3){
    motor5(-1);
    delay(DOWN_TIME_3);
  }else if(n == 4){
    motor5(-1);
    delay(DOWN_TIME_4);
  }else{
    motor5(0);
  }
}

void my_catch_SUN(){
  my_down(2);
  my_open();
  my_front();
  delay(SUN_TIME);
  my_close();
  my_up(2);
  my_back();
  delay(SUN_TIME);
}

void my_catch_STAND(){
    my_down(2);
    my_open();
    my_down(3);
    my_close();
    my_up(3);
}

/*
void my_catch_STAND(int n){
  if(n == 1){
    my_right();
    delay(STAND_TIME_1);
    my_down(2);
    my_open();
    my_down(3);
    my_close();
    my_up(3);
  }else if(n == 2){
    my_down(2);
    my_open();
    my_down(3);
    my_close();
    my_up(3);
    
    my_right();
    delay(STAND_TIME_2);
    my_down(2);
    my_open();
    my_down(3);
    my_close();
    my_up(3);
  }
  
}
*/
void my_release(){
  
}

 void my_rotation(int n){
  
}

void init(){
  Serial.print(F("init"));
  my_stop();
  delay(3000);
  gStatus = PHASE_1;
  gflag = 0;
}

void phase_1(){
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag == 1){
    gflag = 0;
    gStatus = PHASE_2;
  }
}

void phase_2(){
  void my_catch_SUN();
  change_trPin(1);
  gStatus = PHASE_3;
}

void phase_3(){
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag ==1){
    gflag = 0;
    change_trPin(0);
    gStatus = PHASE_4;
  }
}

void phase_4(){
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag == 1){
    gflag = 0;
    gStatus = PHASE_5;
  }
}

void phase_5(){
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag == 1){
    gflag = 0;
    my_stop();
    delay(1000);
    my_turn_left();
    delay(1000);
    my_stop();
    delay(1000);
    gStatus = PHASE_6;
  }
}

void phase_6(){
  my_turn_left();
  if(gflag == 1){
    gflag = 0;
    change_trPin(2);
    gStatus = PHASE_7;
  }
}

void phase_7(){
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag ==1){
    gflag = 0;
    change_trPin(3);
    gStatus = PHASE_8;
  }
}

void phase_8(){
  my_motion(trace(NUMBER,THRESHOLD));
  delay(STAND_TIME_1);
  my_catch_STAND();
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag = 1){
    gflag = 0;
    gStatus = PHASE_9;
  }
}


void phase_9(){
  my_motion(trace(NUMBER,THRESHOLD));
  delay(STAND_TIME_2);
  my_catch_STAND();
  change_trPin(1);
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag == 1){
    gflag = 0;
    gStatus = PHASE_10;
  }
}

void phase_10(){
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag == 1){
    gflag = 0;
    change_trPin(0);
    gStatus = PHASE_11;
  }
}

void phase_11(){
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag == 1){
    gflag = 0;
    change_trPin(1);
    gStatus = PHASE_12;
  }
}

void phase_12(){
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag == 1){
    gflag = 0;
    gStatus = PHASE_13;
    }
}

void phase_13(){
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag == 1){
    gflag = 0;
    change_trPin(2);
    gStatus = PHASE_14;
  }
}

void phase_14(){
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag == 1){
    gflag = 0;
    gStatus = PHASE_15;
  }
}

void phase_15(){
  my_motion(trace(NUMBER,THRESHOLD));
  if(gflag == 1){
    gflag = 0;
    gStatus = PHASE_16;
  }
}

void phase_16(){
  my_back();
  delay(1000);
  my_turn_right();
  delay(1000);
  my_stop();
  delay(1000);
  my_release();
  delay(1000);
  gStatus = GOAL;
  
}

void goal(){
  my_stop();
  delay(1000);
}

void my_motion(int n){
  if(n = 00000000){
    my_stop();
  }else if( n = 00110011){//n = abcdefgh
    my_front();
  }else if( n = 00100010){
    my_turn_left();
  }else if( n = 00010001){
    my_turn_right();
  }else {
    my_save( save_point);
  }
}



void change_trPin(int n){
  if( n == 0){
    trPin[0] = {A0};
    trPin[1] = {A1};
    trPin[2] = {A2};
    trPin[3] = {A3};
    trPin[4] = {A4};
    trPin[5] = {A5}; 
    trPin[6] = {A6}; 
    trPin[7] = {A7};
  }
  else if( n == 1){
    trPin[0] = {A2};
    trPin[1] = {A3};
    trPin[2] = {A4};
    trPin[3] = {A5};
    trPin[4] = {A6};
    trPin[5] = {A7}; 
    trPin[6] = {A0}; 
    trPin[7] = {A1};
  }
  else if( n == 2){
    trPin[0] = {A4};
    trPin[1] = {A5};
    trPin[2] = {A6};
    trPin[3] = {A7};
    trPin[4] = {A0};
    trPin[5] = {A1}; 
    trPin[6] = {A2}; 
    trPin[7] = {A3};
  }
  else if( n == 3){
    trPin[0] = {A6};
    trPin[1] = {A7};
    trPin[2] = {A0};
    trPin[3] = {A1};
    trPin[4] = {A2};
    trPin[5] = {A3}; 
    trPin[6] = {A4}; 
    trPin[7] = {A5};
  }
}

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  for(int h = 0; h < PIN_NUMBER; h++){
     pinMode( pin[h],OUTPUT);
     digitalWrite( pin[h], LOW);
  }
  for(int i = 0; i < NUMBER; i++){
    pinMode(trPin[i],INPUT);
  }
  for( int k = 0; k < 8; k++){
    pinMode( LPIN[k], OUTPUT);
    digitalWrite( LPIN[k], LOW);
  }
  for(int j = 38; j < 46; j++){
    pinMode(j,OUTPUT);
    digitalWrite(j,HIGH);
  }
  
  myservo1.attach(ServoPin);
  pinMode(ServoPin,OUTPUT);  
  digitalWrite(ServoPin,LOW);
  pinMode(DENJIBENPIN,OUTPUT);

}

void loop() {
  switch (gStatus) {
    case INIT:
      break;
    case PHASE_1:
      break;
    case PHASE_2:
      break;
    case PHASE_3:
      break;
    case PHASE_4:
      break;
    case PHASE_5:
      break;
    case PHASE_6:
      break;
    case GOAL:
    my_stop();
      break;
  }
  my_motion(trace(NUMBER,THRESHOLD));
  
  // put your main code here, to run repeatedly:
  //my_motion(trace(NUMBER,THRESHOLD));
  delay(100);
 
}




/*
void my_front( int n){
  if(n > 0){
    mod_val = 255;
    motor1(1);
  }else if( n < 0){
    mod_val = 127;
    motor1(1);
  }else{
    mod_val = 168;
    motor1(1);
  }
  Serial.print(F("PWM"));
  Serial.print(  mod_val);
}

void my_stop(){
  mod_val = 0;
  motor1(0);
  Serial.print(F("PWM"));
  Serial.print(mod_val);
}

void steer( int n){
  if( n > 0 ){
    myservo1.write(servo_val_1);
   // myservo2.write(servo_val_1);
   //Serial.print(F("right\n"));
  }else if( n < 0){
    myservo1.write(servo_val_2);
    //myservo2.write(servo_val_2);
    //Serial.print(F("left\n"));
  }else{
    myservo1.write(servo_val_0);
    //myservo2.write(servo_val_0);
    //Serial.print(F("straight\n"));
  }
}
*/
/*
int trace_a(){
  int n;
  n = analogRead( trPin_a);
  if(n > 524){
    n = 0;
  }else{
    n = 1;
  }
  return n;
}

int trace_b(){
  int n;
  n = analogRead( trPin_b);
  if(n > 524){
    n = 0;
  }else{
    n = 1;
  }
  return n;
}

int trace_c(){
  int n;
  n = analogRead( trPin_c);
  if(n > 524){
    n = 0;
  }else{
    n = 1;
  }
  return n;
}

int trace_d(){
  int n;
  n = analogRead( trPin_d);
  if(n > 524){
    n = 0;
  }else{
    n = 1;
  }
  return n;
}

int trace_e(){
  int n;
  n = analogRead( trPin_e);
  if(n > 524){
    n = 0;
  }else{
    n = 1;
  }
  return n;
}

int trace_f(){
  int n;
  n = analogRead( trPin_f);
  if(n > 524){
    n = 0;
  }else{
    n = 1;
  }
  return n;
}

int trace_g(){
  int n;
  n = analogRead( trPin_g);
  if(n > 524){
    n = 0;
  }else{
    n = 1;
  }
  return n;
}

int trace_h(){
  int n;
  n = analogRead( trPin_h);
  if(n > 524){
    n = 0;
  }else{
    n = 1;
  }
  return n;
}
*/
/*
  switch(closs_count){
    case 0:
      my_up(1);
      my_motion_A( trace_a, trace_b, trace_c, trace_d, trace_e, trace_f, trace_g, trace_h);
    case 1:
      my_motion_A( trace_a, trace_b, trace_c, trace_d, trace_e, trace_f, trace_g, trace_h);
    case 2:
      my_catch_SUN();
      my_motion_A( trace_e, trace_f, trace_g, trace_h, trace_a, trace_b, trace_c, trace_d);
    case 3:
      my_motion_A( trace_g, trace_h, trace_a, trace_b, trace_c, trace_d, trace_e, trace_f);
    case 4:
      my_motion_A( trace_a, trace_b, trace_c, trace_d, trace_e, trace_f, trace_g, trace_h);
    case 5:
      my_motion_A( trace_a, trace_b, trace_c, trace_d, trace_e, trace_f, trace_g, trace_h);
    case 6:
      my_down(2);
      my_motion_A( trace_c, trace_d, trace_e, trace_f, trace_g, trace_h, trace_a, trace_b);
    case 7:
      my_rotation(-1);
      my_motion_A( trace_c, trace_d, trace_e, trace_f, trace_g, trace_h, trace_a, trace_b);
      delay(500);
      my_catch_STAND(1);
      my_motion_A( trace_c, trace_d, trace_e, trace_f, trace_g, trace_h, trace_a, trace_b);
    case 8:
      my_catch_STAND(2);
      my_motion_A( trace_g, trace_h, trace_a, trace_b, trace_c, trace_d,trace_e, trace_f);
    case 9:
      my_motion_A( trace_g, trace_h, trace_a, trace_b, trace_c, trace_d,trace_e, trace_f);
    case 10:
      my_rotation(1);
      my_motion_A( trace_g, trace_h, trace_a, trace_b, trace_c, trace_d,trace_e, trace_f);
    case 11:
      my_motion_A( trace_e, trace_f, trace_g, trace_h, trace_a, trace_b, trace_c, trace_d);
    case 12:
      my_motion_A( trace_e, trace_f, trace_g, trace_h, trace_a, trace_b, trace_c, trace_d);
    case 13:
      my_rotation(1);
       my_motion_A( trace_a, trace_b, trace_c, trace_d, trace_e, trace_f, trace_g, trace_h);
    case 14:
       my_motion_A( trace_a, trace_b, trace_c, trace_d, trace_e, trace_f, trace_g, trace_h);
    case 15:
       my_open();
       my_motion_A( trace_e, trace_f, trace_g, trace_h, trace_a, trace_b, trace_c, trace_d);
    case 16:
       my_stop();
  }
*/

/*
void my_motion(int a, int b)
{
  Serial.print(F("SENSOR"));
  if(a ==0 && b == 0){
    Serial.print(F("00\n"));
    steer(0);
    my_front(1);
  }else if(a == 0 && b == 1){
    Serial.print(F("01\n"));
    steer(-1);
    my_front(-1);
  }else if(a == 1 && b == 0){
    Serial.print(F("10\n"));
    steer(1);
    my_front(-1);
  }else if(a == 1 && b ==1){
    Serial.print(F("11\n"));
    my_stop();
  }
}
*/



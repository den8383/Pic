#include<Servo.h>
#define PIN_NUMBER 12
int pin[PIN_NUMBER] = { 22, 23, 11, 24, 25, 10, 26, 27, 9, 28, 29, 6};
#define NUMBER 8
#define p1 22//motor1
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
#define DENJIBENPIN 37
#define ServoPin 3
#define p16 37
#define p17 38
#define p18 39
#define p19 40

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
    digitalWrite(p13,HIGH);
    digitalWrite(p14,LOW);
    analogWrite(p15,mod_val);
  }
  else if(n<0){
    digitalWrite(p13,LOW);
    digitalWrite(p14,HIGH);
    analogWrite(p15,mod_val);
  }
  else{
    digitalWrite(p13,LOW);
    digitalWrite(p14,LOW);
    analogWrite(p15,mod_val);
  }
}
void my_open(){
  digitalWrite(DENJIBENPIN,HIGH);
  
}

void my_close(){
  digitalWrite(DENJIBENPIN,LOW);
  
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
}
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

void my_release(){
  
}

 void my_rotation(int n){
  
}


void my_motion(int n){
  if(n = 00000000){
    my_stop();
  }else if( n = 01100110){//n = abcdefgh
    my_front();
  }else if( n = 01000100){
    my_turn_left();
  }else if( n = 00100010){
    my_turn_right();
  }else {
    my_save( save_point);
  }
}



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
    return old_trace_point;
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


void my_motion_A(int h, int g, int f, int e, int d, int c, int b, int a){
  if(h == 0 && g ==0 && f == 0 && e ==0 && d == 0 && c == 0 && b == 0 && a == 0){
    my_stop();
    Serial.print(F("00000000\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("00000001\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("00000010\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("00000011\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 0 && c == 1 && b == 0 && a == 0){
    
    Serial.print(F("00000100\nn"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("00000101\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("00000110\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("00000111\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("00001000\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("00001001\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("00001010\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("00001011\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("00001100\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("00001101\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("00001110\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==0 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("00001111\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("00010000\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("00010001\n"));
  }else if( h== 0 && g ==0 && f == 0 && e ==1 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("00010010\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("00010011\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("00010100\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("00010101\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("00010110\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("00010111\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("00011000\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("00011001\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("00011010\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("00011011\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("00011100\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("00011101\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("00011110\n"));
  }else if(h == 0 && g ==0 && f == 0 && e ==1 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("00011111\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("00100000\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("00100001\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("00100010\n"));
    my_turn_right();
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("00100011\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("00100100\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("00100101\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("00100110\n"));
    my_steer_right_B();
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("00100111\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("00101000\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("00101001\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("00101010\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("00101011\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("00101100\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("00101101\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("00101110\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==0 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("00101111\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("00110000\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("00110001\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("00110010\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("00110011\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("00110100\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("00110101\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("00110110\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("00110111\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("00111000\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("00111001\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("00111010\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("00111011\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("00111100\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("00111101\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("00111110\n"));
  }else if(h == 0 && g ==0 && f == 1 && e ==1 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("00111111\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("01000000\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("01000001\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("01000010\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("01000011\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("01000100\n"));
    my_turn_left();
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("01000101\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("01000110\n"));
    my_steer_left_B();
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("01000111\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("01001000\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("01001001\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("01001011\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("01001100\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("01001101\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("01001110\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==0 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("01001111\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("01010000\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("01010001\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("01010010\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("01010011\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("01010100\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("01010101\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("01010110\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("01010111\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("01011000\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("01011001\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("01011010\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("01011011\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("01011100\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("01011101\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("01011110\n"));
  }else if(h == 0 && g ==1 && f == 0 && e ==1 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("01011111\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("01100000\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("01100001\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("01100010\n"));
    my_steer_right_F();
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("01100011\n"));
    my_front();
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("01100100\n"));
    my_steer_left_F();
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("01100101\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("01100110\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("01100111\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("01101000\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("01101001\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("01101010\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("01101011\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 1 && c == 1&& b == 0 && a == 0){
    Serial.print(F("01101100\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("01101101\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("01101110\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==0 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("01101111\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("01110000\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("01110001\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("01110010\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("01110011\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("01110100\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("01110101\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("01110110\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("01110111\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("01111000\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("01111001\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("01111010\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("01111011\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("01111100\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("01111101\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("01111110\n"));
  }else if(h == 0 && g ==1 && f == 1 && e ==1 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("01111111\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("10000000\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("10000001\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("10000010\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("10000011\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("10000100\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("10000101\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("10000110\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("10000111\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("10001000\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("10001001\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("10001010\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("10001011\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("10001100\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("10001101\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("10001110\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==0 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("10001111\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("10010000\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("10010001\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("10010010\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("10010011\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("10010100\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("10010101\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("10010110\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("10010111\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("10011000\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("10011001\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("10011010\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("10011011\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("10011100\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("10011101\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("10011110\n"));
  }else if(h == 1 && g ==0 && f == 0 && e ==1 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("10011111\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("10100000\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("10100001\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("10100010\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("10100011\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("10100100\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("10100101\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("10100110\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("10100111\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("10101000\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("10101001\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("10101010\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("10101011\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("10101100\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("10101101\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("10101110\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==0 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("10101111\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("10110000\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("10110001\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("10110010\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("10110011\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("10110100\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("10110101\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("10110110\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("10110111\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("10111000\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("10111001\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("10111010\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("10111011\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("10111100\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("10111101\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("10111110\n"));
  }else if(h == 1 && g ==0 && f == 1 && e ==1 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("10111111\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("11000000\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("11000001\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("11000010\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("11000011\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("11000100\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("11000101\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("11000110\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("11000111\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("11001000\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("11001001\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("11001010\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("11001011\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("11001100\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("11001101\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("11001110\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==0 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("11001111\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("11010000\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("11010001\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("11010010\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("11010011\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("11010100\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("11010101\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("11010110\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("11010111\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("11011000\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("11011001\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("11011010\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("11011011\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("11011100\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("11011101\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("11011110\n"));
  }else if(h == 1 && g ==1 && f == 0 && e ==1 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("11011111\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("11100000\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("11100001\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("11100010\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("11100011\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("11100100\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("11100101\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("11100110\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("11100111\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("11101000\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("11101001\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("11101010\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("11101011\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("11101100\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("11101101\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("11101110\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==0 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("11101111\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 0 && c == 0 && b == 0 && a == 0){
    Serial.print(F("11110000\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 0 && c == 0 && b == 0 && a == 1){
    Serial.print(F("11110001\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 0 && c == 0 && b == 1 && a == 0){
    Serial.print(F("11110010\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 0 && c == 0 && b == 1 && a == 1){
    Serial.print(F("11110011\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 0 && c == 1 && b == 0 && a == 0){
    Serial.print(F("11110100\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 0 && c == 1 && b == 0 && a == 1){
    Serial.print(F("11110101\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 0 && c == 1 && b == 1 && a == 0){
    Serial.print(F("11110110\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 0 && c == 1 && b == 1 && a == 1){
    Serial.print(F("11110111\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 1 && c == 0 && b == 0 && a == 0){
    Serial.print(F("11111000\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 1 && c == 0 && b == 0 && a == 1){
    Serial.print(F("11111001\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 1 && c == 0 && b == 1 && a == 0){
    Serial.print(F("11111010\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 1 && c == 0 && b == 1 && a == 1){
    Serial.print(F("11111011\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 1 && c == 1 && b == 0 && a == 0){
    Serial.print(F("11111100\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 1 && c == 1 && b == 0 && a == 1){
    Serial.print(F("11111101\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 1 && c == 1 && b == 1 && a == 0){
    Serial.print(F("11111110\n"));
  }else if(h == 1 && g ==1 && f == 1 && e ==1 && d == 1 && c == 1 && b == 1 && a == 1){
    Serial.print(F("11111111\n"));
    closs_count++;
  }
  */
 

#define NUMBER 8
#define THRESHOLD 50

double BINC(int j, int l){
  int i;
  int k[l];
  int kioku = l;
  while(l>0){
    k[l] = 0;
    l--;
  }
  kioku = l ;
  Serial.print("/");
  while(kioku>0){
    Serial.print(k[kioku]);
    kioku--;
    delay(500);
  }
  for(i =0; j > 0; i++){
    k[i] = j % 2;
    j = j / 2;
  }
  
    Serial.print("/");
  while(i>0){
    Serial.print("/");
    Serial.print(k[i]);
    i--;
    delay(500);
  }
  Serial.print("\n");
  delay(1000);
}


int trPin[NUMBER] = { A0, A1, A2, A3, A4, A5, A6, A7};
int LPIN[NUMBER] = { 46, 47, 48, 49, 50, 51, 52, 53};
int trace(int number, int threshold){// numberにはNUMBERを、thresholdにはTHRESHOLD
  //Serial.print(F("aaaa"));
  int x[number];//センサーの値を格納します
  int i = 0;
  double trace_point = 0;
  double old_trace_point = 0;
  Serial.print(F("\r\n"));
  for( i = 0; i < number; i++){//x[0]～x[NUMBER]
     Serial.print(i);
     Serial.print("ban");
     x[i] = analogRead( trPin[i]);
     Serial.print(x[i]);
     Serial.print(F(":"));
     delay(1000);
     if( x[i] < threshold){//trace_point←x[0]x[1]x[2]～x[7]
      digitalWrite( LPIN[i], HIGH);
      trace_point += pow(2,i);
      old_trace_point = trace_point;
     }else{
     digitalWrite( LPIN[i], LOW);
      old_trace_point = trace_point;
     }
  }
  Serial.print("/");
  Serial.print(trace_point);
  Serial.print("/");
  Serial.print((int)trace_point);
  Serial.print("/");
  Serial.print((int)trace_point);
  Serial.print("/");
  if( trace_point < 2^( number + 1)-1){//全部１ではないとき
    return trace_point;
  }else if(trace_point == 2^(number + 1) - 1){//全部1の時前回の値を返す
    return old_trace_point;
  }
}


void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  
  for(int i = 0; i < NUMBER; i++){
    pinMode(trPin[i],INPUT);
  } 
  
  for( int k = 0; k < 8; k++){
    pinMode( LPIN[k], OUTPUT);
    digitalWrite( LPIN[k], LOW);
  }
  delay(1000);
}
int a = 0;

void loop() {
  BINC(4,8);
  //trace(NUMBER,THRESHOLD);
  /*
  a  =analogRead(A0);
  if(a < 80){
    digitalWrite(12,HIGH);
  }else{
    digitalWrite(12,LOW);
  }
  Serial.print(a);
  Serial.print(F("\n"));
  delay(10);*/
}

// A相ピン割り当て
#define ENC_A 2
// B相ピン割り当て
#define ENC_B 3
double dt = 0;
double preTime = 0;
double old_velocity = 0;
int old_encValue = 0;
 
// B相の前回値
volatile int oldEncB;
 
// エンコーダ値
volatile long encValue;
 
void doEncoderCounter(void){
  int newEncB = digitalRead(ENC_B);
  int newEncA = digitalRead(ENC_A);
   
  if (newEncA){
    if (oldEncB && !newEncB) { // up
      ++encValue;
    } else { // down
      --encValue;
    }
  } else {
    if (oldEncB && !newEncB) { // down
      --encValue;
    } else { // up
      ++encValue;
    }
  }
  oldEncB = newEncB;
}
 
void setup() {
  pinMode(ENC_A, INPUT);
  pinMode(ENC_B, INPUT);
  encValue = 0;
  oldEncB = digitalRead(ENC_B);;
  attachInterrupt(0, doEncoderCounter, CHANGE);
  Serial.begin(115200);
  preTime = micros();
}
 
void loop() {
  old_velocity = (encValue - old_encValue)/ dt;
  Serial.print(F("kakudo :"));
  Serial.print(encValue,DEC);
  Serial.print(F("kakusokudo :"));
  delayMicroseconds(10);
  dt = (micros() - preTime)/1000000;
  Serial.print((encValue - old_encValue)/ dt);
  Serial.print(F("kakukasokudo :"));
  Serial.print((((encValue - old_encValue) - old_velocity)/ dt)/dt);
  preTime = micros();
  old_encValue = encValue;
  Serial.print("dt:");
  Serial.print(dt);
  Serial.print(F("\n"));
  delay(10);
}



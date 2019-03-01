// A相ピン割り当て
#define ENC_A 2
// B相ピン割り当て
#define ENC_B 3
float dt = 0;
float preTime = 0;

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
  Serial.println(encValue,DEC);
  delayMicroseconds(10);
  dt = micros() - preTime;
  Serial.print((encValue - old_encValue)/ dt);
  Serial.print(((encValue - old_encValue)/ dt)/dt);
  preTime = micros();
  old_encValue = encValue;
  //delay(1000);
}



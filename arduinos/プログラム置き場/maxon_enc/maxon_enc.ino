int ENC_A = 2;
int ENC_B = 3;
float dt = 0;
float preTime = 0;
int old_encValue = 0;
volatile int oldEncB;
volatile long encValue;
void doEncoderCounter(void){
  int newEncB = digitalRead(ENC_B);
  int newEncA = digitalRead(ENC_A);

  if (newEncA){
    if (oldEncB && !newEncB){
      encValue++;
    }else{
      encValue--;
    }
  }else{
    if(oldEncB &&!newEncB){
      encValue--;
    }else{
      encValue++;
    }
  }
  oldEncB = newEncB;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(ENC_A, INPUT);
  pinMode(ENC_B, INPUT);
  encValue = 0;
  oldEncB = digitalRead(ENC_B);
  attachInterrupt(0,doEncoderCounter, CHANGE);
  Serial.begin(115200);
  preTime = micros();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(encValue,DEC);
  delayMicroseconds(10);
  dt = micros() - preTime;
  Serial.print((encValue - old_encValue)/ dt);
  Serial.print(((encValue - old_encValue)/ dt)/dt);
  preTime = micros();
  old_encValue = encValue;
}

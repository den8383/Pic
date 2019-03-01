#include <TimerOne.h>
void timerFire(){
  Serial.print(F("timerfire"));
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Timer1.initialize(100);
  Timer1.attachInterrupt(timerFire);

}

void loop() {
  // put your main code here, to run repeatedly:

}

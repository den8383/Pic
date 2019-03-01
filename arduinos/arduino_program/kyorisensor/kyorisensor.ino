#include<kadai_robo.h>
int input_pin1 = A0;
void setup() {
  // put your setup code here, to run once:
  pinMode(input_pin1, INPUT);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(digitalRead(input_pin1));
  Serial.print(F("\n"));
  delay(10);

}

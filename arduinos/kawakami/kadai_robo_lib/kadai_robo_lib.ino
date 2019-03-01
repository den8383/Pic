#include "kadai_robo.h"


#define NUMBER 8
#define PWM_NUMBER 4
int motor_pin[NUMBER] = { 22, 23, 24, 25, 26, 27, 28, 29};
int pwm_pin[PWM_NUMBER] = { 12, 11, 10, 6};
int pwm_val[PWM_NUMBER]  = { 0, 0, 0, 0};
void setup() {
  Serial.begin(115200);
  set_output(NUMBER,motor_pin);
  pwm_val[0] = 255;
}


void loop() {
  // put your main code here, to run repeatedly:
  motor(pwm_val[0],motor_pin);
  Serial.print(pwm_val[0]);
  accel(&pwm_val[0],-1);
  delay(50);
}


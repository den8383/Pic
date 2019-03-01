#include <kadai_robo.h>


#define NUMBER 8
#define PWM_NUMBER 4
int motor_pin[NUMBER] = { 22, 23, 24, 25, 26, 27, 28, 29};
int pwm_pin[PWM_NUMBER] = { 13, 11, 10, 6};
int pwm_val[PWM_NUMBER]  = { 90, 0, 0, 0};
void setup() {
  Serial.begin(115200);
  K_set_motor(NUMBER,motor_pin);
  K_set_motor_pwm(PWM_NUMBER,pwm_pin);
}


void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(pwm_val[0]);
  Serial.print(F("\r\n"));
  motor(pwm_val[0],motor_pin,pwm_pin);
  acceleration(&pwm_val[0],-1);
  Serial.print(pwm_val[0]);
  Serial.print(F("\r\n"));
  delay(100);
}

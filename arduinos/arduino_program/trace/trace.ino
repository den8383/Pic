#include <kadai_robo.h>


#define TRACEHOLD 512
int output_pin[6] = {22,23,24,25,26,27};
double Kp = 1;
double Ki = 0;
double Kd = 0;
double dt = 0.01;
#define READ_PIN_NUMBER 6
int read_pin[READ_PIN_NUMBER] = { A0, A1, A2, A3, A4, A5};
int *trace_val;
void pid(double *p,  double *i, double *d, double target,double now){
  p[0] = target - now;
  i[0] = p[0] + i[0];
  d[0] = p[0]- d[0];
}
double target = TRACEHOLD;
double  trace_sum = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  set_input(READ_PIN_NUMBER,read_pin);
  set_output(6,output_pin);
  for(int i = 0;i < 6; i++){
    digitalWrite(output_pin[i],HIGH);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  double p[1] = {0};
  double i[1] = {0};
  double d[1] = {0};
  double PID = 0;
  trace_val = trace(READ_PIN_NUMBER,read_pin);
  for(int i = 0; i < READ_PIN_NUMBER; i++){
    Serial.print(F("["));
    Serial.print(trace_val[i]);
    Serial.print(F("]"));
  }
  trace_sum = ((-4)*0+(-2)*0+(-1)*0+1*trace_val[3]+2*trace_val[4]+4*trace_val[5]);
  Serial.print(F("now["));
  Serial.print(trace_sum);
  Serial.print(F("]"));
  pid(p,i,d,target,trace_sum);
  PID = Kp**p+Ki**i+Kd**d;
  Serial.print(F("PID"));
  Serial.print(PID);
  Serial.print(F("\r\n"));
  delay(2000);

}

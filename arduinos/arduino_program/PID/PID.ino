

void pid(double *p,  double *i, double *d, double target,double sensor_val){
  p[0] = target - sensor_val;
  i[0] = p[0] + i[0];
  d[0] = p[0]- d[0];
}
double *p, *i, *d; 
double sensor_val = 0;
double target = 512;
double dt = 0.01;
double PID = 0;
void setup() {
  // put your setup code here, to run once:
  pid(p,i,d,target,sensor_val);
  PID = *p + *i + *d;

}

void loop() {
  // put your main code here, to run repeatedly:

}

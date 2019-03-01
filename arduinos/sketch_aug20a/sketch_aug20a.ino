
const int LED = 9;
const int BUTTON = 7;
int i=0;
int val = 0;
int old_val = 0;
int state  = 0;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BUTTON,INPUT);
}

void loop() {
  digitalRead(BUTTON);
  val=digitalRead;
  for(i=0;i<=255;i++){
    
    if((val==HIGH)&&(old_val==LOW)){
      state=1-state;
    }
    if(state==1){
       analogWrite(LED,i);
       delay(10);
    }
    old_val=val;
  }
  for(i = 255; i>0; i--){
    if((val==HIGH)&&(old_val==LOW)){
      state=1-state;
    }

    if(state==1){
    analogWrite(LED,i);
    delay(10);
     }
  }
} 


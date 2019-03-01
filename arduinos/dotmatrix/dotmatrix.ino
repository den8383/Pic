void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i <= 17; i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
  

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int j = 2; j <= 9; j++){
    digitalWrite(j, HIGH);
    for(int k = 10; k <= 17; k++){
      digitalWrite(k, LOW);
      delay(500);
      digitalWrite(k,HIGH);
    }
  digitalWrite(j, LOW);
  }
}

int  n = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(45); // 1バイトのデータ(45)を送信
  //n = Serial.read();
  Serial.println(n);
}


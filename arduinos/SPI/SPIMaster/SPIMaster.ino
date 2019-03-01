/*
 * SPIマスタ
 * SS   - Pin10
 * MOSI - Pin11
 * MISO - Pin12
 * SCK  - Pin13
 */
 
#include <SPI.h>
 
#define SSPin 10
 
void setup() {
  Serial.begin (9600); 
  Serial.println("Master");
 
  pinMode(SS,OUTPUT); //SSピンを出力設定
 
  SPI.setBitOrder(MSBFIRST);  //最上位ビット(MSB)から送信
  SPI.setClockDivider(SPI_CLOCK_DIV4);  //通信速度をデフォルト
  SPI.setDataMode(SPI_MODE2);   //アイドル5Vで0V→5Vの変化で送信する
  SPI.begin();  //開始
}
 
void loop() {
  byte snd;
  byte rcv;
 
  //UARTから読み込み
  snd = Serial.read();
 
  //データがあれば送信
  if(snd != -1){
 
    //このSlaveをセレクトする
    //（マスタ通信は有効です）
    SetSSPin(LOW);
 
    //送信
    snd = 100;
 
    //受信
 
    //データ確認
    Serial.print(F("snd:"));
    Serial.print(snd);
    Serial.print(F("rcv:"));
    Serial.print(SPI.transfer(snd));
    Serial.print(F("\n"));
  }
}
 
/*
 * SSピンの設定
 * Lowでマスタからの通信が有効（セレクト）
 * (Highではマスタから通信出来ない(無視される）セレクト解除の状態)
 */
void SetSSPin(int val)
{ 
    digitalWrite(SSPin, val); 
}


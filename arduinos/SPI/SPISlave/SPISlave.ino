/*
 * SPIスレーブ
 * SS   - Pin10
 * MOSI - Pin11
 * MISO - Pin12
 * SCK  - Pin13
 */
 
#include <SPI.h>
  byte sd = 0;
  byte rd = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(MISO,OUTPUT); //MISOを出力
 
  SPI.setBitOrder(MSBFIRST);  //最上位ビット(MSB)から送信
  SPI.setClockDivider(SPI_CLOCK_DIV4);  //通信速度をデフォルト
  SPI.setDataMode(SPI_MODE2);   //アイドル5Vで0V→5Vの変化で送信する
  SPCR |= _BV(SPE);
     
  SPI.attachInterrupt(); 
}
 
// SPI割り込み処理
ISR(SPI_STC_vect)
{
  rd = SPDR;    //SPIの受信バッファから取得
  Serial.print(F("rd:"));
  Serial.print(SPDR);
  SPDR = 78;  //送信バッファに書き込む
  sd = SPDR;
  Serial.print(F("sd"));
  Serial.print(sd);
  Serial.print(F("\n"));
}
 
void loop() {
  // put your main code here, to run repeatedly:
}


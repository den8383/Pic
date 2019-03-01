#include "Arduino.h"
#include "SpiConS.h"
#include <SPI.h>
#define SS_PIN 10
#define SCK_PIN 13
#define MISO_PIN 12
#define MOSI_PIN 11


SpiConS::SpiConS(void){
  
}

void SpiConS::setUp(void){
  Serial.begin(115200);
  while (!Serial)
  
  pinMode(SS_PIN,INPUT);
  pinMode(SCK_PIN,INPUT);
  pinMode(MISO_PIN,OUTPUT);
  pinMode(MOSI_PIN,INPUT);

  SPCR &= ~_BV(4);    //スレーブ設定
  
  SPCR |= _BV(6);   //SPI有効

  SPI.attachInterrupt();    //SPI割り込み有効
  
  
}

void SpiConS::task(void){
  if(spi_flag){
    Serial.print("read:");
    Serial.print(MOSI_Byte);
    Serial.print(" : sent:");
    Serial.print(MISO_Byte);
    Serial.println();

    spi_flag = false;
  }
}
void SpiConS::Inter(){

  MOSI_Byte = SPDR;   //受信データ

//  MISO_Byte_ = MISO_Byte;   //表示用
  MISO_Byte = MOSI_Byte;    //折り返し
    
  SPDR = MISO_Byte;   //送信データセット

  spi_flag = true;    //表示フラグ
  
}

//



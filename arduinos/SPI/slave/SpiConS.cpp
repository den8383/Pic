#include "Arduino.h"
#include "SpiConS.h"
#include <SPI.h>
#define UNO 0
#define MEGA 1


SpiConS::SpiConS(int board){
  if(board == UNO){
    SS_PIN = 10;
    SCK_PIN = 13;
    MISO_PIN = 12;
    MOSI_PIN = 11;
  } else if(board == MEGA){
    SS_PIN = 53;
    SCK_PIN = 52;
    MISO_PIN = 50;
    MOSI_PIN = 51;
  }
  
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



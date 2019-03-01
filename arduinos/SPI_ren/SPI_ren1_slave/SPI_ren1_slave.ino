/**********************************************
Arduino nano SPI(sleave)
**********************************************/
#include <SPI.h>
#define SS_PIN 10
#define SCK_PIN 13
#define MISO_PIN 12
#define MOSI_PIN 11
int inByte  = 0;
int SPIdata = 0;
int data    = 0;
byte MOSI_Byte = 0;
byte MISO_Byte = 0;
byte MISO_Byte_ = 0;
int spi_flag = 0;
void setup() {
  Serial.begin(9600);
  while (!Serial)
  
  pinMode(SS_PIN,INPUT);
  pinMode(SCK_PIN,INPUT);
  pinMode(MISO_PIN,OUTPUT);
  pinMode(MOSI_PIN,INPUT);

  SPCR &= ~_BV(4);    //スレーブ設定
  
  SPCR |= _BV(6);   //SPI有効

  SPI.attachInterrupt();    //SPI割り込み有効
  
  Serial.println("/-----START Arduino nano-----/");
  Serial.println("/----------SPI Slave---------/");
}
void loop() {
  if(spi_flag){
    Serial.print("read:");
    Serial.write(MOSI_Byte);
    Serial.print(" : sent:");
    Serial.write(MISO_Byte_);
    Serial.println();

    spi_flag = false;
  }
}
//SPI割り込み
ISR(SPI_STC_vect){

  MOSI_Byte = SPDR;   //受信データ

  MISO_Byte_ = MISO_Byte;   //表示用
  MISO_Byte = MOSI_Byte;    //折り返し
    
  SPDR = MISO_Byte;   //送信データセット

  spi_flag = true;    //表示フラグ
}


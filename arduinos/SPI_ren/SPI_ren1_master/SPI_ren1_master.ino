/**********************************************
Arduino nano SPI(Master)
**********************************************/
#include <SPI.h>
#define SS_PIN 10
int inByte  = 0;
int SPIdata = 0;
int data    = 0;
byte MOSI_Byte = 0;
byte MISO_Byte = 0;
void setup() {
  Serial.begin(9600);
  while (!Serial)
  
  pinMode(SS_PIN,OUTPUT);

  SPI.setClockDivider(SPI_CLOCK_DIV128);  //fosc/128
  
  SPI.begin();    //SPI有効

  Serial.println("/-----START Arduino UNO-----/");
  Serial.println("/---------SPI Master--------/");
  Serial.println("/-------Default DIV128------/");

  delay(100);
}
void loop() {
  if(Serial.available() > 0) {
    inByte = Serial.read();

    /**************************************
     送信速度変更
     '1' = fosc / 2 ※スレーブ側対応しません
     '2' = fosc / 4
     '3' = fosc / 8
     '4' = fosc / 16
     '5' = fosc / 32
     '6' = fosc / 64
     '7' = fosc / 128
     上記以外はMOSI送信に使用
     **************************************/
    switch(inByte){
      case '1':
        SPI.setClockDivider(SPI_CLOCK_DIV2);
        Serial.println("DIV2");
        break;
       case '2':
        SPI.setClockDivider(SPI_CLOCK_DIV4);
        Serial.println("DIV4");
        break;
       case '3':
        SPI.setClockDivider(SPI_CLOCK_DIV8);
        Serial.println("DIV8");
        break;
       case '4':
        SPI.setClockDivider(SPI_CLOCK_DIV16);
        Serial.println("DIV16");
        break;
       case '5':
        SPI.setClockDivider(SPI_CLOCK_DIV32);
        Serial.println("DIV32");
        break;
       case '6':
        SPI.setClockDivider(SPI_CLOCK_DIV64);
        Serial.println("DIV64");
        break;
       case '7':
        SPI.setClockDivider(SPI_CLOCK_DIV128);
        Serial.println("DIV128");
        break;
       default:
        MOSI_Byte = inByte;
    }
  }

  if(MOSI_Byte){
    Serial.print("sent:");
    Serial.write(MOSI_Byte);
    
    digitalWrite(10, LOW);    //SS 有効
    MISO_Byte = SPI.transfer(MOSI_Byte);    //送受信処理
    digitalWrite(10, HIGH);   //SS 終了

    Serial.print(" : read:");
    Serial.write(MISO_Byte);
    Serial.println();

    MOSI_Byte = 0;
    MISO_Byte = 0;
  }
}


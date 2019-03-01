#include "Arduino.h"
#include "SpiConS.h"
#include <SPI.h>


SpiConS::SpiConS(void)
{
    SPI.begin();
    pinMode(SS_PIN,INPUT);
    pinMode(SCK_PIN,INPUT);
    pinMode(MISO_PIN,OUTPUT);
    pinMode(MOSI_PIN,INPUT);
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE1);
    SPCR &= ~_BV(4);    //スレーブ設定
    SPCR |= _BV(6);   //SPI有効
    SPI.attachInterrupt();    //SPI割り込み有効
}

void SpiConS::RS()
{
  m_sendData = sData;
  m_receiveData = SPI.transfer(m_sendData);
  rData = m_receiveData;
}

void SpiConS::Task()
{
  if(m_spiFlag){
    m_spiFlag = false;
  }
}

void SpiConS::Print()
{
  
    Serial.print(F("sData="));
    Serial.print(sData);
    Serial.print(F(";"));
    Serial.print(F("rData="));
    Serial.print(rData);
}




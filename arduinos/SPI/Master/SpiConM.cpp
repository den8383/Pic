#include "Arduino.h"
#include "SpiConM.h"
#include <SPI.h>
#define UNO 0
#define MEGA 1


SpiConM::SpiConM(int board)
{
    m_board = board;
    setUp();
}

void SpiConM::setUp(){
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);
    if(m_board == UNO){
      SCK_PIN = 13;
      MISO_PIN = 12;
      MOSI_PIN = 11;
      SSPIN = 10;
    }else if(m_board == MEGA){
      SSPIN = 53;
      SCK_PIN = 52;
      MISO_PIN = 50;
      MOSI_PIN = 51;
    }
    digitalWrite(SSPIN,HIGH);
    digitalWrite(SSPIN,LOW);
  
}

void SpiConM::End(){
    SPI.end();
}

void SpiConM::RS()
{
  m_sendData = sData;
  m_receiveData = SPI.transfer(m_sendData);
  rData = m_receiveData;
}
void SpiConM::Print()
{
  
    Serial.print(F("sData="));
    Serial.print(sData);
    Serial.print(F(";"));
    Serial.print(F("rData="));
    Serial.print(rData);
}


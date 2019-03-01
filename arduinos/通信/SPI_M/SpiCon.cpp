#include "Arduino.h"
#include "SpiCon.h"
#include <SPI.h>


SpiCon::SpiCon(int SS_PIN)
{
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);
    m_SS_PIN = SS_PIN;

    pinMode(m_SS_PIN, OUTPUT);
    digitalWrite(m_SS_PIN, HIGH);
}

void SpiCon::RS()
{
  m_sendData = sData;
  digitalWrite(m_SS_PIN, LOW);
  m_receiveData = SPI.transfer(m_sendData);
  digitalWrite(m_SS_PIN, HIGH);
  rData = m_receiveData;
}
void SpiCon::Print()
{
  
    Serial.print(F("sData="));
    Serial.print(m_sendData);
    Serial.print(F(":"));
    Serial.print(F("rData="));
    Serial.print(m_receiveData);
}


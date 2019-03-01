#include "Arduino.h"
#include "SpiConM.h"
#include <SPI.h>
#define SCK_PIN 13
#define MISO_PIN 12
#define MOSI_PIN 11


SpiConM::SpiConM(int SSPIN)
{
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);
    digitalWrite(SSPIN,HIGH);
    digitalWrite(SSPIN,LOW);

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


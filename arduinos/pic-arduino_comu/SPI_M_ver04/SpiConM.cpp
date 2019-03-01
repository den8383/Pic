#include "Arduino.h"
#include "SpiConM.h"
#include <SPI.h>


SpiConM::SpiConM(void)
{
    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);

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


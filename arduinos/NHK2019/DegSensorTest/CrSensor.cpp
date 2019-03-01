#include "Arduino.h"
#include "CrSensor.h"

CrSensor::CrSensor(int ReadPin)
{
  m_ReadPin = ReadPin;
  pinMode(m_ReadPin,INPUT);
}

void CrSensor::TraceD()
{
  m_TrValueD = digitalRead(m_ReadPin);
}

void CrSensor::TraceA(int TraceHold)
{
  m_TrValueA = analogRead(m_ReadPin);
  if(m_TrValueA >= TraceHold)
  {
    m_TrValueD = 1;
  }
  else
  {
    m_TrValueD =0;
  }
}

void CrSensor::PrintD()
{
  Serial.print(F("TrValuD = "));
  Serial.print(m_TrValueD);
  Serial.print(F(";"));
}

void CrSensor::PrintA()
{
  Serial.print(F("TrValuA = "));
  Serial.print(m_TrValueA);
  Serial.print(F(";"));
}


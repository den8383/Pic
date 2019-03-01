#include <SPI.h>

#define SS_PIN 10

void setup()
{
    Serial.begin(9600);

    pinMode(SS_PIN, OUTPUT);
    digitalWrite(SS_PIN, HIGH);

    SPI.begin();
    SPI.setBitOrder(MSBFIRST);
    SPI.setDataMode(SPI_MODE0);
}

char msg[100];
byte i, n;

void loop()
{
    digitalWrite(SS_PIN, LOW);
    n = SPI.transfer(i);
    digitalWrite(SS_PIN, HIGH);

    sprintf(msg, "%d/%d, ", n, i);
    Serial.print(msg);
}

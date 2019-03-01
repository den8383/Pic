#include "Arduino.h"
#include "dotMatrix.h"

dotMatrix::dotMatrix(int Num)
{
  for(int j = 2; j <= 9; j++){
    pinMode(j,OUTPUT);
    digitalWrite(j,LOW);
  }
  for(int k = 10; k <= 17; k++){
    pinMode(k,OUTPUT);
    digitalWrite(k,HIGH);
  }
}


void dotMatrix::inTurn(int Time){
  
  for(int j = 2; j <= 9; j++){
    digitalWrite(j, HIGH);
    for(int k = 10; k <= 17; k++){
      digitalWrite(k, LOW);
      delay(Time);
      digitalWrite(k,HIGH);
    }
  digitalWrite(j, LOW);
  }
}

void dotMatrix::draw(int Time){
  int x = 0;
  int y = 0;
  
  for(x = 0; x <= 7; x++){
    digitalWrite(x+2,HIGH);
    for(y = 0; y <= 7; y++){
      if(m_screen[x][y] == 1){
        digitalWrite(y+10,LOW);
        delay(Time);
        digitalWrite(y+10,HIGH);
      }else{
        digitalWrite(y+10,HIGH);
      }
      delay(Time);
    }
    digitalWrite(y+10,HIGH);
    digitalWrite(x+2,LOW);
  }
}

void dotMatrix::smileFace(int Time)
{
  for(int y = 0; y < 8; y++){
    for(int x = 0; x < 8; x++){
      m_screen[x][y] = m_smileScreen[x][y];
    }
  }
  draw(Time);
}

void dotMatrix::sadFace(int Time){
  for(int y = 0; y < 8; y++){
    for(int x = 0; x < 8; x++){
      m_screen[x][y] = m_sadScreen[x][y];
    }
  }
  draw(Time);
}


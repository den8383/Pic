/**********************************************
Arduino nano SPI(sleave)
**********************************************/

#include<pic.h>
#define SS_PIN RA0
#define SCK_PIN RA1
#define MISO_PIN RA2
#define MOSI_PIN RA3
#define false 0;
int inByte  = 0;
int SPIdata = 0;
int data    = 0;
unsigned char MOSI_Byte = 0;
unsigned char MISO_Byte = 0;
unsigned char MISO_Byte_ = 0;
int spi_flag = 0;



//__CONFIG(CLKOUTEN_OFF & FOSC_INTOSC & FCMEN_OFF & IESO_OFF & BOREN_ON &
//         PWRTE_ON & WDTE_OFF & MCLRE_OFF & CP_OFF & CPD_OFF) ;
#pragma config CLKOUTEN = OFF
#pragma config FOSC = INTOSC
#pragma config FCMEN = OFF
#pragma config IESO = OFF
#pragma config BOREN = ON
#pragma config PWRTE = ON
#pragma config WDTE = OFF
#pragma config MCLRE = OFF
#pragma config CP = OFF
#pragma config CPD = OFF


void LED(){
     PORTB =  0b00001000 ;
}
void LED_OFF(){
     PORTB =  0b00000000 ;
}

void interrupt InterSPI( void )
{
     if (SSP1IF == 1) {         // ??????????
          MOSI_Byte = SSPBUF ;
          MISO_Byte = MISO_Byte;
          SSPBUF = MISO_Byte;
          SSP1IF = 0 ;          // ??????????
          LED_OFF();
     }
}





void loop() {
  while(1){
    if(spi_flag){
      spi_flag = false;
    }
  }
}


int main(int argc, char** argv){
    
  
  //pinMode(SS_PIN,INPUT);
  //pinMode(SCK_PIN,INPUT);
  //pinMode(MISO_PIN,OUTPUT);
  //pinMode(MOSI_PIN,INPUT);


     OSCCON = 0b01101010 ;     // ??????????????
     ANSELA = 0b00000000 ;     // ??????????????????I/O??????
     TRISA  = 0b00000100 ;     // RA2??????????????(RA3?????)
     PORTA  = 0b00000000 ;     // ????????(??LOW???)
     TRISB  = 0b00000000 ;
     PORTB  = 0b00000000 ;
     

  //SPCR &= ~_BV(4);    //??????
  
  //SPCR |= _BV(6);   //SPI??

  //SPI.attachInterrupt();    //SPI??????
  
  //Serial.println("/-----START Arduino nano-----/");
  //Serial.println("/----------SPI Slave---------/");
     SDO1SEL   = 1 ;            // 3???(RA4)?SDO?????
     SSP1CON1 = 0b00100001 ;   // ???????LOW????????FOSC/16????????
     SSP1STAT = 0b00000000 ;   // ?????????????(0V)??????(5V)????????*2)
     SSP1IF = 0 ;              // ????????????????
     SSP1IE = 1 ;              // ????????????
     PEIE   = 1 ;              // ?????????
     GIE    = 1 ;              // ???????????
     LED();

     loop();

}
//SPI????




//ISR(SPI_STC_vect){
//
//  MOSI_Byte = SPDR;   //?????
//
//  MISO_Byte_ = MISO_Byte;   //???
// MISO_Byte = MOSI_Byte;    //????
//   
//  SPDR = MISO_Byte;   //????????
//
//  spi_flag = true;    //?????
//}

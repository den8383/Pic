/*******************************************************************************
*  slave.c - ???????????????                                    *
*                                                                              *
*  ???????????????????????????????????      *
*  ??????????????????????????                        *
*  ?????????skI2Cslave.c?skMonitorLCD.c?????????            *
* ============================================================================ *
*  VERSION DATE        BY                    CHANGE/COMMENT                    *
* ---------------------------------------------------------------------------- *
*  1.00    2012-01-05  ?????(????)  Create                            *
* ============================================================================ *
*  PIC 12F1822                                                                 *
*  HI-TECH C Compiler for PIC10/12/16 MCUs Version 9.80 in Lite mode           *
*******************************************************************************/
#include <pic.h>
#include <htc.h>                        // delay????
#include "skI2Cslave.h"                 // I2C????????
#include "skMonitorLCD.h"               // LCD?????
//#include "encoder1.h"

#define _XTAL_FREQ   8000000            // delay????(????8MHz???)

void enc(void){
    
     
    RB4 = 1;
    volatile long encValue = 0;
    int newEncA = 0;
    int newEncB = 0;
    volatile int oldEncB = 0;
    
    newEncA = RB0;
    newEncB = RA2;

    if (newEncA)
    {
      if (oldEncB && !newEncB) 
      { // up
        ++encValue;
        RB3 = 1;
      } 
      else 
      { // down
        --encValue;
        RB3 = 1;
      }
    }
    else 
    {
       if (oldEncB && !newEncB) 
       { // down
        --encValue;
        RB3 = 0;
       }
       else
       { // up
        ++encValue;
        RB3 = 0;
       }
    }
    oldEncB = newEncB;

    
	// LED1????
   
	// ????????????
    if(INTEDG == 1)
    {
        INTEDG = 0;
    }else
    {
        INTEDG = 1;
    }
	INTF = 0;
    RB4 = 0;
    count = encValue;
}


void InitInterExt (void)
{
	// RB0??????????
	TRISB0 = 1;
    TRISA2 = 1;
	
	// ???????????????
	INTEDG = 1;
	
	// ????????????
	INTF = 0;
	
	// ????????
	INTE = 1;

}

// ???????????????
// CLKOUT????RA4????????(CLKOUTEN_OFF)???????????(INTIO)
// ???????????(FCMEN_OFF)?????????????????????(IESO_OFF)
// ????????????ON(BOREN_ON)????????????????(WDTE_OFF)
// ??ON??64ms??????????????(PWRTEN_ON)
// ??????????????????????(RA3)??????(MCLRE_OFF)
// ?????????????????(CP_OFF)???????????????(CPD_OFF)
/*__CONFIG(CLKOUTEN_OFF & FOSC_INTOSC & FCMEN_OFF & IESO_OFF & BOREN_ON &
         PWRTE_ON & WDTE_OFF & MCLRE_OFF & CP_OFF & CPD_OFF) ;*/
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
// ???????????????
// ???????32MHz????????(PLLEN_OFF)
// ?????????????????????????????(STVREN_ON)
// ?????????????????(LVP_OFF)
// Flash??????????(WRT_OFF)?????????????(2.5V)??(BORV_25)
/*__CONFIG(PLLEN_OFF & STVREN_ON & WRT_OFF & BORV_25 & LVP_OFF);*/
#pragma config PLLEN = OFF
#pragma config STVREN = ON
#pragma config WRT = OFF
#pragma config BORV = 25
#pragma config LVP = OFF

/*******************************************************************************
*  ??????                                                                *
*******************************************************************************/
void main()
{
     int ans ;

     OSCCON  = 0b01110010 ;   // ???????8??????
     ANSELA  = 0b00000000 ;   // ?????????(???????I/O?????)
     //ANSELB  = 0b00000000 ;     // AN5-AN11????????????I/O???
     TRISA   = 0b00001110 ;   // ???RA1(SCL)/RA2(SDA)????(RA3?????)
     TRISB   = 0b00010010 ;
     PORTA   = 0b00000000 ;   // ????????(??LOW???)
     PORTB   = 0b00000000 ;
     
     

     InitI2C_Slave(8) ;       // ????????????????????8???

     __delay_ms(2000) ;
     //MonitorPutc(0x11) ;      // ??????????????
     count = 9;
     GIE = 1;

     while(1) {
         //InterI2C();
	      InitInterExt();//ori
          //GIE = 1;//ori
          ans = I2C_ReceiveCheck() ;              // ?????????
          if (ans != 0) {
               MonitorPutc(rcv_data[0]) ;         // ?????????
               //enc();
               snd_data[0] = count;
               //snd_data[0] = rcv_data[0]+0x11 ;   // ???????????
               
          }
     }
}

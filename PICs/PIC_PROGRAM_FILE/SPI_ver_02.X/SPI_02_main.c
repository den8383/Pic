#include <xc.h>
//#include "skMonitorLCD.h"      // ???LCD???????

#define _XTAL_FREQ  20000000   // delay?(????20MHz????)

unsigned int RCV_Buff ;
int Flag ;

// ???????(DEBUGDIS):?????????????????(LVPDIS)
// ?????????(UNPROTECT):??????????????????????(RA5)??????(MCLRDIS)
// ????????????ON(BOREN)???ON??72ms????????????(PWRTEN)
// ????????????(WDTDIS)????????????(HS)
//__CONFIG(DEBUGDIS & LVPDIS & UNPROTECT & MCLRDIS & BOREN & PWRTEN & WDTDIS & HS) ;

//#pragma config DEBUGE = ON
#pragma config LVP = OFF
#pragma config WRT = OFF
#pragma config MCLRE= OFF
#pragma config BOREN = ON
#pragma PWRTEN = ON
#pragma config WDTE = OFF
#pragma confif HS = ON


// ?????????
void interrupt InterSPI( void )
{
     if (SSP1IF == 1) {         // ??????????
          RCV_Buff = SSPBUF ;
          Flag = 1 ;
          SSP1IF = 0 ;          // ??????????
          //
          RA1= 1;
          //
     }
}
// ??????
void main()
{
     ADCON1 = 0b00000110 ;     // ???????????RA0-RA4?????I/O???
     TRISA  = 0b00000000 ;     // 1??? 0??? RA0-RA7???????(RA5?????)
     TRISB  = 0b00010010 ;     // 1:in 0:out SDI(RB1:in) SDO(RB2:out) SCK(RB4:in) SS(RB5:?)
     PORTA  = 0b00000000 ;     // ????????(??LOW???)
     PORTB  = 0b00000000 ;     // ????????(??LOW???)z

     // SPI??????????
     SDO1SEL = 0;
     SSPCON = 0b00100101 ;     // ???????LOW???????????????
     SSPSTAT= 0b00000000 ;     // ????????(??????????)?*4)
     SSP1IF= 0 ;                // ????????????????
     SSP1IE= 1 ;                // ????????????
     PEIE = 1 ;                // ?????????
     GIE  = 1 ;                // ???????????
     Flag = 0 ;

     // LCD?????????????????*3)
//     MonitorInit() ;

     while(1) {
     //    RA1=0;
	     if (Flag == 1) {
               // ????????????????????
//               MonitorPutc(0x11) ;
//               MonitorPuts("        ") ;
//               MonitorPutc(0x11) ;
//               MonitorPutc(RCV_Buff) ;
               Flag = 0 ;
          }
     }
}

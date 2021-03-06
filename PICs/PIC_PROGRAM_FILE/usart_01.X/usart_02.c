
#include <xc.h>
#include <stdbool.h>    // bool???????????
#pragma config FOSC = INTOSC // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin) 
#pragma config WDTE = OFF // Watchdog Timer Enable (WDT disabled) 
#pragma config PWRTE = ON // Power-up Timer Enable (PWRT enabled) 
#pragma config MCLRE = OFF // MCLR Pin Function Select (MCLR/VPP pin function is MCLR) 
#pragma config CP = OFF // Flash Program Memory Code Protection (Program memory code protection is disabled) 
#pragma config CPD = OFF // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = OFF // Brown-out Reset Enable (Brown-out Reset disabled) 
#pragma config CLKOUTEN = OFF // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin) 
#pragma config IESO = OFF // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled) // ??????????BIT2 ?? 
#pragma config WRT = OFF // Flash Memory Self-Write Protection (Write protection off) 
#pragma config PLLEN = ON // PLL Enable (4x PLL enabled) 
#pragma config STVREN = ON // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset) 
#pragma config BORV = HI // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), high trip point selected.) 
#pragma config LVP = OFF // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming) 
unsigned char rx_data = 0; 
bool rx_flg = false; // ??????????? // ???????????????? 
void interrupt rx_uart0( void ) 
{
    if( RCIF )
    {
        rx_data = RCREG; // ??????????? 
        rx_flg = true;RCIF = 0; // ???????????? 
    } 
} 
int main(int argc, char** argv) 
{
  OSCCON = 0b01110000 ; // ??????8??? ANSELA = 0b00000000 ; // ???????I/O????? 
  TRISA = 0b00101000 ; // RA3,5?????? 
  PORTA = 0b00000000 ; // ???????  
  RXDTSEL = 1; // RA5?????? 
  TXCKSEL = 1; // RA4?????? 
  TXSTA = 0x24; // ???/8???/?????? 
  RCSTA = 0x90; // ?????????/?????? 
  BAUDCON = 0x08; // 16bit??? // 16Bit?????? 
  SPBRG = 0x40; // ??????9600???(??8bit)
  SPBRGH = 0x03; // ??????9600???(??8bit)
  RCIF = 0; // ????????????????? 
  RCIE = 1; // ????????????? 
  PEIE = 1; // ?????????? 
  GIE = 1; // ????????? 
  for(;;){// ?????????? 
      if( rx_flg )
      {// ?????? 
          if( TXIF )
          {
              TXREG = rx_data; // ???????????????? 
              rx_flg = false;
          }
      }
  }
return 0; 
} 
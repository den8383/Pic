#include <xc.h>

#pragma config FOSC = INTOSC    // Inner clock
#pragma config WDTE = OFF       // Watchdog timer
#pragma config PWRTE = OFF      // Power-Up timer
#pragma config MCLRE = ON       // MCLR pin
#pragma config CP = OFF         // Code protection
#pragma config CPD = OFF        // Memory protection
#pragma config BOREN = ON       // Brown-out Reset
#pragma config CLKOUTEN = OFF   // Outer clock
#pragma config IESO = OFF       // Oscillator switchover
#pragma config FCMEN = OFF      // Fail-Safe clockmonitor

#pragma config WRT = OFF        // Power-up Timer
#pragma config PLLEN = ON       // Use 4xPLL
#pragma config STVREN = OFF     // Reset when stack error
#pragma config LVP = OFF        // Low voltage program

#define _XTAL_FREQ 32000000 // 32MHz
unsigned char count = 0;

void interrupt OnInterSpi()
{
    if (SSP1IF == 1){
        SSP1IF = 0;

        unsigned char read_data = SSP1BUF;
        if(count == 255) count = 0; else count++;
        SSP1BUF = count;
    }
}

void main(void)
{
    OSCCON = 0b00110100;    

    ANSELA = 0b00000000;    
    TRISA = 0b00000001;     
    PORTA = 0b00000000;     


    ANSELB = 0b00000000;
    TRISB = 0b00010010;     
    PORTB = 0b00000000;     

    SDO1SEL = 0;             
    SSP1CON1 = 0b00100100;    
    SSP1STAT = 0b01000000;    

    SSP1IF = 0;  
    SSP1IE = 1;  
    PEIE = 1;   
    GIE = 1;   

    while(1) ;
}
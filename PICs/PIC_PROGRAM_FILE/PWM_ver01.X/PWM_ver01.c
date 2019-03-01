// ????????
// PIC16F1827
 
// CCP3?CCP4???????PWM???????
// CCP3 - ????
// CCP4 - ????
 
#include <xc.h>
#include <stdbool.h>    // bool???????????
 
// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)
 
// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = HI        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), high trip point selected.)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)
 
//?delay_ms(x) ??????
#define _XTAL_FREQ 8000000


unsigned char PWM = 00000000;
 
// ????????
bool InitDevice();                         // ????????? 
bool ChangeRightMotorSpeed(int per);     // ????????????
 
int main(void)
{
    // ???????
    if(!InitDevice()){
        // ??????
        return 0;
    }
    
    while(1)
    {
        ChangeRightMotorSpeed(PWM);
        __delay_ms(1000);
        for(PWM = 0;PWM < 255; PWM++)
        {
            
        }
        
        
    }
    
    return 0;
}
 
 
// ?????????
bool InitDevice()
{
    // ???????
    OSCCON = 0b01110010;    // ?????8MHz???
    
    // ????????????
    TRISA = 0b00000000;
    TRISB = 0b00000000;
    
    // ????????????????
    ANSELA = 0b00000000;
    ANSELB = 0b00000000;
    
    // CCP?????????
    CCP3CON = 0b00001100;   // CCP3?PWM?????????CCPR3L???2????0????
    CCP4CON = 0b00001100;   // CCP4?PWM?????????CCPR4L???2????0????
    
    // CCP??????????
    CCPTMRS = 0b00000000;   // CCP3?CCP4?????????Timer2
    
    // ??????
    T2CON = 0b00000100;     // TIMER2??????????????????
    PR2 = 255;              // PWM Period?1.28 * 10^4(= (255(PR2) + 1) * 1 / 8000000(CLOCK) * 1(Prescale))
    
    return true;
}
 
 
// ????????????
bool ChangeRightMotorSpeed(int pwm)
{
            CCPR3L = pwm;
    return true;
}
 


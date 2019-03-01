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
 
// ????????
bool InitDevice();                         // ????????? 
bool ChangeRightMotorSpeed(int per);     // ????????????
bool ChangeLeftMotorSpeed(int per);      // ????????????
 
int main(void)
{
    // ???????
    if(!InitDevice()){
        // ??????
        return 0;
    }
    
    while(1)
    {
        // ?????????0%???
        ChangeRightMotorSpeed(0);
        ChangeLeftMotorSpeed(0);
        __delay_ms(1000);
        
        // ?????????10%???
        ChangeRightMotorSpeed(10);
        ChangeLeftMotorSpeed(10);
        __delay_ms(1000);
        
        // ?????????20%???
        ChangeRightMotorSpeed(20);
        ChangeLeftMotorSpeed(20);
        __delay_ms(1000);
        
        // ?????????30%???
        ChangeRightMotorSpeed(30);
        ChangeLeftMotorSpeed(30);
        __delay_ms(1000);
        
        // ?????????40%???
        ChangeRightMotorSpeed(40);
        ChangeLeftMotorSpeed(40);
        __delay_ms(1000);
 
        // ?????????50%???
        ChangeRightMotorSpeed(50);
        ChangeLeftMotorSpeed(50);
        __delay_ms(1000);
        
        // ?????????60%???
        ChangeRightMotorSpeed(60);
        ChangeLeftMotorSpeed(60);
        __delay_ms(1000);
        
        // ?????????70%???
        ChangeRightMotorSpeed(70);
        ChangeLeftMotorSpeed(70);
        __delay_ms(1000);
        
        // ?????????80%???
        ChangeRightMotorSpeed(80);
        ChangeLeftMotorSpeed(80);
        __delay_ms(1000);
        
        // ?????????90%???
        ChangeRightMotorSpeed(90);
        ChangeLeftMotorSpeed(90);
        __delay_ms(1000);
        
        // ?????????100%???
        ChangeRightMotorSpeed(100);
        ChangeLeftMotorSpeed(100);
        __delay_ms(1000);
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
bool ChangeRightMotorSpeed(int per)
{
    switch(per)
    {
        // 0%??
        case 0:
            CCPR3L = 0b00000000;
            break;
            
        // 10%??
        case 10:
            CCPR3L = 0b00011001;
            break;
            
        // 20%??
        case 20:
            CCPR3L = 0b00110011;
            break;
            
        // 30%??
        case 30:
            CCPR3L = 0b01001100;
            break;
            
        // 40%??
        case 40:
            CCPR3L = 0b01100110;
            break;
            
        // 50%??
        case 50:
            CCPR3L = 0b10000000;
            break;
            
        // 60%??
        case 60:
            CCPR3L = 0b10011001;
            break;
            
        // 70%??
        case 70:
            CCPR3L = 0b10110011;
            break;
            
        // 80%??
        case 80:
            CCPR3L = 0b11001100;
            break;
            
        // 90%??
        case 90:
            CCPR3L = 0b11100110;
            break;
            
        // 100%??
        case 100:
            CCPR3L = 0b11111110;
            break;
            
        // ???
        default:
            return false;
            break;
    }
    
    return true;
}
 
// ????????????
bool ChangeLeftMotorSpeed(int per)
{
    switch(per)
    {
        // 0%??
        case 0:
            CCPR4L = 0b00000000;
            break;
            
        // 10%??
        case 10:
            CCPR4L = 0b00011001;
            break;
            
        // 20%??
        case 20:
            CCPR4L = 0b00110011;
            break;
            
        // 30%??
        case 30:
            CCPR4L = 0b01001100;
            break;
            
        // 40%??
        case 40:
            CCPR4L = 0b01100110;
            break;
            
        // 50%??
        case 50:
            CCPR4L = 0b10000000;
            break;
            
        // 60%??
        case 60:
            CCPR4L = 0b10011001;
            break;
            
        // 70%??
        case 70:
            CCPR4L = 0b10110011;
            break;
            
        // 80%??
        case 80:
            CCPR4L = 0b11001100;
            break;
            
        // 90%??
        case 90:
            CCPR4L = 0b11100110;
            break;
            
        // 100%??
        case 100:
            CCPR4L = 0b11111110;
            break;
            
        // ???
        default:
            return false;
            break;
    }
    
    return true;
}


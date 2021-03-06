/*
arduinoPin-picPin
GND-5
11-7
12-8
13-10
5V-14
/*
arduinoPin-picPin
GND-5
11-7
12-8
13-10
5V-14
*/
#include "commu_08.h"

#include <xc.h>
#include <stdbool.h>    // bool???????????

 
// ????????
#pragma config BORV = HI      
bool InitDevice();                         // ????????? 
bool ChangeRightMotorSpeed(int pwm);     // ????????????
bool ChangeLefttMotorSpeed(int pwm);
unsigned char PWM1 = 00000000;
int sousinData1 = 0;
int jusinData1 = 0;
unsigned char PWM2 = 00000000;
int sousinData2 = 0;
int jusinData2 = 0;
int count = 0;
int OUT;

void interrupt OnInterSpi()
{
      SlaveStart();
      jusinData1 = SlaveRec();
      OUT = jusinData1;
      sousinData1 = OUT;
      SlaveSen(sousinData1);
     
}

 



void main(void)
{
    SlaveInit();
    
    // ???????
    if(!InitDevice()){
        // ??????
    }
    
    
    while(1)
    {
        PWM1 = OUT;
        PWM2 = OUT;
        ChangeRightMotorSpeed(PWM1);
        ChangeLeftMotorSpeed(PWM2);
    };
    
}

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

bool ChangeLeftMotorSpeed(int pwm)
{
            CCPR1L = pwm;
    return true;}
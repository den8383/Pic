/* 
 * File:   SPI_ver04_slave.h
 * Author: OWNER
 *
 * Created on 2018/09/12, 18:19
 */

#ifndef SPICom_ver01_H
#define	SPICom_ver01_H

#pragma config FOSC = INTOSC    // ?????????
#pragma config WDTE = OFF       // ??????????
#pragma config PWRTE = OFF      // ??????????
#pragma config MCLRE = ON       // MCLR????????
#pragma config CP = OFF         // ????????
#pragma config CPD = OFF        // ???????
#pragma config BOREN = ON       // ??????
#pragma config CLKOUTEN = OFF   // CLKOUT??????
#pragma config IESO = OFF       // ????????????
#pragma config FCMEN = OFF      // ?????????

#pragma config WRT = OFF        // 4KW?????????????????
#pragma config PLLEN = ON       // 4xPLL???
#pragma config STVREN = OFF     // ?????????????
#pragma config LVP = OFF        // ??????????

#define _XTAL_FREQ 32000000     // ???????????????
#define LOW 0
#define HIGH 1

unsigned char return_data = 0, read_data;




void SlaveInit(void);
void SlaveStart(void);
int SlaveRec(void);
void SlaveSen(int sendData);

#endif


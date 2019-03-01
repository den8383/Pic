#include <SPI.h>

void setup()
{
     SPI.begin() ;                        // ＳＰＩを行う為の初期化
     SPI.setBitOrder(MSBFIRST) ;          // ビットオーダー
     SPI.setClockDivider(SPI_CLOCK_DIV8) ;// クロック(CLK)をシステムクロックの1/8で使用(16MHz/8)
     SPI.setDataMode(SPI_MODE1) ;         // クロック極性０(LOW)　クロック位相１(0V→5Vの変化で送信)

     delay(5000) ;  // 5Sしたら開始
}
void loop()
{
     int i ;
     byte ans ;

    // ＬＣＤに表示しやすい用にキャラクター文字を送っています。
    for (i = 0x30 ; i < 0x7b ; i++) {
          ans = (byte)i ;
          ans = SPI.transfer(ans) ;
          delay(1000) ;
    }
}


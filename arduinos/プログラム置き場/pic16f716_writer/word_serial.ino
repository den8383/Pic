/*
Copyright 2014 みけCAT.

This software is provided "as is", without any express or implied warranties,
including but not limited to the implied warranties of merchantability and
fitness for a particular purpose.  In no event will the authors or contributors
be held liable for any direct, indirect, incidental, special, exemplary, or
consequential damages however caused and on any theory of liability, whether in
contract, strict liability, or tort (including negligence or otherwise),
arising in any way out of the use of this software, even if advised of the
possibility of such damage.

Permission is granted to anyone to use this software for any purpose, including
commercial applications, and to alter and distribute it freely in any form,
provided that the following conditions are met:

1. The origin of this software must not be misrepresented; you must not claim
   that you wrote the original software. If you use this software in a product,
   an acknowledgment in the product documentation would be appreciated but is
   not required.

2. Altered source versions may not be misrepresented as being the original
   software, and neither the name of みけCAT nor the names of
   authors or contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

3. This notice must be included, unaltered, with any source distribution.
*/

#include "pic16f716_writer.h"

// ワード(2バイト)単位でのシリアル通信ラッパ
// ビッグエンディアン(0x1234は0x12 0x34の順番で送受信する)

// バッファに溜まっているデータの数をワード単位で得る
int serialGetAvailableWordsNum(void) {
  return Serial.available()/2;
}

// 1ワード受信する
unsigned int serialReadOneWord(void) {
  int high=Serial.read();
  int low=Serial.read();
  return (((unsigned int)high)<<8)|((unsigned int)low);
}

// データが来るまで待機し、1ワード受信する
unsigned int serialReadOneWordBlock(void) {
  while(serialGetAvailableWordsNum()==0) {
    delay(1);
  }
  return serialReadOneWord();
}

// 1ワード送信する
void serialWriteOneWord(unsigned int w) {
  Serial.write((w>>8)&0xff);
  Serial.write(w&0xff);
}

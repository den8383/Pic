/*
Copyright 2014 ‚Ý‚¯CAT.

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
   software, and neither the name of ‚Ý‚¯CAT nor the names of
   authors or contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

3. This notice must be included, unaltered, with any source distribution.
*/

#include "pic16f716_writer.h"

void sendDataToPic(unsigned int data, int bitLength) {
  noInterrupts();
  for(int i=0;i<bitLength;i++) {
    digitalWrite(PIN_CLOCK, HIGH);
    digitalWrite(PIN_DATA, (data&(1u<<i))?HIGH:LOW);
    delayMicroseconds(TSET1);
    digitalWrite(PIN_CLOCK, LOW);
    delayMicroseconds(THLD1);
  }
  digitalWrite(PIN_DATA, LOW);
  interrupts();
}

unsigned int receiveDataFromPic(int bitLength) {
  unsigned int data=0;
  noInterrupts();
  pinMode(PIN_DATA, INPUT);
  for(int i=0;i<bitLength;i++) {
    digitalWrite(PIN_CLOCK, HIGH);
    delayMicroseconds(TDLY3);
    if(digitalRead(PIN_DATA)==HIGH) {
      data|=(1<<i);
    }
    digitalWrite(PIN_CLOCK, LOW);
    delayMicroseconds(TDLY1);
  }
  pinMode(PIN_DATA, OUTPUT);
  digitalWrite(PIN_DATA, LOW);
  interrupts();
  return data;
}

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

// データを読み書きするときに一時保存するためのバッファ
#define BUFFER_MAX 512
unsigned int dataBuffer[BUFFER_MAX];

// COMMAND_ERASE
void commandErase(void) {
  sendDataToPic(PIC_BULK_ERASE_PROGRAM_MEMORY, 6);
  delayMicroseconds(TERA);

  serialWriteOneWord(COMMAND_RET_DONE);
}

// COMMAND_ERASE_ALL
void commandEraseAll(void) {
  sendDataToPic(PIC_LOAD_CONFIGURATION, 6);
  delayMicroseconds(TDLY2);
  sendDataToPic(0x3FFFu<<1, 16);
  delayMicroseconds(TDIS);
  sendDataToPic(PIC_BULK_ERASE_PROGRAM_MEMORY, 6);
  delayMicroseconds(TERA);

  serialWriteOneWord(COMMAND_RET_DONE);
}

// COMMAND_WRITE_PROGRAM, 書き込むワード数, プログラム, COMMAND_DATA_END
void commandWriteProgram(void) {
  // PCから書き込むべきデータを受け取る
  unsigned int expectedDataSize;
  // まずデータサイズを取得する
  expectedDataSize=serialReadOneWordBlock();
  // データを受信する
  unsigned int dataSize=0;
  while(dataSize<BUFFER_MAX) {
    unsigned int currentData=serialReadOneWordBlock();
    if(currentData==COMMAND_DATA_END) {
      break;
    } else {
      dataBuffer[dataSize++]=currentData;
    }
  }
  // データが途中で抜けていないかチェックする
  if(dataSize!=expectedDataSize) {
    // サイズが合わない
    serialWriteOneWord(COMMAND_RET_FAILED);
    return;
  }
  // 4ワード境界に合わせる
  while(dataSize%4!=0) {
    dataBuffer[dataSize++]=0x3fff;
  }
  // PICに書き込む操作を行う
  for(unsigned int i=0;i<dataSize;i++) {
    // データをラッチに設定
    sendDataToPic(PIC_LOAD_DATA_FOR_PROGRAM_MEMORY, 6);
    delayMicroseconds(TDLY2);
    sendDataToPic(dataBuffer[i]<<1, 16);
    delayMicroseconds(TDIS);
    // 4ワード目なら書き込みを実行する
    if((i+1)%4==0) {
      sendDataToPic(PIC_BEGIN_PROGRAMMING, 6);
      delayMicroseconds(TPROG);
      sendDataToPic(PIC_END_PROGRAMMING, 6);
      delayMicroseconds(TDIS);
    }
    // ポインタを進める
    sendDataToPic(PIC_INCREMENT_ADDRESS, 6);
    delayMicroseconds(TDLY1);
  }

  serialWriteOneWord(COMMAND_RET_DONE);
}

// COMMAND_WRITE_ID, 書き込むID
void commandWriteId(void) {
  // PCから書き込むべきIDを受け取る
  // IDは、例えば0x01234567を指定すると、0x0001, 0x0023, 0x0045, 0x0067となる。
  unsigned int idToWrite1,idToWrite2;
  unsigned int dataToWrite[4];
  idToWrite1=serialReadOneWordBlock();
  idToWrite2=serialReadOneWordBlock();
  dataToWrite[0]=(idToWrite1>>8)&0x7f;
  dataToWrite[1]=idToWrite1&0x7f;
  dataToWrite[2]=(idToWrite2>>8)&0x7f;
  dataToWrite[3]=idToWrite2&0x7f;

  // PICへの書き込み操作を行う
  // 最初のデータを設定
  sendDataToPic(PIC_LOAD_CONFIGURATION, 6);
  delayMicroseconds(TDLY2);
  sendDataToPic(dataToWrite[0]<<1, 16);
  delayMicroseconds(TDIS);
  // ポインタを進める
  sendDataToPic(PIC_INCREMENT_ADDRESS, 6);
  delayMicroseconds(TDLY1);
  for(unsigned int i=1;i<4;i++) {
    // データをラッチに設定
    sendDataToPic(PIC_LOAD_DATA_FOR_PROGRAM_MEMORY, 6);
    delayMicroseconds(TDLY2);
    sendDataToPic(dataToWrite[i]<<1, 16);
    delayMicroseconds(TDIS);
    // 4ワード目なら書き込みを実行する
    if((i+1)%4==0) {
      sendDataToPic(PIC_BEGIN_PROGRAMMING, 6);
      delayMicroseconds(TPROG);
      sendDataToPic(PIC_END_PROGRAMMING, 6);
      delayMicroseconds(TDIS);
    } else {
      // ポインタを進める
      sendDataToPic(PIC_INCREMENT_ADDRESS, 6);
      delayMicroseconds(TDLY1);
    }
  }

  serialWriteOneWord(COMMAND_RET_DONE);
}

// COMMAND_WRITE_CONFIG, 書き込む設定ワード
void commandWriteConfig(void) {
  // PCから書き込むべきワードを読み込む
  int configToWrite;
  configToWrite=serialReadOneWordBlock();

  // PICへの書き込み操作を行う
  sendDataToPic(PIC_LOAD_CONFIGURATION, 6);
  delayMicroseconds(TDLY2);
  sendDataToPic(0x3fff<<1, 16);
  delayMicroseconds(TDIS);
  // ポインタを書き込む位置まで進める
  for(int i=0;i<7;i++) {
    sendDataToPic(PIC_INCREMENT_ADDRESS, 6);
    delayMicroseconds(TDLY1);
  }
  // 書き込みを実行する
  sendDataToPic(PIC_LOAD_DATA_FOR_PROGRAM_MEMORY, 6);
  delayMicroseconds(TDLY2);
  sendDataToPic(configToWrite<<1, 16);
  delayMicroseconds(TDIS);
  sendDataToPic(PIC_BEGIN_PROGRAMMING, 6);
  delayMicroseconds(TPROG);
  sendDataToPic(PIC_END_PROGRAMMING, 6);
  delayMicroseconds(TDIS);

  serialWriteOneWord(COMMAND_RET_DONE);
}

void commandReadProgram(void) {
  // PCから読み込むべきデータ数を受信する
  unsigned int dataLengthToRead;
  dataLengthToRead=serialReadOneWordBlock();
  if(dataLengthToRead>BUFFER_MAX) {
    dataLengthToRead=BUFFER_MAX;
  }
  // PICからデータを読み込む処理を行う
  for(int i=0;i<dataLengthToRead;i++) {
    // データを読み込む
    sendDataToPic(PIC_READ_DATA_FROM_PROGRAM_MEMORY, 6);
    delayMicroseconds(TDLY2);
    dataBuffer[i]=(receiveDataFromPic(16)>>1)&0x3fff;
    delayMicroseconds(TDLY2);
    // ポインタを進める
    sendDataToPic(PIC_INCREMENT_ADDRESS, 6);
    delayMicroseconds(TDLY1);
  }
  // 読み込んだデータをPCに送信する
  for(int i=0;i<dataLengthToRead;i++) {
    serialWriteOneWord(dataBuffer[i]);
  }
  // 終了を表すデータをPCに送信する
  serialWriteOneWord(COMMAND_DATA_END);
}

void commandReadIdAndConfig(void) {
  // User ID, Device ID, Configuration Wordを読み込む
  unsigned int readData[8];
  sendDataToPic(PIC_LOAD_CONFIGURATION, 6);
  delayMicroseconds(TDLY2);
  sendDataToPic(0x3fff<<1, 16);
  delayMicroseconds(TDIS);
  // User IDを読み込む
  for(int i=0;i<8;i++) {
    // Reservedは飛ばす
    if(i!=4 && i!=5) {
      // データを読み込む
      sendDataToPic(PIC_READ_DATA_FROM_PROGRAM_MEMORY, 6);
      delayMicroseconds(TDLY2);
      readData[i]=(receiveDataFromPic(16)>>1)&0x3fff;
      delayMicroseconds(TDLY2);
    }
    // ポインタを進める
    sendDataToPic(PIC_INCREMENT_ADDRESS, 6);
    delayMicroseconds(TDLY1);
  }

  // 読み取ったデータをPCに送信する
  // User ID
  serialWriteOneWord(((readData[0]&0xff)<<8)|(readData[1]&0xff));
  serialWriteOneWord(((readData[2]&0xff)<<8)|(readData[3]&0xff));
  // Device ID
  serialWriteOneWord(readData[6]);
  // Configuration Word
  serialWriteOneWord(readData[7]);
}

void setup(void) {
  pinMode(PIN_CLOCK, OUTPUT);
  pinMode(PIN_DATA, OUTPUT);
  pinMode(PIN_RUNNING, OUTPUT);
  digitalWrite(PIN_CLOCK, LOW);
  digitalWrite(PIN_DATA, LOW);
  digitalWrite(PIN_RUNNING, LOW);
  Serial.begin(9600);
}

void loop(void) {
  if(serialGetAvailableWordsNum()>0) {
    unsigned int command=serialReadOneWord();
    digitalWrite(PIN_RUNNING, HIGH);
    switch(command) {
      case COMMAND_ERASE:
        commandErase();
        break;
      case COMMAND_ERASE_ALL:
        commandEraseAll();
        break;
      case COMMAND_WRITE_PROGRAM:
        commandWriteProgram();
        break;
      case COMMAND_WRITE_ID:
        commandWriteId();
        break;
      case COMMAND_WRITE_CONFIG:
        commandWriteConfig();
        break;
      case COMMAND_READ_PROGRAM:
        commandReadProgram();
        break;
      case COMMAND_READ_ID_AND_CONFIG:
        commandReadIdAndConfig();
        break;
    }
    digitalWrite(PIN_RUNNING, LOW);
  }
}

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

#ifndef PIC16F716_WRITER_H_GUARD_346D899D_909A_4EFA_BFA3_39910820D73B
#define PIC16F716_WRITER_H_GUARD_346D899D_909A_4EFA_BFA3_39910820D73B

// ピンの割り当て設定
#define PIN_CLOCK 2
#define PIN_DATA 3
#define PIN_RUNNING 13

// コマンドを表す定数
// プログラムとconfiguration wordを消す
#define COMMAND_ERASE 0x8000u
// プログラム、configuration word、user IDを消す
#define COMMAND_ERASE_ALL 0x8001u
// プログラムを書き込む
#define COMMAND_WRITE_PROGRAM 0x8010u
// IDを書き込む
#define COMMAND_WRITE_ID 0x8011u
// configulation dataを書き込む
#define COMMAND_WRITE_CONFIG 0x8012u
// プログラムを読み込む
#define COMMAND_READ_PROGRAM 0x8020u
// IDとconfigulation dataを読み込む
#define COMMAND_READ_ID_AND_CONFIG 0x8021u
// 処理が完了した時に送る定数
#define COMMAND_RET_DONE 0xC000u
// 処理が失敗したと判定した時に送る定数
#define COMMAND_RET_FAILED 0xF000u
// データの終わりを示す定数
#define COMMAND_DATA_END 0xffffu

// PICのコマンドの定数
#define PIC_LOAD_CONFIGURATION 0x00
#define PIC_LOAD_DATA_FOR_PROGRAM_MEMORY 0x02
#define PIC_READ_DATA_FROM_PROGRAM_MEMORY 0x04
#define PIC_INCREMENT_ADDRESS 0x06
#define PIC_BEGIN_PROGRAMMING 0x18
#define PIC_END_PROGRAMMING 0x0e
#define PIC_BULK_ERASE_PROGRAM_MEMORY 0x09

// PICの操作にかける時間[μs]
#define TSET1 5
#define THLD1 5
#define TDLY1 5
#define TDLY2 5
#define TDLY3 5
#define TERA 7000
#define TPROG 3000
#define TDIS 200

// ワード(2バイト)単位でのシリアル通信ラッパ
int serialGetAvailableWordsNum(void);
unsigned int serialReadOneWord(void);
unsigned int serialReadOneWordBlock(void);
void serialWriteOneWord(unsigned int w);

// PICと通信するためのプログラム
void sendDataToPic(unsigned int data, int bitLength);
unsigned int receiveDataFromPic(int bitLength);

#endif

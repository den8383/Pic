// skI2Cslave.h
// �h�Q�b�ʐM�̃X���[�u�֐��p���C�u�����p�C���N���[�h�t�@�C��
// ����M���s���f�[�^�̃T�C�Y�ɂ��SND_DATA_LEN/RCV_DATA_LEN�𒲐����ĉ������B
#ifndef _SKI2CSLAVE_H_
#define _SKI2CSLAVE_H_

#define SND_DATA_LEN 8                  // ���M�f�[�^�o�b�t�@�̃T�C�Y
#define RCV_DATA_LEN 8                  // ��M�f�[�^�o�b�t�@�̃T�C�Y

unsigned char rcv_data[RCV_DATA_LEN] ;  // ��M�f�[�^�o�b�t�@
unsigned int snd_data[SND_DATA_LEN] ;  // ���M�f�[�^�o�b�t�@


int oldEncValue = 0;
int count = 0;


void interrupt InterI2C( void ) ;
//void InterI2C( void ) ;
void InitI2C_Slave(int address) ;
int I2C_ReceiveCheck() ;

#endif

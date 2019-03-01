#ifndef SpiConS_H
#define SpiConS_H


class SpiConS{
  public:
  SpiConS(int board);
  void task(void);
  void setUp(void);
  int MOSI_Byte = 0;
  int MISO_Byte = 0;
  int MISO_Byte_ = 0;
  int spi_flag = 0;
  void Inter();
  
  private:
  int SS_PIN = 10;
  int SCK_PIN = 13;
  int MISO_PIN = 12;
  int MOSI_PIN = 11;
  
};


#endif

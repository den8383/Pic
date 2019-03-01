#ifndef SpiConS_H
#define SpiConS_H


class SpiConS{
  public:
  SpiConS(void);
  void task(void);
  void setUp(void);
  int MOSI_Byte = 0;
  int MISO_Byte = 0;
  int MISO_Byte_ = 0;
  int spi_flag = 0;
  void Inter();
  
  private:
  
};


#endif

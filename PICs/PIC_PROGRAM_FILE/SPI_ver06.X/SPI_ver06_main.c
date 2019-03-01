#include "SPI_ver06_slave.h"

int sousinData = 0;
int jusinData = 0;

void interrupt OnInterSpi()
{
    SlaveStart();
    jusinData = SlaveRec();
    sousinData = jusinData - 10;
    SlaveSen(sousinData);
}

void main(void)
{
    SlaveInit();
    
    while(1) ;
}
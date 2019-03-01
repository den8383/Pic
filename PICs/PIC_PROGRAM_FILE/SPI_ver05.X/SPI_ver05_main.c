#include "SPI_ver05_slave.h"



void interrupt OnInterSpi()
{
    SlaveStart();
}

void main(void)
{
    SlaveInit();
    
    while(1) ;
}
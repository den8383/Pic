#include "encoder1.h"



void InitInterExt (void)
{
	// RB0??????????
	TRISB0 = 1;
    TRISA2 = 1;
	
	// ???????????????
	INTEDG = 1;
	
	// ????????????
	INTF = 0;
	
	// ????????
	INTE = 1;

}


/*static void interrupt isr(void)
{
    RB4 = 1;
    volatile long encValue = 0;
    int newEncA = 0;
    int newEncB = 0;
    volatile int oldEncB = 0;
    
    newEncA = RB0;
    newEncB = RA2;

    if (newEncA)
    {
      if (oldEncB && !newEncB) 
      { // up
        ++encValue;
        RB3 = 1;
      } 
      else 
      { // down
        --encValue;
        RB3 = 1;
      }
    }
    else 
    {
       if (oldEncB && !newEncB) 
       { // down
        --encValue;
        RB3 = 0;
       }
       else
       { // up
        ++encValue;
        RB3 = 0;
       }
    }
    oldEncB = newEncB;

    
	// LED1????
   
	// ????????????
    if(INTEDG == 1)
    {
        INTEDG = 0;
    }else
    {
        INTEDG = 1;
    }
	INTF = 0;
    RB4 = 0;
    count = encValue;
    
}
*/
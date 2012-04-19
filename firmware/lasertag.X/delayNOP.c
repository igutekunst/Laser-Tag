#include "delayNOP.h"
#include <p24F16KA102.h>

void delay(long int ms){
    volatile int i = 0;
    for(i=0;i<ms;i++){
        msdelay();
    }
}

void msdelay(){
    volatile int i = 0;
    for(i=0;i<330;i++){//330? seems to work.
        asm("NOP");
    }
}

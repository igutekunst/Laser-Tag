#include <p24F16KA102.h>
#include "delayNOP.h"

#include "io.h"
#include "laserTagHardware.h"
#include "playerInfo.h"
#include "gameSM.h"


// 2 is board with all the shit
// 3 is left board
// 4 is kelly
//5 is isaac
_FWDT	(FWDTEN_OFF);
_FOSCSEL(FNOSC_FRCPLL );
_FOSC   ( POSCFREQ_HS & POSCMOD_HS & OSCIOFNC_OFF );


char bit_counter;
unsigned char command;
unsigned char old_nibble;
unsigned char rx_counter;
unsigned char values[8];

unsigned char rx_timeout;

unsigned long long int counter = 0;
int main(void){

    TRISAbits.TRISA6 = 0;
    PR2   = 0xC0;
    OC1R  = 0xC0/2;
    OC1RS = 0xC0/2;

    PADCFG1bits.OC1TRIS = 0;
    OC1CONbits.OCTSEL =0; // use timer 2
    OC1CONbits.OCM = 0b110; // PWM


    T2CONbits.TON = 1;


    while (1){
        delay(5000);
        OC1RS = 0xC0/3;
        delay(5000);
        OC1RS = 0xC0/2;


    }
    
    //set up interupt to debounce trigger, maybe establish game clock
    enableIO();


   
    Nop();

    updateDisplay(lives);

    TRISBbits.TRISB2 = 1; //
    Nop();
    TRISAbits.TRISA6 = 0;
    Nop();
    TRISAbits.TRISA4 = 1;
    Nop();

    TRISBbits.TRISB0 =0;
    AD1PCFG = 0xffff;
     RED_LAT = 1;
    BLUE_LAT = 0;
    GREEN_LAT = 0;
    while(1){
        int i;
        int j;
        for(i =0; i < 10; i++){


            for(j = 0; j<10; j++){
                if(TRIGGER_PORT == 0){
                     delay(i/2);
                    SPEAKER_LAT = 1;
                    
                    delay(i/2);
                    SPEAKER_LAT = 0;
                    

                    RED_LAT = 0;
                    BLUE_LAT = 1;
                    GREEN_LAT = 1;

                  
                }else{
                     RED_LAT = 1;
                     BLUE_LAT = 0;
                     GREEN_LAT = 0;

                     
                }
                
            }
        }
       
        
        
    }

}








void _ISR _U1RXInterrupt (void){
#ifndef SPECIAL_FUNCTION
    unsigned char temp = U1RXREG;
    if(U1STAbits.FERR==1){
        //do nothing
         rx_counter= 0;

    }else{

        if(rx_counter<5){
            rx_timeout = 0;
            values[rx_counter] = temp;
            rx_counter++;
        }else if(rx_counter==5){
            values[rx_counter] = temp;
            rx_counter = 0;
        }
    }
#endif
 IFS0bits.U1RXIF = 0;
  //UART1PutChar(temp);
}

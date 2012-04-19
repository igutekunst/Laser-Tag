#include "eeprom.h"
#include <p24F08KA102.h>
void eeprom_write(unsigned int address, int data){
    unsigned int offset;
    // Set up NVMCON to erase one word of data EEPROM
    NVMCON = 0x4004;
    int * dataPointer = (int * ) (0x7FFE00 +  address);
    TBLPAG = __builtin_tblpage(dataPointer);
    offset = __builtin_tbloffset(dataPointer);
    
    __builtin_tblwtl(offset, data);
    asm volatile ("disi #5");
    __builtin_write_NVM();
   
}
int eeprom_read(unsigned int address){
    unsigned int offset;
    // Set up a pointer to the EEPROM location to be erased
    int * dataPointer = (int * ) (0x7FFE00 +  address);
    TBLPAG = __builtin_tblpage(dataPointer);
    offset = __builtin_tbloffset(dataPointer);
    int data = __builtin_tblrdl(offset);
    
}



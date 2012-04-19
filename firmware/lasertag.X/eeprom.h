#ifndef  EEPROM_H
#define EEPROM_H

void eeprom_write(unsigned int address, int data);
int eeprom_read(unsigned int address);



#endif
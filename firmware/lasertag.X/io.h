#ifndef IO_H
#define IO_H
#include "laserTagHardware.h"
#include "hamming.h"
#include "irSerial.h"


#include <p24F16KA102.h>
/**
 * Initializes all lasertag io
 */
void enableIO();
void _ISR _U1RXInterrupt (void);
/**
 * Changes LED lives display
 * @param lives Range 0 to 3
 */
void updateLives(unsigned char lives);
#endif
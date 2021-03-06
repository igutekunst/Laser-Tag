#ifndef LASER_TAG_HARDWARE_H
#define LASER_TAG_HARDWARE_H
#define BLUE_TRIS (TRISBbits.TRISB11)
#define GREEN_TRIS (TRISBbits.TRISB12)
#define RED_TRIS (TRISBbits.TRISB13)

#define BLUE_LAT (LATBbits.LATB11)
#define GREEN_LAT (LATBbits.LATB12)
#define RED_LAT (LATBbits.LATB13)

#define LIFE_1_LAT (LATAbits.LATA7)
#define LIFE_3_LAT (LATBbits.LATB9)
#define LIFE_2_LAT (LATBbits.LATB8)

#define LIFE_1_TRIS (TRISAbits.TRISA7)
#define LIFE_3_TRIS (TRISBbits.TRISB9)
#define LIFE_2_TRIS (TRISBbits.TRISB8)


#define IR_OUT_LAT (LATAbits.LATA6)
#define IR_OUT_TRIS (TRISAbits.TRISA6)

#define TRIGGER_LAT  (LATAAbits.LATA4)
#define TRIGGER_TRIS (TRISAbits.TRISA4)
#define TRIGGER_PORT (PORTAbits.RA4)


    #define SPEAKER_LAT  (LATBbits.LATB6)
#define SPEAKER_TRIS (TRISBbits.TRISB6)
#endif

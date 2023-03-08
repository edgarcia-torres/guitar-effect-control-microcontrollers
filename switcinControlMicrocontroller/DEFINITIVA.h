#include <C:\Program Files (x86)\PICC\Devices\18f4550.h>                //Directorio donde se encuentra la libreria del PIC
#fuses hs, nowdt, noprotect, intrc, nolvp, put                           //HS = High Speed     INTRC = Reloj Interno
#use delay (internal = 8MHz)                                             //Utilizar el reloj interno del PIC a 8 MHz
#byte trisa = 0xf92                                                      //Configuración de los puertos
#byte porta = 0xf80
#byte trisb = 0xf93
#byte portb = 0xf81
#byte trisc = 0xf94
#byte portc = 0xf82
#byte trisd = 0xf95
#byte portd = 0xf83
#byte trise = 0xf96
#byte porte = 0xf84

#BIT RA0 = PORTA.0
#BIT RA1 = PORTA.1
#BIT RA2 = PORTA.2
#BIT RA3 = PORTA.3
#BIT RA4 = PORTA.4


#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

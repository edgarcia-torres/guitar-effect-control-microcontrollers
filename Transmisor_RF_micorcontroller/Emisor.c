#include <16F88.h>
#FUSES NOWDT, XT, PUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock=4000000)

#include "lib_rf2gh4_10.h"

#int_ext
void int_RB0()
{
   int8 ret1;
   
   ret1 = RF_RECEIVE();
   if ( (ret1 == 0) || (ret1 == 1) )
   {
      do
      {  
         ret1 = RF_RECEIVE(); 
      }  while ( (ret1 == 0) || (ret1 == 1) );
   }  
}

void main()
{  
   int8 ret2;
   int P;

   RF_INT_EN();              // Habilitar interrupción RB0/INT.
   RF_CONFIG_SPI();          // Configurar módulo SPI del PIC.
   RF_CONFIG(0x40,0x01);     // Configurar módulo RF canal y dirección.
   RF_ON();                  // Activar el módulo RF.
   
   delay_ms(5);
   
   set_tris_a(0xff);     // Todo el puerto A como entradas.

   
   while(true)
   {  
      
   //********************************************************************************************************************************
   //                                     SE CREA LA VARIABLE QUE VAMOS A ENVIAR
   //********************************************************************************************************************************
  // if(Bit_test(porta,6)==1 && Bit_test(porta,7)==0){ 
   if(S1==1 && S2==0){
IF (A1==1 &&  A2==0 && A3==0 && A4==0 && A5==0){P=15; GOTO A;}
IF (A1==0 &&  A2==1 && A3==0 && A4==0 && A5==0){P=14; GOTO A;}
IF (A1==0 &&  A2==0 && A3==1 && A4==0 && A5==0){P=13; GOTO A;}
IF (A1==0 &&  A2==0 && A3==0 && A4==1 && A5==0){P=12; GOTO A;}
IF (A1==0 &&  A2==0 && A3==0 && A4==0 && A5==1){P=11; GOTO A;}
}
//if(Bit_test(porta,6)==1 && Bit_test(porta,7)==1){
 if(S1==1 && S2==1){
IF (A1==1 &&  A2==0 && A3==0 && A4==0 && A5==0){P=10; GOTO A;}
IF (A1==0 &&  A2==1 && A3==0 && A4==0 && A5==0){P=9; GOTO A;}
IF (A1==0 &&  A2==0 && A3==1 && A4==0 && A5==0){P=8; GOTO A;}
IF (A1==0 &&  A2==0 && A3==0 && A4==1 && A5==0){P=7; GOTO A;}
IF (A1==0 &&  A2==0 && A3==0 && A4==0 && A5==1){P=6; GOTO A;}
}   
//if(Bit_test(porta,6)==0 && Bit_test(porta,7)==0){   
 if(S1==0 && S2==0){
IF (A1==1 &&  A2==0 && A3==0 && A4==0 && A5==0){P=5; GOTO A;}
IF (A1==0 &&  A2==1 && A3==0 && A4==0 && A5==0){P=4; GOTO A;}
IF (A1==0 &&  A2==0 && A3==1 && A4==0 && A5==0){P=3; GOTO A;}
IF (A1==0 &&  A2==0 && A3==0 && A4==1 && A5==0){P=2; GOTO A;}
IF (A1==0 &&  A2==0 && A3==0 && A4==0 && A5==1){P=1; GOTO A;}
}
A:  //Despues de que se crea una variable el tipo va diorectamente a A para enviar la variable.
//*********************************************************************************************************************************
//
//*¨*******************************************************************************************************************************
   
   
      RF_DATA[0]=P;
      RF_DIR=0x08;           // Dirección del receptor.
      ret2=RF_SEND();        // Enviar datos.
   }
}

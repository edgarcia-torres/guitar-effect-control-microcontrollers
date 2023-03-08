#include "C:\Users\David\Desktop\OneDrive\SEMESTRE ACTUAL\PROYECTO 1\PROGRAMACION DE LA INTERFACE\PROGRAMACION PIC18F4550 DEFINITIVA\DEFINITIVA.h"
char conf[91]="A10000B01000C10100D01010E00111F10000G10010H01100I00110J00001K10000L01000M00100N00010O00001";
  //char cont[91]="A11000B01100C00110D00011E00100F10001G01010H00100I10100J11111K10000L01000M00100N00010O00001";
 //char conf[91];                                   //Se crea un vector de caracteres para almacenar la cadena concatenada que envía LabView
// char cont[91];                                                     //El vector es de 70 posiciones ya que la cadena que envía LabView tiene 70 caracteres.

#int_rda                             //Se utiliza la interrupción RDA del PIC, que indica cuando un caracter es recibido por comunicación serial
void rd_isr(void){ int i;                             //Se crea una función que se llama automáticamente cuando se presente una interrupción RDA.
   for( i=0; i < 90; i++){                          //Se utiliza un ciclo FOR para leer los 70 caracteres de la cadena
      conf[i] = getc(); //y almacenar cada caracter en una posición del vector
   
//  WRITE_EEPROM(i,cont[i]);
//  conf[i]=READ_EEPROM(i);
   }                                                  //La función GETC() lee el caracter que llego al Buffer de la comunicación serial.
}

void main(){   

   setup_oscillator(OSC_8MHZ|OSC_INTRC);               //Se configura oscilador interno de 8 MHz
   enable_interrupts(GLOBAL);                          //Se habilitan las interrupciones globales 
                                        
//printf("AT");                                            //velocidades baud   //CONFIGURAR BLUETOOTH
//delay_ms(1000);
//printf("AT+BAUD4"); 
//delay_ms(1000);
//printf("AT+NAMEUnidad_aplicadora_de_efectos"); 
//delay_ms(1000);
     
   
   enable_interrupts(INT_RDA);                         //Se habilita la interrupción RDA de la comunicación UART  
  

   delay_ms(10000); 
   
   trisa = 0x00;                                       //Se configuran todos los pines del Puerto A como salida (Para conectar los RELES)
   trisb = 0xff;                                       //Se configuran todos los pines del Puerto B como entrada(Para la entrada de comandos)
   trisc = 0xff;                                       //se configuran dos pines del puerto C como entrada(enable trasmision y modo de operacion)  
   trisd = 0x00;                                       //Se configuran todos los pines del Puerto D como salida (Para conectar los LEDs)
   trise = 0x00;                                       //Se configuran todos los pines del Puerto E como salida (Para conectar los LEDs)
                                     //Se hace un retardo de 10 segundos para esperar que el Bluetooth se empareje con el PC
   
   INT C=0 ,U=0 ,n=0 ,o=0 ,p=0 ,q=0 ,r=0 ,e1=0 ,e2=0 ,e3=0 ,e4=0 ,e5=0 ;
   
   while(1){      //Ciclo infinito
    
     k:
if (bit_test(portc,0)==1){                                   // MODO DE OPERACION 1
   if(portb==15 || portb==14 || portb==13  || portb==12  || portb==11){  
      
      C=0;                                             //valida que dentro de este modo no se va a activar el modo de operacion 2
      U=0;
              if(portb==0){  goto K;     //no hacer nada 
                                                                                              }
                  if(portb==15){//porta=A;
                     RA0=(conf[1]);     RA1=(conf[2]);    RA2=(conf[3]);
                     RA3=(conf[4]);     RA4=(conf[5]);                                        } 
                  if(portb==14){//porta=B;
                     RA0=(conf[7]);     RA1=(conf[8]);    RA2=(conf[9]);
                     RA3=(conf[10]);    RA4=(conf[11]);                                       }
                  if(portb==13){//porta=C;
                     RA0=(conf[13]);    RA1=(conf[14]);   RA2=(conf[15]);
                     RA3=(conf[16]);    RA4=(conf[17]);                                       }         
                  if(portb==12){//porta=D;
                     RA0=(conf[19]);    RA1=(conf[20]);   RA2=(conf[21]);
                     RA3=(conf[22]);    RA4=(conf[23]);                                       }
                  if(portb==11){//porta=E;
                     RA0=(conf[25]);    RA1=(conf[26]);   RA2=(conf[27]);
                     RA3=(conf[28]);    RA4=(conf[29]);                                       }      
   }
   else {goto J;}

}

J:

IF(bit_test(portc,0)==1){                                    //MODO DE OPERACION 2
    IF (PORTB==10 || PORTB==9){
      U=0;
                                                   //en este modo de operacion c nunca sera = 0 de manera que cuando se salga 
                                                   //de este if aplicara el efecto que indique la variable c 
                                                   //Se pone en ON la transmicion de datos 
       while(bit_test(portc,0)==1);                //Mientras RC0 este en ON el programa se para aca, pero ya entro a la rutina
   delay_ms(100);
      IF(bit_test(portc,0)==0 && PORTB==9){        //si se cumplemn estas dos condiciones el RC0 ya habra pasado de 1 a 0 entonces
         C=C+1;                                    //ya se puede hacer la adicion a C     
                                                   //cuando e=1 significa que ya se ha entrado al modo de operacion 2 y se ha puesto en ON en RC0
         IF(C==6){C=1;}                            //Si vamos en el efecto numero 5 y se presiona el RC0 se pasa al efecto numero 1 
         delay_ms(100);
         goto L;                                   // me saca del IF
      }
      IF(bit_test(portc,0)==0 && PORTB==10){        //si se cumplemn estas dos condiciones el RC0 ya habra pasado de 1 a 0 entonces ya se puede hacer la resta a C
         C=C-1;                                    
         IF(C==0){C=5;}                            //Si vamos en el efecto numero 5 y se presiona el RC0 se pasa al efecto numero 1
         IF(C==-1){C=1;}delay_ms(100);
         goto L;                                   // me saca del IF 
      }        
   }
   else{goto H;}
    
}

H:                                                            //MODO DE OPERACION 3

IF(bit_test(portc,0)==1){ 



   IF(PORTB==5 || PORTB==4 || PORTB==3 || PORTB==2 || PORTB==1){    //se entra al modo de operacion 3

   C=0;                                                   //valida que dentro de este modo no se va a activar el modo de operacion 2
   
   If(U==0){U=1;
      RA0=0;    RA1=0;   RA2=0;   RA3=0;    RA4=0;       //se pone en cero el puerto A
      }
                                                   
     while(bit_test(portc,0)==1);
     delay_ms(100);
       if(portb==5 && bit_test(portc,0)==0) {//porta=K;
           n=conf[61];
           o=conf[62];
           p=conf[63];
           q=conf[64];
           r=conf[65];
               if(n==49){
                if(e1==1){e1=0;  RA0=e1;  goto K;}
                if(e1==0){e1=1;  RA0=e1;  goto K;}     
               }
               if(o==49){
                if(e2==1){e2=0;  RA1=e2; goto K;}
                if(e2==0){e2=1;  RA1=e2; goto K;}     
               }
               if(p==49){
                if(e3==1){e3=0;   RA2=e3; goto K;}
                if(e3==0){e3=1;   RA2=e3; goto K;}    
               }
               if(q==49){
                if(e4==1){e4=0;  RA3=e4; goto K;}
                if(e4==0){e4=1;  RA3=e4; goto K;}     
               }
               if(r==49){
                if(e5==1){e5=0;  RA4=e5; goto K;}
                if(e5==0){e5=1;  RA4=e5; goto K;}         
               }                                          
           }              
                                                  
         if(portb==4 && bit_test(portc,0)==0) {//porta=L;
           n=conf[67];
           o=conf[68];
           p=conf[69];
           q=conf[70];
           r=conf[71];
               if(n==49){
                if(e1==1){e1=0;  RA0=e1; goto K;}
                if(e1==0){e1=1;  RA0=e1; goto K;}     
               }
               if(o==49){
                if(e2==1){e2=0;  RA1=e2; goto K;}
                if(e2==0){e2=1;  RA1=e2; goto K;}     
               }
               if(p==49){
                if(e3==1){e3=0;  RA2=e3; goto K;}
                if(e3==0){e3=1;  RA2=e3; goto K;}    
               }
               if(q==49){
                if(e4==1){e4=0;  RA3=e4; goto K;}
                if(e4==0){e4=1;  RA3=e4; goto K;}     
               }
               if(r==49){
                if(e5==1){e5=0;  RA4=e5;  goto K;}
                if(e5==0){e5=1;  RA4=e5;  goto K;}  
               }                 
            }
               
         if(portb==3 && bit_test(portc,0)==0) {//porta=M;
           n=conf[73];
           o=conf[74];
           p=conf[75];
           q=conf[76];
           r=conf[77];            
              if(n==49){
                if(e1==1){e1=0;  RA0=e1; goto K;}
                if(e1==0){e1=1;  RA0=e1; goto K;}     
               }
               if(o==49){
                if(e2==1){e2=0;  RA1=e2; goto K;}
                if(e2==0){e2=1;  RA1=e2; goto K;}     
               }
               if(p==49){
                if(e3==1){e3=0;  RA2=e3; goto K;}
                if(e3==0){e3=1;  RA2=e3; goto K;}     
               }
               if(q==49){
                if(e4==1){e4=0;  RA3=e4; goto K;}
                if(e4==0){e4=1;  RA3=e4; goto K;}     
               }
               if(r==49){
                if(e5==1){e5=0;  RA4=e5;  goto K;}
                if(e5==0){e5=1;  RA4=e5;  goto K;}   
               }                     
            }
                                                                    
         if(portb==2 && bit_test(portc,0)==0) {//porta=N;
           n=conf[79];
           o=conf[80];
           p=conf[81];
           q=conf[82];
           r=conf[83];                     
               if(n==49){
                if(e1==1){e1=0;  RA0=e1; goto K;}
                if(e1==0){e1=1;  RA0=e1; goto K;}     
               }
               if(o==49){
                if(e2==1){e2=0;  RA1=e2; goto K;}
                if(e2==0){e2=1;  RA1=e2; goto K;}     
               }
               if(p==49){
                if(e3==1){e3=0;  RA2=e3; goto K;}
                if(e3==0){e3=1;  RA2=e3; goto K;}     
               }
               if(q==49){
                if(e4==1){e4=0;  RA3=e4; goto K;}
                if(e4==0){e4=1;  RA3=e4; goto K;}     
               }
               if(r==49){
                if(e5==1){e5=0;  RA4=e5; goto K;}
                if(e5==0){e5=1;  RA4=e5; goto K;}  
               }           
            }
                                                                                   
         if(portb==1 && bit_test(portc,0)==0) {//porta=O;
           n=conf[85];
           o=conf[86];
           p=conf[87];
           q=conf[88];
           r=conf[89];
               if(n==49){
                if(e1==1){e1=0;  RA0=e1; goto K;}
                if(e1==0){e1=1;  RA0=e1; goto K;}     
               }
               if(o==49){
                if(e2==1){e2=0;  RA1=e2; goto K;}
                if(e2==0){e2=1;  RA1=e2; goto K;}     
               }
               if(p==49){
                if(e3==1){e3=0;  RA2=e3;  goto K;}
                if(e3==0){e3=1;  RA2=e3;  goto K;}     
               }
               if(q==49){
                if(e4==1){e4=0;  RA3=e4; goto K;}
                if(e4==0){e4=1;  RA3=e4; goto K;}     
               }
               if(r==49){
                if(e5==1){e5=0;  RA4=e5; goto K;}
                if(e5==0){e5=1;  RA4=e5; goto K;}   
               }
                    
          }
   }

}


L:                                                             //APLICA EFECTOS DEL MODO DE OPERACION 2
IF(C==1){                                                // si C es diferente de 0 significa que se encuentra en el modo de operacion 2
   RA0=(conf[31]);    RA1=(conf[32]);   RA2=(conf[33]);
    RA3=(conf[34]);    RA4=(conf[35]);
}
IF(C==2){
   RA0=(conf[37]);    RA1=(conf[38]);   RA2=(conf[39]);
    RA3=(conf[40]);    RA4=(conf[41]);
}
IF(C==3){
   RA0=(conf[43]);    RA1=(conf[44]);   RA2=(conf[45]);
    RA3=(conf[46]);    RA4=(conf[47]);
}
IF(C==4){
      RA0=(conf[49]);    RA1=(conf[50]);   RA2=(conf[51]);
        RA3=(conf[52]);    RA4=(conf[53]);
}
IF(C==5){   
   RA0=(conf[55]);    RA1=(conf[56]);   RA2=(conf[57]);
    RA3=(conf[58]);    RA4=(conf[59]);
}

      
      
   }

}


// carrega biblioteca wire
#include <Wire.h>



String  txt  =  " " ;
int  AcX , AcY , AcZ ;
const  int  MPU = 0x68 ;  


void  setup () {
  Serial . começar ( 9600 );
  // inicializaçãoiza o acelerometro
  Wire . escrever ( 0 );
  Wire . endTransmission ( true );
  
  
}

void  loop () {
  Wire . beginTransmission ( MPU );
  Wire . escreva ( 0x3B );  // começando com o registrador 0x3B (ACCEL_XOUT_H)
  Wire . endTransmission ( false );
  // solicitar dados do sensor
  Wire . requestFrom ( MPU , 14 , true );  
  // Armazém ou valor das luzes nas variaveis correspondentes
  AcX = fio . ler () << 8 | Wire . ler ();  // 0x3B (ACCEL_XOUT_H) e 0x3C (ACCEL_XOUT_L)     
  AcY = Wire . ler () << 8 | Wire . ler ();  // 0x3D (ACCEL_YOUT_H) e 0x3E (ACCEL_YOUT_L)
  AcZ = fio . ler () << 8 | Wire . ler ();  // 0x3F (ACCEL_ZOUT_H) e 0x40 (ACCEL_ZOUT_L)
 
  // TESTE NO CONSOLE SERIAL com dados do eixos
  Serial . print ( " X: " );
  Serial . impressão ( AcX );

  Serial . print ( " Y: " );
  Serial . impressão ( AcY );

  Serial . imprimir ( " Z: " );
  Serial . impressão ( AcZ );
  // TESTE 2 COM RESULTADO DO EIXO, Precisa passar no teste1
  // E de acordo com o teste 1 criar uma logica abaixo. EXEMPLO ..
//
//   if (AcX <300) {
//     Serial.print ("Número 1");
//   } else if (AcZ <360 && (AcY> 330)) {
//     Serial.print ("Número 2");
//   }
  // traduzir valores do eixos para número
  

  // Aguarda 300 ms e reinicia o processo
  atraso ( 300 );
}

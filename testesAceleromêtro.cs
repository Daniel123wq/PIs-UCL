//carrega biblioteca wire
#include<Wire.h>



String txt = "";
int AcX,AcY,AcZ;
const int MPU=0x68;  


void setup(){
  Serial.begin(9600);
  //inicializa o acelerometro
  Wire.write(0); 
  Wire.endTransmission(true);
  
  
}

void loop(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  //solicita dados do sensor
  Wire.requestFrom(MPU,14,true);  
  //Armazena o valor dos sensores nas variaveis correspondentes
  AcX=Wire.read()<<8|Wire.read();  //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
 
  //TESTE NO CONSOLE SERIAL com dados do eixos
  Serial.print("X: ");
  Serial.print(AcX);

  Serial.print("Y: ");
  Serial.print(AcY);

  Serial.print("Z: ");
  Serial.print(AcZ);
  // TESTE 2 COM RESULTADO DO EIXO, Precisa passar no teste1
  // E de acordo com o teste 1 criar a logica abaixo. EXEMPLO..
//
//  if(AcX < 300){
//    Serial.print("Número 1");
//  }else if (AcZ < 360 && (AcY >330)){
//    Serial.print("Número 2");
//  }
  //traduzir valores do eixos para número
  

  //Aguarda 300 ms e reinicia o processo
  delay(300);
}

//carrega biblioteca wire
#include<Wire.h>



String txt = "";
int AcX,AcY,AcZ,GyX,GyY,GyZ;
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
  GyX=Wire.read()<<8|Wire.read();  //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  
	//traduzir valores do eixos para número
  

  //Aguarda 300 ms e reinicia o processo
  delay(300);
}


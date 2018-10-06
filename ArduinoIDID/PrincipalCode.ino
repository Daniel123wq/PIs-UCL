//carrega biblioteca wire
#include<Wire.h>

//Carrega biblioteca para transformar pinDigital em Serial ( rx tx serial)
#include<SoftwareSerial.h>


SoftwareSerial serial1(4,5); // RX ==2 TX==3

String txt = "";
int AcX, AcY, AcZ;
const int MPU = 0x68;


void setup() {
  Serial.begin(9600);
  serial1.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);

  //inicializa o acelerometro
  Wire.write(0);
  Wire.endTransmission(true);


}

void loop() {
  //char ladoDado;


  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  //solicita dados do sensor
  Wire.requestFrom(MPU, 14, true);
  //Armazena o valor dos sensores nas variaveis correspondentes
  AcX = Wire.read() << 8 | Wire.read(); //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read(); //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read(); //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)

  //TESTE NO CONSOLE SERIAL com dados do eixos
  // TESTE 1�TESTE 1�TESTE 1�TESTE 1�TESTE 1�TESTE 1�TESTE 1�TESTE 1� AP�S O TESTE, APAGAR OS SERIAL PRINT
//  Serial.print("X: ");
//  Serial.print(AcX);
//  Serial.print("    ");
//  Serial.print("Y: ");
//  Serial.print(AcY);
//  Serial.print("    ");
//  Serial.print("Z: ");
//  Serial.print(AcZ);
//  Serial.print("\n");
  ///////////////////////////////////////////////////////////////////////////////  //
  ////traduzir valores do eixos para n�mero   >>>>>>LOGICA PRINCIPAL<<<<<<        //
  //// TESTE 2 TESTE 2TESTE 2TESTE 2TESTE 2TESTE 2TESTE 2TESTE 2                  //
  ////COM RESULTADO DO EIXO, Precisa passar no teste1                             //
  //// E de acordo com o teste 1 criar a logica abaixo. EXEMPLO..                 //
  //////////////////////////////////////////////////////////////////////////////////
            if ((AcX >= -7028 && AcX <= 8220) && (AcY >= -5164 && AcY <= 1192) && (AcZ >= -13440 && AcZ <= -15900))
                      {
                Serial.print("1");
                serial1.print("1");

                      }
            if ((AcX >= 15416 && AcX <= 16184) && (AcY >= -3264 && AcY <= -1936) && (AcZ >= -1696 && AcZ <= 4596))
            {
               Serial.print("2");
               serial1.print("2");

            }
            if ((AcX >= -2772 && AcX <= 1052) && (AcY >= 13772 && AcY <= 15084) && (AcZ >= -5428 && AcZ <= 6892))
            {
              Serial.print("3");
                              serial1.print("3");

            }
            if ((AcX >= -1272 && AcX <= 272) && (AcY >= -17920 && AcY <= -17372) && (AcZ >= -3364 && AcZ <= 2380))
            {
               Serial.print("4");
                               serial1.print("4");

            }
            if ((AcX >= -20860 && AcX <= -15032) && (AcY >= -7000 && AcY <= 2792) && (AcZ >= -6996 && AcZ <= 11296))
            {
               Serial.print("5");
                               serial1.print("5");

            }
            if ((AcX >= -5832 && AcX <= 18040) && (AcY >= -9980 && AcY <= 9128) && (AcZ >= 312 && AcZ <= 23084))
            {
               Serial.print("6");
                               serial1.print("6");

            }
            


  //
  ////////////////////////////////////////////////////////////////////////////////////////////////
  ////ENVIA INFO VIA BLUETOOTH                                                                 ///
  ////                                                                                          //
  //char meEnvieLado = '0';                                                                     //
  //// O jogo solicitar� o envio do n�mero do lado e se for == 1 ele envia o n�mero do LADO     //
  //  if (serial1.available()){                                                                 //
  //    meEnvieLado = serial1.read();                                                           //
  //    // 0 n�o envie,  1 envie                                                                //
  //    if(meEnvieLado == '1'){                                                                 //
  //      serial1.print(ladoDado);                                                              //
  //    }                                                                                       //
  //  }                                                                                         //
  ////////////////////////////////////////////////////////////////////////////////////////////////


  //Aguarda 300 ms e reinicia o processo

  delay(200);
}

#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_BMP085.h>


const int Mpu_Addr = 0x68,SDA=8,SCL=9;

int16_t AcX, AcY, AcZ;

float altitude;
File Altitude,AC;

Adafruit_BMP085 bmp;

void setup() {
  Wire.begin(SDA,SCL);
  Serial.begin(9600);


  if(!SD.begin(10)){
    Serial.println("SD card Module is not valid");
    while(1){}
  }

  if(!bmp.begin()){
    Serial.println("BMP180 is not valid");
    while(1){}
  }


  Wire.beginTransmission(Mpu_Addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  
  delay(1000);
}

void loop() {
 
  Wire.beginTransmission(Mpu_Addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  
  if(Wire.requestFrom(Mpu_Addr, 6, true)==6){

      AcX=Wire.read() << 8 | Wire.read();
      AcY=Wire.read() << 8 | Wire.read();
      AcZ=Wire.read() << 8 | Wire.read();
  } else{
    Serial.println("Failed to read");
  }
float AcX_ms2=(AcX/16384.0)*9.81;
float AcY_ms2=(AcY/16384.0)*9.81;
float AcZ_ms2=(AcZ/16384.0)*9.81;


  
//Accelerometer MPU6050
  Serial.print(millis());
  Serial.print("\tAc X = ");
  Serial.print(AcX_ms2);
  Serial.print(" m/s2");
  Serial.print("\tAc Y = ");
  Serial.print(AcY_ms2);
  Serial.print(" m/s2");
  Serial.print("\tAc Z = ");
  Serial.print(AcZ_ms2);
  Serial.println(" m/s2");

  

//Altitude BMP180
altitude = bmp.readAltitude();
  Serial.print(millis());
  Serial.print("\tAltitude = ");
  Serial.print(altitude);
  Serial.println(" Meter");


//SD Card Module
  Altitude = SD.open("Altitude.txt",FILE_WRITE);
      if(Altitude){
        Altitude.print(millis());
        Altitude.print("\tAltitude = ");
        Altitude.print(altitude);
        Altitude.println( "Meter");
        Altitude.close();
      }else{
        Serial.println("cant open File");
      }


      AC=SD.open("acc.txt",FILE_WRITE);
        if(AC){
          AC.print(millis());
          AC.print("\tAc X = ");
          AC.print(AcX_ms2);
          AC.print(" m/s2");
          AC.print("\tAc Y = ");
          AC.print(AcY_ms2);
          AC.print(" m/s2");
          AC.print("\tAc Z = ");
          AC.print(AcZ_ms2);
          AC.println(" m/s2");
          
          AC.close();
        }else{
          Serial.println("cant open File");
        }


delay(1000);
}

**HARDWARE**
ESP32-S3

BMP180

MPU6050

SD Card Module

**LIBARY**
Wire.h

Adafruit_BMP085.h

SPI.h

SD.h

**PINOUT**
<img width="374" height="666" alt="Pinout-removebg-preview" src="https://github.com/user-attachments/assets/ce743bbd-9967-4696-99cc-3535c7053860" />

 
	MPU6050
	
VCC to 3.3v

GND to GND

SDA to GPIO 8

SCL to GPIO 9

	BMP180
	
VCC to 3.3v

GND to GND

SDA TO GPIO 8 (same as MPU6050)

SCL TO GPIO 9 (same as MPU6050)

(because they both are communicating using I2C where the master using address to identify which component they "talking" to)

	SD Card Module
VCC to 3.3v

GND to GND

CS to GPIO 10

MOSI to GPIO 11

MISO to GPIO 13

SCK TO GPIO 12

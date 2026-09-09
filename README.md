# Introduction
A simple flight data logger for ameteur rocket have a task to get the data about how high the rocket and how fast the rocket accelerating. Of course it can always be improved like when the rocket reaches apogee, where the rocket have no acceleration, it will move a servo that trigger a latch mechanism and realasing a parachute. In order to do that Accelerometer (inside MPU6050) and pressure sensor (BMP180) are a great choice. These will be used to built a simple flight data logger, where the data from both of the sensor will be stored inside an SD-Card module. This SD-Card module  and 4-Wires communication protocol SPI (Serial Peripheral Interface) will be the main focus in this repasitory.

HARDWARE
-------------
* ESP32-S3
* BMP180
* MPU6050
* SD Card Module

>[!NOTE]
>MPU6050 and BMP180 already have built in pull up resisitor

LIBARY
-------
* Wire.h
* Adafruit_BMP085.h
* SPI.h
* SD.h

PINOUT
----------
ESP32 | MPU6050 | BMP180 | SD Card Module
----  | ------- | ------ | ---------------
3.3v  | VCC     | VCC    | VCC
GND   | GND     | GND    | GND
GPIO 8| SDA (I2C) | SDA (I2C) |  -
GPIO 9 | SCL (I2C) | SCL (I2C) | -
GPIO  | -     | -    | MOSI
GPIO  | -     | -    | MISO
GPIO  | -     | -    | CS
GPIO  | -     | -    | SCK


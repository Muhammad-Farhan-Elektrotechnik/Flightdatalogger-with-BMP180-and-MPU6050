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
ESP32-S3 | MPU6050 | BMP180 | SD Card Module
----  | ------- | ------ | ---------------
3.3v  | VCC     | VCC    | VCC
GND   | GND     | GND    | GND
GPIO 8| SDA (I2C) | SDA (I2C) |  -
GPIO 9 | SCL (I2C) | SCL (I2C) | -
GPIO 23 | -     | -    | MOSI
GPIO 19 | -     | -    | MISO
GPIO 5 | -     | -    | CS
GPIO 18 | -     | -    | SCK

More About SPI
----------------

<img width="851" height="382" alt="image" src="https://github.com/user-attachments/assets/2b008406-d2fd-4d9c-851b-a69cb790b7b4" />

SPI (Serial Peripheral Interface) have total 4 wires namely CS (Chip Select), SCLK (Serial Clock), MOSI (Master In Slave Out), MISO (Master in Slave Out). SPI consist of a master and multiple slaves.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

The CS line is first idle at HIGH (1), then the master first need to select which chip (CS) or slave, it want to send or recieve data to, by pulling the logic LOW (0) at CS line. Once pulled LOW (0) the CS line will stay at LOW (0) until the communication is completed before going back to HIGH (1).
>[!NOTE]
>CS line idle at HIGH (1)
<img width="749" height="111" alt="image" src="https://github.com/user-attachments/assets/e116ab6e-eeb3-4bb7-9f46-1f4536aff40e" />

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Mosi is used to send data from master to slave, hence the name itself Master Out Slave In. The data will be sent as bytes and multiple bytes can be sent sequentially.

<img width="547" height="45" alt="image" src="https://github.com/user-attachments/assets/3eb3280a-3bb9-4e2b-a1d7-8e4c1962bff4" />

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
MiSO is used to sent data from slave to master, the opposite of MOSI, the data will also sent as bytes.

<img width="669" height="61" alt="image" src="https://github.com/user-attachments/assets/5f9855a8-c3c0-44db-bd59-933d2e6cce7a" />

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Clock polarity (CPOL) is basically just optimization which logic state is idle for the serial clock. For CPOL = 0 is the SCLK idle at LOW (0) and for CPOL = 1 is the SCLK idle at HIGH (1).
Therefore the first edge and the second edge also called **the leading edge** and **the trailing edge** will be different depend on the clock polarity.
<img width="763" height="353" alt="image" src="https://github.com/user-attachments/assets/d7c7dd3a-2b62-4df3-bed2-12cb1e8915fa" />

There is also so called Clock Phase (CPHA), CPHA decided when the data will be sampled. With CPHA = 0 data will be sampled at the leading edge and witch CPHA = 1 data will be sampled at trailing edge.

<img width="502" height="418" alt="image" src="https://github.com/user-attachments/assets/5e41a649-e88b-4921-ba8c-aa4a1feaa8c7" />

With these two CPHA and CPOL there will be 4 SPI modes depending from CPHA and CPOL.
>[!NOTE]
>By far mode 0 is the most common
<img width="245" height="176" alt="image" src="https://github.com/user-attachments/assets/90055bb1-37e7-4b7b-9831-4b2cfa46d369" />

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Multi slave configuration usually divided by 2 ways. Independent Slaves, where all the slaves share the same MISO,MOSI and SCLK line but each slave have their own CS line.

<img width="336" height="381" alt="image" src="https://github.com/user-attachments/assets/a3601f91-57da-45e7-b0f4-9fc8fd2412e7" />

The second way is more complicated, its called daisy chain/coorprative slave, MISO of one slave connected to MOSI of othe slave making a chain unti the last slave connected back to the master.

<img width="390" height="416" alt="image" src="https://github.com/user-attachments/assets/78ce0520-96f3-4b71-97fc-8c22506984d7" />

>[!TIP]
>Highly reccomend to check out the video that explained it [here](https://youtu.be/0nVNwozXsIc?si=UiU1P3OI7MybQqMt)






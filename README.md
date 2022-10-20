# AiryFi

## AiryFi is an open-source portable sensor that can deliver the quantity and mass of suspended particulates. It includes a PMSA003 sensor that uses a digital output with a 5V working voltage to offer information on suspended particulate matter (PM1.0, PM2.5, and PM10) in the air per unit volume. 

### Features
* PMSA003 sensor for monitoring Air Quality
* On board TFT display 
* Battery Powered
* BME 280 sensor for temperature and humidity monitoring
* ESP8266-12
* Type-C charging 

### Specifications

* Battery charging 
* Optional debug port
* Battery Voltage Sensor
* Boost convertor of 3.7 to 5 volt

### Hardware Overview
AiryFi consists of ESP8266-12E, USB type-C Port for charging and communication, CP2102, Battery Connector, On/Off switch, Flash, PMSA003 sensor selection jumper, BME280 and many more. let's take a closer look on our AiryFi board, and see what other hardwares are present on it:

<img src ="https://github.com/sbcshop/AiryFi/blob/main/images/AiryFi_hardware.png" />

<img src ="https://github.com/sbcshop/AiryFi/blob/main/images/AiryFi_hardware_rear.png" />

### ESP8266
It is a SoC (System on Chip) WiFi microchip for TCP/IP having capability of a microcontroller. It has many general purpose input output(GPIO) pins for interfacing different types of sensors and other monitoring devices.

### USB Type-C Port
For charging and communication with the AiryFy board

### CP2102
The CP2102/9 is a highly-integrated USB-to-UART Bridge Controller providing a simple solution for updating RS232 designs to USB using a minimum of components and PCB space. It is a driver IC for interfacing between USB to our ESP8266.

### Sensor Selection Jumper
This jumper is provided to interfacing  between ESP and PMS sensor for displaying PMS sensor data

### Reset and Flash Button
Reset button is provided for resetting ESP8266 and so this board. Flash button is for flashing or updating firmware in ESP8266 chip.

### Battery Connector and ON/OFF
Battery connector is used for connecting a 3.7volt battery for powering-up AiryFi and this connector also works as the battery charging port.
ON/OFF switch is used for toggle ON and OFF this board according to our need to save battery power consumption..  

### Pinouts/Reserved of pins of AiryFy


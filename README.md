# AiryFi

AiryFi is an open-source portable sensor that can deliver the quantity and mass of suspended particulates. It includes a PMSA003 sensor that uses a digital output with a 5V working voltage to offer information on suspended particulate matter (PM1.0, PM2.5, and PM10) in the air per unit volume. 

### Features
* PMSA003 sensor for monitoring Air Quality
* On board TFT display 
* Battery Powered
* BME 280 sensor for temperature and humidity monitoring
* ESP8266-12E
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
In this device by using ESP8266-12E module we can use this board as server or as client for receiving and sending its data to the user and from the user to AiryFy board respectively with the help of an Android Application.

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
ON/OFF switch is used for toggle ON and OFF this board according to our need to save battery power consumption.

#### Attention:
* Please make sure that powering battery of AiryFi board should not be more than 3.7volt. voltage of your baord more than 3.7volt can damage your AiryFi board.
 
### Pinouts/Reserved of pins of AiryFy

<img src ="https://github.com/sbcshop/AiryFi/blob/main/images/AiryFi_pinouts.png" />

### Uploading Firmaware

* For uploading latest frimware to ESP8266 module please click on below link
 https://github.com/nodemcu/nodemcu-flasher

* During uploading the latest firmware to NodeMCU please make sure that sensor selection jumper is open as shown in below image

<img src ="https://github.com/sbcshop/AiryFi/blob/main/images/IMG20221121130128.jpg" />

* After uploading firmware, connect the sensor selection jumper as it is for successful reading of sensor on running code in our AiryfI board

<img src ="https://github.com/sbcshop/AiryFi/blob/main/images/IMG20221121122533.jpg" />

### Steps To Setup the AiryFi
1. Download and install Arduino IDE 
   https://www.arduino.cc/en/software

2. Open Arduino IDE

   <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img6.JPG" />

3. Now install Esp8266 board, for this go to file -> preferences

   <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img7.png" />
  
   * Paste two urls,in "additional board manager urls"
   
     ```http://arduino.esp8266.com/stable/package_esp8266com_index.json```
     
     ```https://dl.espressif.com/dl/package_esp32_index.json```
     
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img8.png" />
   
   * Now install ESP8266 board, go tools -> boards -> board manager
   
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img9.png" />
     
   * Write ESP8266 in search bar
   
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img10.png" />
    
   * Lets, check boards are install or not, go to tools -> boards
   
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img11.png" />
  
 4. Now go to sketch -> include library -> manage libraries
 
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img12.png" />
     
 5. Install all libraries which is mention below
 
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img13.JPG" />
    
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img14.JPG" />
    
 6. Choose Port and ESP8266 board from board manager
 
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img16.png" />
    
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img17.png" />





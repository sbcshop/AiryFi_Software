# AiryFi

<img src ="https://cdn.shopify.com/s/files/1/1217/2104/products/03_3ec113af-3d61-4b44-b423-2ec275826699.png?v=1669110536&width=400" /> <img src = "https://cdn.shopify.com/s/files/1/1217/2104/products/Enclosure02.png?v=1669111302&width=400" />

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

<img src ="https://github.com/sbcshop/AiryFi/blob/main/images/AiryFI.png" />

### ESP8266-12E
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
* Please make sure that powering battery of AiryFi board should not be more than 3.7volt. voltage of your baord more than 3.7volt can damage your AiryFi board. The connection should be proper (+ive and -ive terminal will be in right manner).

<img src ="https://github.com/sbcshop/AiryFi/blob/main/images/IMG20221121122934.jpg" />
 
### Pinouts/Reserved of pins of AiryFy

<img src ="https://github.com/sbcshop/AiryFi/blob/main/images/AiryFi_pinouts.png" />

### Uploading Firmaware

* For uploading latest frimware to ESP8266 module please click on below link
 https://github.com/nodemcu/nodemcu-flasher

* During uploading the latest firmware to NodeMCU please make sure that sensor selection jumper is open as shown in below image

<img src ="https://github.com/sbcshop/AiryFi/blob/main/images/IMG20221121130128.jpg" /> 

* After uploading firmware, connect the sensor selection jumper as it is for successful reading of sensor on running code in our AiryfI board

<img src ="https://github.com/sbcshop/AiryFi/blob/main/images/IMG20221121142725.jpg" />

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

## Working Guide with AiryFi

* For Display the sensors data simply on LCD without internet, upload the code of directory "Air-monitoring Data On LCD".
* To see your sensor data on your smartphone open the directory "Air-monitoring Data on Smartphone" and setup your device according to provided instruction in it.
* To send your sensor data on any cloud plateform(Thingspeak) upload the code of directory "Air-monitoring Data On Thingspeak". You can also choose any of your choice cloud plateform to send your sensor data(necessary changes will require).  
* "Battery Monitoring" code will show battery voltage and a worning when battery of this board gets discharge 


## Documentations

* [AiryFi Hardware](https://github.com/sbcshop/AiryFi_Hardware)
* [Getting Started with NodeMCU](http://www.nodemcu.com/index_en.html)
* [NodeMCU Github Examples](https://github.com/orgs/nodemcu/repositories)
* [NodeMCU Datasheet](https://www.espressif.com/sites/default/files/documentation/0a-esp8266ex_datasheet_en.pdf)

## Related Products

* [Air Monitoring HAT](https://shop.sb-components.co.uk/products/air-monitoring-hat-for-raspberry-pi?_pos=1&_sid=c88f54328&_ss=r)

 ![Air Monitoring HAT](https://cdn.shopify.com/s/files/1/1217/2104/products/4_790d764a-9c5f-47e3-96b4-34035fed05b6.png?v=1612519683&width=400)
 
 * [Pico Air Monitoring Expansion](https://shop.sb-components.co.uk/products/pico-air-wifi-monitoring-expansion?_pos=4&_sid=777d5c359&_ss=r)
 
 ![Pico Air Monitoring](https://cdn.shopify.com/s/files/1/1217/2104/products/PicAirQualityMonitor.png?v=1637644693&width=400)

 * [Air Monitoring Breakout](https://shop.sb-components.co.uk/products/air-monitoring-breakout?_pos=1&_sid=8dbc50256&_ss=r)
 
 ![Air Monitoring Breakout](https://cdn.shopify.com/s/files/1/1217/2104/products/PicAirQualityMonitor.png?v=1637644693&width=400)
 
 * [Pico Sense HAT](https://shop.sb-components.co.uk/products/pico-sense-hat?_pos=1&_sid=893176ed1&_ss=r)
 
 ![Pico Sense HAT](https://cdn.shopify.com/s/files/1/1217/2104/products/PicoSenseHAT.png?v=1639375750&width=400)


## Product License

This is ***open source*** product. Kindly check LICENSE.md file for more information.

Please contact ***support@sb-components.co.uk*** for technical support.
<p align="center">
  <img width="360" height="100" src="https://cdn.shopify.com/s/files/1/1217/2104/files/Logo_sb_component_3.png?v=1666086771&width=300">
</p>

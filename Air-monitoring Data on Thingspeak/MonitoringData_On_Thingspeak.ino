//This is the example code of display data on provided on-baord LCD as well as to send data on Thingspeak
//Developed by sbcomponents

#include <ESP8266WiFi.h>
#include <Arduino_GFX_Library.h>
#include "PMS.h"

PMS pms(Serial);
PMS::DATA data;

#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include <Wire.h>
#include <SPI.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // I2C

#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */

//Arduino_DataBus *bus = create_default_Arduino_DataBus();

Arduino_DataBus *bus = new Arduino_ESP8266SPI(2 /* DC */, 15 /* CS */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, 16 /* RST */, 0 /* rotation */, true /* IPS */,135 /* width */, 240 /* height */,53 /* col offset 1 */, 40 /* row offset 1 */,53 /* col offset 2 */, 40 /* row offset 2 */);
#endif /* !defined(DISPLAY_DEV_KIT) */
/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/
const char* ssid = " ";       //Enter your ssid name
const char* password = " ";  //Enter your password

String apiKey = "2KWL4NUT0MEA8I97";  //Enter your API key
const char* server = "api.thingspeak.com"; //Enter your server name

WiFiClient client;

void printWiFiStatus();

void setup(void)
{
  Serial.begin(9600);   // GPIO1, GPIO3 (TX/RX pin on ESP-12E Development Board)
    gfx->begin();
    gfx->fillScreen(BLACK);

#ifdef TFT_BL
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
#endif

    gfx->setCursor(10, 10);
    gfx->setTextColor(RED);
    gfx->setTextSize(2);
    gfx->println("Connecting.......");

  WiFi.begin(ssid, password);
  //server.begin();
  
   // Check if module is still connected to WiFi.
  if (WiFi.status() != WL_CONNECTED) {
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
    }
    // Print the new IP to Serial.
    printWiFiStatus();
  }
  //Serial1.begin(9600);  // GPIO2 (D4 pin on ESP-12E Development Board)
  Serial.println(F("BME280 test"));
  bool status;
  status = bme.begin(0x76);  


////////////////////////////////////////
  //pmsaSer.begin(9600);
  //pmsaSer.println("  PMSA003 dust sensor");



    delay(5000); // 5 seconds
}

void loop()
{
  if (pms.read(data))
  {
    /*
    pmsaSer.print("PM 1.0 (ug/m3): ");
    pmsaSer.println(data.PM_AE_UG_1_0);
    //swSer.println(data.PM_AE_UG_1_0);

    pmsaSer.print("PM 2.5 (ug/m3): ");
    pmsaSer.println(data.PM_AE_UG_2_5);
    //swSer.println(data.PM_AE_UG_2_5);

    pmsaSer.print("PM 10.0 (ug/m3): ");
    pmsaSer.println(data.PM_AE_UG_10_0);
    //swSer.println(data.PM_AE_UG_1_0);
    pmsaSer.println();

    */
    gfx->setTextWrap(false);
    gfx->fillScreen(BLACK);
    gfx->setCursor(5, 10);
    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->println("Air");


    gfx->setTextWrap(false);
    //tft.fillScreen(ST77XX_YELLOW);
    gfx->setCursor(5, 40);
    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->println("Monitor");

    gfx->setTextWrap(false);
    //tft.fillScreen(ST77XX_YELLOW);
    gfx->setCursor(5, 70);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(3);
    gfx->println("(ug/m3)");

         
    gfx->setCursor(5, 120);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("PM 1 =" + String(data.PM_AE_UG_1_0));
  
  
    gfx->setCursor(5, 150);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("PM 2.5 =" + String(data.PM_AE_UG_2_5));
  
  
    gfx->setCursor(5, 180);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("PM 10 =" + String(data.PM_AE_UG_10_0));

    delay(2000);
    
    ////////////////////////////////////////////////////////////////////

    gfx->setTextWrap(false);
    gfx->fillScreen(BLACK);
    gfx->setCursor(5, 10);
    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->println("weather");
  
  
    gfx->setCursor(5, 60);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("T=" + String(bme.readTemperature()));
  
  
    gfx->setCursor(5, 90);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("P=" + String(bme.readPressure()));
  
  
    gfx->setCursor(5, 120);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("H=" + String(bme.readHumidity()));


    gfx->setCursor(5, 150);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("Alt=" + String(bme.readAltitude(SEALEVELPRESSURE_HPA)));
    //delay(2000);
  
  
      if (client.connect(server,80))  // "184.106.153.149" or api.thingspeak.com
    {
        String postStr = apiKey;
        postStr +="&field4=";
        postStr += String(data.PM_AE_UG_1_0);
        postStr +="&field5=";
        postStr += String(data.PM_AE_UG_2_5);
        postStr +="&field6=";
        postStr += String(data.PM_AE_UG_10_0);
        //postStr +="&field4=";
        //postStr += String(air_quality);
        postStr +="&field1=";
        postStr += String(bme.readTemperature());
        postStr +="&field2=";
        postStr += String(bme.readHumidity());
        postStr +="&field3=";
        postStr += String(bme.readPressure());
        postStr += "\r\n\r\n";
        
        client.print("POST /update HTTP/1.1\n");
        client.print("Host: api.thingspeak.com\n");
        client.print("Connection: close\n");
        client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
        client.print("Content-Type: application/x-www-form-urlencoded\n");
        client.print("Content-Length: ");
        client.print(postStr.length());
        client.print("\n\n");
        client.print(postStr); 
    }   
    client.stop(); 
    delay(5000); 
    
   }
   
}
 



void printWiFiStatus() {
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  gfx->setTextWrap(false);
  gfx->fillScreen(BLACK);

  gfx->setCursor(5, 10);
  gfx->setTextColor(RED);
  gfx->setTextSize(2);
  gfx->println("CONNECTED");

  gfx->setCursor(5, 40);
  gfx->setTextColor(GREEN);
  gfx->setTextSize(2);
  gfx->println("IP ADDRESS");

  String ip = WiFi.localIP().toString();
  String ip1 = ip.substring(0,7);
  String ip2 = ip.substring(10,15);
  gfx->setCursor(5, 80);
  gfx->setTextColor(YELLOW);
  gfx->setTextSize(2);
  gfx->println(ip1);

  gfx->setCursor(5, 100);
  gfx->setTextColor(YELLOW);
  gfx->setTextSize(2);
  gfx->println(ip2);
  
  gfx->setCursor(5, 150);
  gfx->setTextColor(YELLOW);
  gfx->setTextSize(2);
  gfx->println("Connect PMS ");

  gfx->setCursor(2, 180);
  gfx->setTextColor(YELLOW);
  gfx->setTextSize(2);
  gfx->println("Jumpire Wires");

  gfx->setCursor(2, 210);
  gfx->setTextColor(YELLOW);
  gfx->setTextSize(2);
  gfx->println("To start");
  //i = i + 10;
  delay(100);
}

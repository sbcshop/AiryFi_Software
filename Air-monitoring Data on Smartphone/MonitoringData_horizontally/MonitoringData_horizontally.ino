//This is the example file for displaying AiryFi data on Samartphone in Horizontal screen
//Developed by sbcomponents 

#include <ESP8266WiFi.h>
#include <ESP8266WiFi.h>
#include <Arduino_GFX_Library.h>
#include "PMS.h"
//#include <SoftwareSerial.h>
//SoftwareSerial pmsaSer(2,0); //14 rx for dubug

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
Arduino_GFX *gfx = new Arduino_ST7789(bus, 16 /* RST */, 1 /* rotation */, true /* IPS */,135 /* width */, 240 /* height */,53 /* col offset 1 */, 40 /* row offset 1 */,53 /* col offset 2 */, 40 /* row offset 2 */);
#endif /* !defined(DISPLAY_DEV_KIT) */
/*******************************************************************************
 * End of Arduino_GFX setting
 ******************************************************************************/
const char* ssid = "Tech SB_2G"; //Tech SB_2G
const char* password = "jc643111h@";//jc643111
WiFiServer server(8080);

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
    //gfx->println("Hello World!");

  WiFi.begin(ssid, password);
  server.begin();
  
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
  WiFiClient client = server.available();

  if (client)
  {
    while (client.connected()) 
     {
    Serial.println("Client connected.");
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
    gfx->println("Air Monitor");

    /*
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
    */
         
    gfx->setCursor(5, 50);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("PM 1.0 = " + String(data.PM_AE_UG_1_0)+" ug/m3");
  
  
    gfx->setCursor(5, 80);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("PM 2.5 = " + String(data.PM_AE_UG_2_5)+" ug/m3");
  
  
    gfx->setCursor(5, 110);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("PM 10.0 = " + String(data.PM_AE_UG_10_0)+" ug/m3");

    delay(2000);
    
    ////////////////////////////////////////////////////////////////////

    gfx->setTextWrap(false);
    gfx->fillScreen(BLACK);
    gfx->setCursor(5, 10);
    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->println("weather");
  
  
    gfx->setCursor(5, 45);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("Temp =" + String(bme.readTemperature())+" C");
  
  
    gfx->setCursor(5, 65);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("Pressure =" + String(bme.readPressure()));
  
  
    gfx->setCursor(5, 85);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("Humidity =" + String(bme.readHumidity())+" %");


    gfx->setCursor(5, 105);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("Altitude =" + String(bme.readAltitude(SEALEVELPRESSURE_HPA)));
    delay(2000);
  
  }
    if (client.available()) {
        char command = client.read();
        Serial.println(command);
        if (command == 'H') {
          //digitalWrite(ledPin, HIGH);
          client.print(String(data.PM_AE_UG_1_0) + "," + String(data.PM_AE_UG_2_5)+"," + String(data.PM_AE_UG_10_0)+","+ String(bme.readTemperature())+","+String(bme.readHumidity())+"," + String(bme.readAltitude(SEALEVELPRESSURE_HPA)));
        }
        else if (command == 'L') {
          //digitalWrite(ledPin, LOW);
          client.print("0,0,0,0,0,0");
        }
       }
     }
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
  
  gfx->setCursor(5, 70);
  gfx->setTextColor(YELLOW);
  gfx->setTextSize(2);
  gfx->println(WiFi.localIP());

  gfx->setCursor(5, 95);
  gfx->setTextColor(YELLOW);
  gfx->setTextSize(2);
  gfx->println("Connect PMS ");

   gfx->setCursor(5, 115);
  gfx->setTextColor(YELLOW);
  gfx->setTextSize(2);
  gfx->println("Jumpire Wires");
  
  //i = i + 10;
  delay(100);
}

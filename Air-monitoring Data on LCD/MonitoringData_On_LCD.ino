
#include <Arduino_GFX_Library.h>
#include "PMS.h"
#include <SoftwareSerial.h>
SoftwareSerial pmsaSer(2,0); //14 rx for dubug

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

void setup(void)
{
  Serial.begin(9600);   // GPIO1, GPIO3 (TX/RX pin on ESP-12E Development Board)
  Serial1.begin(9600);  // GPIO2 (D4 pin on ESP-12E Development Board)
  Serial.println(F("BME280 test"));
  bool status;
  status = bme.begin(0x76);  

////////////////////////////////////////
  pmsaSer.begin(9600);
  pmsaSer.println("  PMSA003 dust sensor");

    gfx->begin();
    gfx->fillScreen(BLACK);

#ifdef TFT_BL
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
#endif

    //gfx->setCursor(10, 10);
    //gfx->setTextColor(RED);
    //gfx->println("Hello World!");
    
    gfx->setCursor(5, 50);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("Connect PMS");
  
    gfx->setCursor(2, 90);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("Jumpire Wire");
  
    gfx->setCursor(2, 130);
    gfx->setTextColor(YELLOW);
    gfx->setTextSize(2);
    gfx->println("To start");
    delay(2000); // 5 seconds
}

void loop()
{
  if (pms.read(data))
  {
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
    delay(2000);
  
  } 
}

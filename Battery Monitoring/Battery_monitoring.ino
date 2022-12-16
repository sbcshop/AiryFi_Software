//This is the example code of checking battery level and discharge worning on LCD
//Develop by sb-components

#include <ESP8266WiFi.h>
#include <Arduino_GFX_Library.h>


#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */

//Arduino_DataBus *bus = create_default_Arduino_DataBus();

Arduino_DataBus *bus = new Arduino_ESP8266SPI(2 /* DC */, 15 /* CS */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, 16 /* RST */, 0 /* rotation */, true /* IPS */,135 /* width */, 240 /* height */,53 /* col offset 1 */, 40 /* row offset 1 */,53 /* col offset 2 */, 40 /* row offset 2 */);
#endif /* !defined(DISPLAY_DEV_KIT) */

int analogInPin  = A0;    // Analog input pin
int sensorValue;          // Analog Output of Sensor
float calibration = 0.25; // Check Battery voltage using multimeter & add/subtract the value
int bat_percentage;
 
//WiFiClient client;


void setup()
{
  Serial.begin(9600);
  delay(100);
  Serial.print("Battery Voltage ");

    gfx->begin();
    gfx->fillScreen(BLACK);

#ifdef TFT_BL
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
#endif
 
}
 
void loop()
{
  sensorValue = analogRead(analogInPin);
  delay(10);
  float voltage = (((sensorValue * 4.2) / 1024.0) - calibration); //multiply by two as voltage divider network is 100K & 100K Resistor
   // float voltage = (((sensorValue * 3.3) / 1024) + calibration) ; //Caliberation for output voltage

 if (voltage >= 2.8){

    gfx->setTextWrap(true);
    gfx->setRotation(false);
    gfx->fillScreen(BLACK);
    gfx->setCursor(0, 10);
    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->println("BatteryVoltage");

    
    gfx->setTextWrap(false);
    gfx->setCursor(5, 60);
    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->println(voltage);
  delay(2000);
}

else if (voltage <= 2.8){
   Serial.print("Battery Low! Please Plugin Charger");
    gfx->setTextWrap(true);
    gfx->setRotation(true);
    gfx->fillScreen(BLACK);
    gfx->setCursor(0, 25);
    gfx->setTextColor(RED);
    gfx->setTextSize(3);
    gfx->println("Battery Low! Please Charge");
    delay(2000);
  
}
}

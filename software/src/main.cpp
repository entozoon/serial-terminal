#include <Arduino.h>
//
//
// //
// // BLINK
// //
// void setup()
// {
//   pinMode(PC13, OUTPUT);
// }
// void loop()
// {
//   digitalWrite(PC13, HIGH);
//   delay(1000);
//   digitalWrite(PC13, LOW);
//   delay(1000);
// }
//
// RED SCREEN TEST
//
#include "Adafruit_ILI9341.h"
//  CS, DC, MOSI, SCK, RST, MISO
// Adafruit_ILI9341 tft = Adafruit_ILI9341(PA7, PA5, PA4, PA3, PA6, PA2); // works! but not hardware SPI
// CS,DC,RST (also built-in SCK PA5, MISO PA6, MOSI PA7)
Adafruit_ILI9341 tft = Adafruit_ILI9341(PA4, PA2, PA3); // works and faster!
void setup()
{
  tft.begin();
  tft.fillScreen(ILI9341_RED);
}
void loop()
{
}
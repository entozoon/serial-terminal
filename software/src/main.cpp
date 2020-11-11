#include <Arduino.h>
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
//   digitalspiWrite(PC13, HIGH);
//   delay(1000);
//   digitalspiWrite(PC13, LOW);
//   delay(1000);
// }
//
// RED SCREEN TEST
//
// #include "Adafruit_ILI9341.h"
// //  CS, DC, MOSI, SCK, RST, MISO
// // Adafruit_ILI9341 tft = Adafruit_ILI9341(PA7, PA5, PA4, PA3, PA6, PA2); // works! but not hardware SPI
// // CS,DC,RST (also built-in SCK PA5, MISO PA6, MOSI PA7)
// Adafruit_ILI9341 tft = Adafruit_ILI9341(PA4, PA2, PA3); // works and faster!
// void setup()
// {
//   tft.begin();
//   tft.fillScreen(ILI9341_RED);
// }
// void loop()
// {
// }
//
//
// HERE WE GO
//
#include "SPI.h"
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
//
bool shouldScroll = true;
bool wrap = true;
//
// CS,DC,RST (also built-in SCK PA5, MISO PA6, MOSI PA7)
Adafruit_ILI9341 tft = Adafruit_ILI9341(PA4, PA2, PA3); // works and faster!
//
#define ILI9341_VSCRDEF 0x33
#define ILI9341_VSCRSADD 0x37
uint16_t bg = ILI9341_BLACK;
uint16_t fg = ILI9341_ORANGE; // allows escape codes tho!
int screenWd = 240;
int screenHt = 320;
int bold = 0;
int xp = 0;
int yp = 0;
int sx = 1;
int sy = 1;
#include "font_6x8.h"
const uint16_t *fontRects = font_6x8_Rects;
const uint16_t *fontOffs = font_6x8_CharOffs;
int charWd = 6;
int charHt = 9; // real 8
int charYoffs = 1;
void scrollFrame(uint16_t vsp)
{
  // old writecommand(), instead use spiWrite and wrap in DC LOW DC HIGH
  // Also put the whole thing in startWrite endWrite
  tft.startWrite();
  tft.SPI_DC_LOW();
  tft.spiWrite(ILI9341_VSCRSADD); // Vertical scrolling start address
  tft.SPI_DC_HIGH();
  tft.spiWrite(vsp >> 8);
  tft.spiWrite(vsp);
  // tft.spiWrite(vsp);
  tft.endWrite();
}
void scroll()
{
  xp = 0;
  yp += charHt * sy;
  if (yp + charHt > screenHt)
    yp = 0;
  tft.fillRect(0, yp, screenWd, charHt * sy, ILI9341_BLACK);
  if (shouldScroll)
    scrollFrame(320 - yp - charHt * sy);
  else
    scrollFrame(0);
  // Serial.println("Random scrolling");
  // scrollFrame(random(10, 100));
}
void setupScroll(uint16_t tfa, uint16_t bfa)
{
  tft.startWrite();
  tft.SPI_DC_LOW();
  tft.spiWrite(ILI9341_VSCRDEF); // Vertical scroll definition
  tft.SPI_DC_HIGH();
  tft.spiWrite(tfa >> 8);
  tft.spiWrite(tfa);
  tft.spiWrite((320 - tfa - bfa) >> 8);
  tft.spiWrite(320 - tfa - bfa);
  tft.spiWrite(bfa >> 8);
  tft.spiWrite(bfa);
  // tft.spiWrite(tfa);
  // tft.spiWrite(320 - tfa - bfa);
  // tft.spiWrite(bfa);
  tft.endWrite();
}
void drawChar(int16_t x, int16_t y, unsigned char c,
              uint16_t color, uint16_t bg, uint8_t sx, uint8_t sy)
{
  if ((x >= screenWd) ||             // Clip right
      (y >= screenHt) ||             // Clip bottom
      ((x + charWd * sx - 1) < 0) || // Clip left
      ((y + charHt * sy - 1) < 0))   // Clip top
    return;
  if (c > 127)
    return;
  uint16_t recIdx = fontOffs[c];
  uint16_t recNum = fontOffs[c + 1] - recIdx;
  if (bg && bg != color)
    tft.fillRect(x, y, charWd * sx, charHt * sy, bg);
  if (charWd <= 16 && charHt <= 16)
    for (int i = 0; i < recNum; i++)
    {
      int v = fontRects[i + recIdx];
      int xf = v & 0xf;
      int yf = charYoffs + ((v & 0xf0) >> 4);
      int wf = 1 + ((v & 0xf00) >> 8);
      int hf = 1 + ((v & 0xf000) >> 12);
      tft.fillRect(x + xf * sx, y + yf * sy, bold + wf * sx, hf * sy, color);
    }
  else
    for (int i = 0; i < recNum; i++)
    {
      uint8_t *rects = (uint8_t *)fontRects;
      int idx = (i + recIdx) * 3;
      int xf = rects[idx + 0] & 0x3f;
      int yf = rects[idx + 1] & 0x3f;
      int wf = 1 + rects[idx + 2] & 0x3f;
      int hf = 1 + (((rects[idx + 0] & 0xc0) >> 6) | ((rects[idx + 1] & 0xc0) >> 4) | ((rects[idx + 2] & 0xc0) >> 2));
      tft.fillRect(x + xf * sx, y + yf * sy, bold + wf * sx, hf * sy, color);
    }
}
int escMode = 0;
int nVals = 0;
int vals[10] = {0};
void printChar(char c)
{
  if (c == 0x1b)
  {
    escMode = 1;
    return;
  }
  if (escMode == 1)
  {
    if (c == '[')
    {
      escMode = 2;
      nVals = 0;
    }
    else
      escMode = 0;
    return;
  }
  if (escMode == 2)
  {
    if (isdigit(c))
      vals[nVals] = vals[nVals] * 10 + (c - '0');
    else if (c == ';')
      nVals++;
    else if (c == 'm')
    {
      escMode = 0;
      nVals++;
      for (int i = 0; i < nVals; i++)
      {
        int v = vals[i];
        static const uint16_t colors[] = {
            0x0000, // 0-black
            0xf800, // 1-red
            0x0780, // 2-green
            0xfe00, // 3-yellow
            0x001f, // 4-blue
            0xf81f, // 5-magenta
            0x07ff, // 6-cyan
            0xffff  // 7-white
        };
        if (v == 0)
        { // all attributes off
          if (nVals == 1)
          {
            fg = ILI9341_WHITE;
            bg = ILI9341_BLACK;
          }
          bold = 0;
        }
        else if (v == 1)
        { // all attributes off
          bold = 1;
        }
        else if (v >= 30 && v < 38)
        { // fg colors
          fg = colors[v - 30];
        }
        else if (v >= 40 && v < 48)
        {
          bg = colors[v - 40];
        }
      }
      vals[0] = vals[1] = vals[2] = vals[3] = 0;
      nVals = 0;
    }
    else
    {
      escMode = 0;
      vals[0] = vals[1] = vals[2] = vals[3] = 0;
      nVals = 0;
    }
    return;
  }
  if (c == 10)
  {
    scroll();
    return;
  }
  if (c == 13)
  {
    xp = 0;
    return;
  }
  if (c == 8)
  {
    if (xp > 0)
      xp -= charWd * sx;
    tft.fillRect(xp, yp, charWd * sx, charHt * sy, ILI9341_BLACK);
    return;
  }
  if (xp < screenWd)
    drawChar(xp, yp, c, fg, bg, sx, sy);
  xp += charWd * sx;
  if (xp >= screenWd && wrap)
    scroll();
}
void printString(char *str)
{
  while (*str)
    printChar(*str++);
}
void setup()
{
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(2);
  tft.fillScreen(ILI9341_BLACK);
  // tft.setTextSize(3);
  // tft.fillScreen(ILI9341_MAROON);
  // tft.setTextColor(ILI9341_WHITE);
  // tft.setCursor(40, 100);
  // tft.println("Serial");
  // tft.setCursor(40, 150);
  // tft.println("Monitor");
  // tft.setCursor(40, 200);
  // tft.println("Bitch");
  // delay(2000);
  setupScroll(0, 0);
  tft.setCursor(0, 0);
  // Supports oldschool ascii codes within the feed!
  sx = 2;
  sy = 2;
  printString("\e[0;41m    Serial          ");
  printString("\e[0;41m       Monitor      ");
  printString("\e[0;41m          Bitch     \e[0m\n");
  printString("\e[0;33m"); // get it back to orange on black
  sx = 1;
  sy = 1;
}
void loop(void)
{
  while (Serial.available())
    printChar(Serial.read());
}
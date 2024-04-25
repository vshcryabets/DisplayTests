#include "Arduino.h"
#include "ssd1306.h"
#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include "font.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C
SSD1306AsciiWire *oled  = nullptr;

void prepareSSD1306(bool use128)
{
    Wire.begin();
    Wire.setClock(400000L);
    oled = new SSD1306AsciiWire();
    if (use128) {
        oled->begin(&Adafruit128x64, I2C_ADDRESS);
    } else {
        oled->begin(&Adafruit128x32, I2C_ADDRESS);
    }
    oled->setFont(font);
    oled->setLetterSpacing(0);
    oled->clear();
    oled->println("00112233");
}

void drawI2cSSD1306(State &state) {

}
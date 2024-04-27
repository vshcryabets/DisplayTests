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
}

void drawI2cSSD1306(State &state) {
    if (!state.isDirty)
        return;
    oled->clear();
    if (state.selectedMode < 3) {
        return;
    }
    char fillChar = '0';
    if (state.selectedMode == 3 || state.selectedMode == 4) {
    // 25% fill
    fillChar = '0';
    } else if (state.selectedMode == 5 || state.selectedMode == 6) {
    // 50% fill
    fillChar = '1';
    } else if (state.selectedMode == 7 || state.selectedMode == 8) {
    // 100% fill
    fillChar = '3';
    }
    uint8_t height = oled->displayHeight();
    for (uint8_t y = 0; y < height/8; y++) {
        oled->setCursor(0,y);
        for(uint8_t i = 0; i< oled->displayWidth()/8; i++) oled->print(fillChar);
    }
    state.isDirty = false;
}
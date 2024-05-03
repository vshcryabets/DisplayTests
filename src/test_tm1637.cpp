#include "Arduino.h"
#include "test_tm1637.h"

#include <TM1637Display.h>

TM1637Display   *displayTM1637 = nullptr;
uint8_t  all_str[]   = {0xF0, 0xF0, 0x0F, 0x0F};  

void prepareTM1637(uint8_t clPin, uint8_t dioPin)
{
    displayTM1637 = new TM1637Display(clPin, dioPin);
    displayTM1637->setBrightness(0x01);
}

void drawTM1637(State &state)
{
    if (state.isDirty) {
        displayTM1637->setSegments(all_str);
        state.isDirty = false;
    }
}
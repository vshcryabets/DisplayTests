#include "Arduino.h"
#include "test_tm1637.h"

#include <TM1637Display.h>

TM1637Display   *displayTM1637 = nullptr;
uint8_t  s0_str[]   = {0x00, 0x00, 0x00, 0x00};  
uint8_t  s25_str[]   = {0xFF, 0x00, 0x00, 0x00};  
uint8_t  s50_str[]   = {0xFF, 0xFF, 0x00, 0x00};  
uint8_t  all_str[]   = {0xFF, 0xFF, 0xFF, 0xFF};  

void prepareTM1637(uint8_t clPin, uint8_t dioPin, State &state)
{
    displayTM1637 = new TM1637Display(clPin, dioPin);
    displayTM1637->setBrightness(0x00);
    state.maxMode = 4;
}

void drawTM1637(State &state)
{
    if (state.isDirty) {
        switch (state.selectedMode) {
            case 1:
                displayTM1637->setSegments(s0_str);
                break;
            case 2:
                displayTM1637->setSegments(s25_str);
                break;
            case 3:
                displayTM1637->setSegments(s50_str);
                break;
            case 4:
                displayTM1637->setSegments(all_str);
                break;
        }
        state.isDirty = false;
    }
}
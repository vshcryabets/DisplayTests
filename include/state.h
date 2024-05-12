#pragma once
#include <stdint.h>

struct State {
    uint8_t maxMode = 8;
    uint8_t selectedMode = 1;
    bool isDirty = true;
    uint32_t btnPressed = 0;
    uint16_t displayWidth;
    uint16_t displayHeight;
};
#pragma once
#include <stdint.h>

struct State {
    uint8_t selectedMode = 1;
    bool isDirty = true;
};
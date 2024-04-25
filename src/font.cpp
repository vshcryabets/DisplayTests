#include "font.h"

uint8_t font[38] PROGMEM = {
    0x0, 0x0, // size of zero indicates fixed width font,
    0x08, // width
    0x08, // height
    0x30, // first char
    0x04, // char count

    0x55, 0x00, 0x55, 0x00, 0x55, 0x00, 0x55, 0x00, // 25%
	0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, // 50% block
	0xFF, 0x55, 0xFF, 0x55, 0xFF, 0x55, 0xFF, 0x55, // 75% block
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF // 100%
};
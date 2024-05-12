#include "test_lcd.h"
#include "Arduino.h"
#include <stdint.h>
#include <LiquidCrystal_I2C.h>
#include "font.h"


#define LCD_SPACE_SYMBOL 0x20 //space symbol from LCD ROM, see p.9 of GDM2004D datasheet or english ASCII printable characters

LiquidCrystal_I2C *lcd = nullptr;

void prepareLcd(uint8_t columns, uint8_t rows, State &state) {
  lcd = new LiquidCrystal_I2C(PCF8574_ADDR_A21_A11_A01, 4, 5, 6, 16, 11, 12, 13, 14, POSITIVE);
    while (lcd->begin(columns, rows, LCD_5x8DOTS, PB7, PB6, 400000) != 1) //colums, rows, characters size, SDA, SCL, I2C speed in Hz
  {
    Serial.println(F("PCF8574 is not connected or lcd pins declaration is wrong. Only pins numbers: 4,5,6,16,11,12,13,14 are legal."));
    delay(5000);
  }
  Serial.println(F("PCF8574 is OK..."));
  lcd->print(F("PCF8574 is OK...")); //(F()) saves string to flash & keeps dynamic memory free
  delay(1000);
  lcd->createChar(0, font + 6);
  lcd->createChar(1, font + 6 + 8);
  lcd->createChar(2, font + 6 + 16);
  lcd->noBacklight();
  lcd->clear();
  state.displayWidth = columns;
  state.displayHeight = rows;
}

void drawI2cLcd1602(State &state) {
  if (!state.isDirty) 
    return;
  lcd->clear();
  lcd->setCursor(0, 0);
  if (state.selectedMode & 1 != 0) {
    lcd->noBacklight();
  } else {
    lcd->backlight();
  }
  if (state.selectedMode < 3) {
    return;
  }
  uint8_t fillChar = 0;
  if (state.selectedMode == 3 || state.selectedMode == 4) {
    // 25% fill
    fillChar = 0;
  } else if (state.selectedMode == 5 || state.selectedMode == 6) {
    // 50% fill
    fillChar = 1;
  } else if (state.selectedMode == 7 || state.selectedMode == 8) {
    // 100% fill
    fillChar = 2;
  }
  for (uint8_t row = 0; row < state.displayHeight; row++) {
    lcd->setCursor(0, row);
    for(uint8_t i = 0; i< state.displayWidth; i++) lcd->write(fillChar);
  }
  state.isDirty = false;
}
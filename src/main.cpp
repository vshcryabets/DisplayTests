#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "state.h"

enum WorkMode {
  I2C_LCD1604
};

#define COLUMS           16   //LCD columns
#define ROWS             2    //LCD rows
#define LCD_SPACE_SYMBOL 0x20 //space symbol from LCD ROM, see p.9 of GDM2004D datasheet or english ASCII printable characters
const uint8_t fill25[8]    PROGMEM = {0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55};
const uint8_t fill50[8]    PROGMEM = {0x55, 0x00, 0x55, 0x00, 0x55, 0x00, 0x55, 0x00};
const uint8_t fill100[8]    PROGMEM = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

LiquidCrystal_I2C lcd(PCF8574_ADDR_A21_A11_A01, 4, 5, 6, 16, 11, 12, 13, 14, POSITIVE);

uint8_t workMode = I2C_LCD1604;
State state;

void printMenu() {
  Serial.println(F("1 - empty screen, no backlight"));
  Serial.println(F("2 - empty screen, with backlight"));
  Serial.println(F("3 - 25%% fill, no backlight"));
  Serial.println(F("4 - 25%% fill, with backlight"));
  Serial.println(F("5 - 50%% fill, no backlight"));
  Serial.println(F("6 - 50%% fill, with backlight"));
  Serial.println(F("7 - 100%% fill, no backlight"));
  Serial.println(F("8 - 100%% fill, with backlight"));
  Serial.println(F("\n\n"));
}

void prepareLcd1604() {
    while (lcd.begin(COLUMS, ROWS, LCD_5x8DOTS, PB7, PB6, 400000) != 1) //colums, rows, characters size, SDA, SCL, I2C speed in Hz
  {
    Serial.println(F("PCF8574 is not connected or lcd pins declaration is wrong. Only pins numbers: 4,5,6,16,11,12,13,14 are legal."));
    delay(5000);
  }
  Serial.println(F("PCF8574 is OK..."));
  lcd.print(F("PCF8574 is OK...")); //(F()) saves string to flash & keeps dynamic memory free
  delay(1000);
  lcd.createChar(0, fill25);
  lcd.createChar(1, fill50);
  lcd.createChar(2, fill100);
  lcd.noBacklight();
  lcd.clear();
}

void setup() {
  Serial.begin(9600);
  delay(1500);
  Serial.println("Begin 1");
  if (workMode == I2C_LCD1604) {
    prepareLcd1604();
  }
  printMenu();
}

void drawI2cLcd1604(State &state) {
  if (!state.isDirty) 
    return;
  lcd.clear();
  lcd.setCursor(0, 0);
  if (state.selectedMode & 1 != 0) {
    lcd.noBacklight();
  } else {
    lcd.backlight();
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
  for(uint8_t i =0; i< 16; i++) lcd.write(fillChar);
  lcd.setCursor(0, 1);
  for(uint8_t i =0; i< 16; i++) lcd.write(fillChar);
}

void loop()
{
  if (workMode == I2C_LCD1604) {
    drawI2cLcd1604(state);
  }
  delay(100);
  while (Serial.available()) {
    uint8_t ch = Serial.read();
    if ((ch >= '1') && (ch <= '8')) {
      state.selectedMode = ch - '0';
      state.isDirty = true;
      Serial.print(F("Selected mode "));
      Serial.println(state.selectedMode);
    }
    printMenu();
  }
}

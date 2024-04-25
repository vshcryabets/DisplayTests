#include <Arduino.h>
#include <Wire.h>
#include "state.h"
#include "lcd1604.h"
#include "ssd1306.h"

enum WorkMode
{
  I2C_LCD1604,
  I2C_SSD1306_128x64,
  I2C_SSD1306_128x32
};

uint8_t workMode = I2C_SSD1306_128x64;
State state;

void printMenu()
{
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

void setup()
{
  Serial.begin(9600);
  delay(1500);
  Serial.println("Begin 1");
  if (workMode == I2C_LCD1604)
  {
    prepareLcd1604();
  }
  else if (workMode == I2C_SSD1306_128x64)
  {
    prepareSSD1306(true);
  }
  else if (workMode == I2C_SSD1306_128x32)
  {
    prepareSSD1306(false);
  }

  printMenu();
}

void loop()
{
  if (workMode == I2C_LCD1604)
  {
    drawI2cLcd1604(state);
  }
  else if (workMode == I2C_SSD1306_128x64)
  {
    drawI2cSSD1306(state);
  }

  delay(100);
  while (Serial.available())
  {
    uint8_t ch = Serial.read();
    if ((ch >= '1') && (ch <= '8'))
    {
      state.selectedMode = ch - '0';
      state.isDirty = true;
      Serial.print(F("Selected mode "));
      Serial.println(state.selectedMode);
    }
    printMenu();
  }
}

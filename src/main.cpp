#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

enum WorkMode {
  I2C_LCS1604
};
/*
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Wire.begin();
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  // lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("111111");
  //  lcd.setCursor(0,2);
  // lcd.print("Arduino LCM IIC 2004");
  //  lcd.setCursor(2,3);
  // lcd.print("Power By Ec-yuan!");
}


void loop()
{
}*/


#define COLUMS           16   //LCD columns
#define ROWS             2    //LCD rows
#define LCD_SPACE_SYMBOL 0x20 //space symbol from LCD ROM, see p.9 of GDM2004D datasheet or english ASCII printable characters

LiquidCrystal_I2C lcd(PCF8574_ADDR_A21_A11_A01, 4, 5, 6, 16, 11, 12, 13, 14, POSITIVE);

void setup() {
  Serial.begin(9600);
  delay(1500);
  Serial.println("Begin 1");
  while (lcd.begin(COLUMS, ROWS, LCD_5x8DOTS, PB7, PB6, 400000) != 1) //colums, rows, characters size, SDA, SCL, I2C speed in Hz
  {
    Serial.println(F("PCF8574 is not connected or lcd pins declaration is wrong. Only pins numbers: 4,5,6,16,11,12,13,14 are legal."));
    delay(5000);
  }

  Serial.println(F("PCF8574 is OK..."));
  lcd.print(F("PCF8574 is OK...")); //(F()) saves string to flash & keeps dynamic memory free
  delay(1000);

  lcd.noBacklight();

  lcd.clear();

  lcd.print(F("Hello world!"));
  lcd.setCursor(0, 1);              //set 1-st colum & 2-nd row
  lcd.print(F("Random number:"));
  Serial.println("Begin 4");
}

void loop()
{
  lcd.setCursor(14, 1);             //set 15-th colum & 2-nd row
  lcd.print(random(10, 1000));
  lcd.write(LCD_SPACE_SYMBOL);      //"write(0x20)" faster than "print(" ")"

  delay(1000);
}

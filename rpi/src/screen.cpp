// Copyright2019 Charlie WIlkin

#include "../include/screen.hpp"
#include <wiringPi.h>
#include <lcd.h>

//USE WIRINGPI PIN NUMBERS
#define LCD_RS  25               //Register select pin
#define LCD_E   24               //Enable Pin
#define LCD_D0  29               //Data pin D0
#define LCD_D1  28               //Data pin D1
#define LCD_D2  27               //Data pin D2
#define LCD_D3  26               //Data pin D3
#define LCD_D4  23               //Data pin D4
#define LCD_D5  22               //Data pin D5
#define LCD_D6  21               //Data pin D6
#define LCD_D7  14               //Data pin D7


Screen::Screen() {
  int lcd;
  wiringPiSetup();
  lcd = lcdInit (2, 16, 8, LCD_RS, LCD_E, LCD_D0, LCD_D1, LCD_D2, LCD_D3,
		 LCD_D4, LCD_D5, LCD_D6, LCD_D7);

  lcdPosition(lcd, 0, 0); 
  lcdPuts(lcd, "Dial to set ABV");
}

void Screen::print(int abv) {
  std::string text;
  text = "ABV: ";
  text += std::to_string(abv);
  text += "%";
      
  lcdPosition(lcd, 0, 1);
  lcdPuts(lcd, text);
}  


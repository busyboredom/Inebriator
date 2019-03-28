// Copyright2019 Charlie WIlkin

#include "../include/screen.hpp"

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


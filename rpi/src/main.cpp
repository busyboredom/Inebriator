// Copyright 2019 Charlie Wilkin

#include "../include/screen.hpp"
#include <wiringPi.h>
#include <lcd.h>
#include <iostream>

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

int main() {
  Screen LCD;
  int dialed_ABV = 0;
  while (true) {
    dialed_ABV = POT.get_dialed();
    LCD.print(dialed_ABV);
    if (get_button()) {
      motors.Pour(dialed_ABV);
    }
  }
}

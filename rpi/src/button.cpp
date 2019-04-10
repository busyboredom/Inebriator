// Copyright 2019 Charlie Wilkin

#include "../include/button.hpp"
#include <wiringPi.h> 

Button::Button() {
  int pin = 0;
  wiringPiSetup();
  pinMode(pin INPUT);
}

bool Button::get_button() {
  return digitalRead(pin); 
}

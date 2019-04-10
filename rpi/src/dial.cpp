// Copyright 2019 Charlie Wilkin

#include "../include/dial.hpp"
#include <wiringPi.h>

Dial::Dial() {
  int pin = 0;
  wiringPiSetup();
  pinMode(pin, INPUT)
}

bool get_dialed() {
  //TODO: Use arduino as an ADC. RPi doesn't have analog read. 
  int position = anlogRead(pin);
  
}

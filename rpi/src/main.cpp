// Copyright 2019 Charlie Wilkin

#include "../include/screen.hpp"
#include "../include/button.hpp"
#include "../include/dial.hpp"
#include <iostream>

int main() {
  Screen LCD;
  Button pushbutton;
  Dial POT;
  int dialed_ABV = 0;
  while (true) {
    dialed_ABV = POT.get_dialed();
    LCD.print(dialed_ABV);
    if (pushbutton.get_button()) {
      Pour(dialed_ABV);
    };
  }
}

void Pour(int dialed_ABV) {

}

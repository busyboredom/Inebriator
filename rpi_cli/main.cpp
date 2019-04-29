#include <iostream>
#include <wiringPi.h>
#include <chrono>
#include <thread>

float ABV_to_sec(float ABV) {
  // Assume 40% ABV spirit, and an 8oz (227 mL) drink.
  float vol = (ABV / 40) * 227;
  float sec = vol * 0.0344 + 0.309;  // Experimentally determined from flow 
                                    // rate.
  return sec;
}


void pour(int ABV) {
  int spirit_pin = 21;  // GPIO 21
  int mixer_pin = 23;  // GPIO 23
  float total_pour_time = 8.11;  // Seconds.
  wiringPiSetup();
  pinMode(spirit_pin, OUTPUT);
  pinMode(mixer_pin, OUTPUT);

  std::cout << "Pouring a " << ABV << "\% ABV drink...\n";
  float spirit_msec = 1000 * ABV_to_sec(ABV);

  // Mixer pouring time is the remainder, plus the time it takes for the motor
  // to start:
  float mixer_msec = 1000 * total_pour_time - spirit_msec + 0.309;

  unsigned int ispirit_msec = (int) spirit_msec;
  unsigned int imixer_msec = (int) mixer_msec;

  
  digitalWrite(spirit_pin, HIGH);
  std::this_thread::sleep_for(std::chrono::milliseconds(ispirit_msec));
  digitalWrite(spirit_pin, LOW);

  digitalWrite(mixer_pin, HIGH);
  std::this_thread::sleep_for(std::chrono::milliseconds(imixer_msec));
  digitalWrite(mixer_pin, LOW);
  
};

int main() {
  float ABV = 0;
  char response = 'N';

  while (true) {
    std::cout << "\033[2J\033[1;1H";  // Clear terminal.
    std::cout << "Hello, I'm the Inebriator.\n";
    std::cout << "Please enter the desired ABV of your drink:\n";
    std::cout << "(Values between 0 and 10 are valid)\n";

    std::cin >> ABV;
    while (ABV > 10 || ABV < 0) {
      std::cout << "I'm sorry, that is not a valid \% ABV. Please try again:\n";
      std::cin >> ABV;
    };

    std::cout << "Should I pour a " << ABV <<"\% ABV drink?\n(Y/N)";
    std::cin >> response;
    while (response != 'Y' && response != 'N') {
      std::cout << "Please enter 'Y' or 'N'\n";
      std::cin >> response;
    };

    if (response == 'Y') {
      pour(ABV);
    } else {
      std::cout << "Cancelled\n";
    };

  };
}

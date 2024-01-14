#ifndef LEDControl_H
#define LEDControl_H
#include "DE1SoCfpga.h"
#include <iostream>

using std::cout;
using std::endl;

// Cyclone V FPGA device addresses
const unsigned int LEDR_BASE = 0x00000000; // Leds offset
const unsigned int SW_BASE = 0x00000040; // Switches offset
const unsigned int KEY_BASE = 0x00000050; // Push buttons offset

class LEDControl {

    DE1SoCfpga *board;
    unsigned int leds_regValue;
public:
  LEDControl(DE1SoCfpga *b) {
      board = b;
      leds_regValue = 0;
  }
  LEDControl() {
    board = new DE1SoCfpga;
    leds_regValue = 0;
  }
  ~LEDControl() {
      cout << "Closing LEDs, Switches, & Buttons..." << endl;
  }
  void Write1Led(int ledNum, int value);
	void WriteAllLeds(int value);
  int Read1Switch(int switchNum);
  int ReadAllSwitches();
  int PushButtonGet();
};


#endif
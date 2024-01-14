#include "LEDControl.h"


void LEDControl::Write1Led(int ledNum, int value){
  int newLED = ((board->RegisterRead(LEDR_BASE) & 0x3ff) & ~(1 << ledNum)) | (value << ledNum);
	WriteAllLeds(newLED);

}

void LEDControl::WriteAllLeds(int value){
		board->RegisterWrite(LEDR_BASE, value);
}
 
int LEDControl::Read1Switch(int switchNum) {
    return (ReadAllSwitches() >> switchNum) & 1;
}

int LEDControl::ReadAllSwitches() {
  return board->RegisterRead(SW_BASE) & 0x3ff;
}

int LEDControl::PushButtonGet()
	{
		int button = board->RegisterRead(KEY_BASE) & 0xf;
		if (button == 1)
		{
			return 0;
		}
		if (button == 2)
		{
			return 1;
		}
		if (button == 4)
		{
			return 2;
		}
		if (button == 8)
		{
			return 3;
		}
		if (button == 0)
		{
			return -1;
		}
		else
		{
			return 4;
		}
	}

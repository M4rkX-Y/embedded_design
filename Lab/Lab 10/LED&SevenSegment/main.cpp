#include "SevenSegment.h"
#include "LEDControl.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
  SevenSegment *display = new SevenSegment;
	LEDControl *control = new LEDControl;
	int base = control->ReadAllSwitches();
  cout << base;
	control->WriteAllLeds(base);
  display->Hex_WriteNumber(base);
	while (true)
	{
		if (control->PushButtonGet() == 0)
		{
			base++;
			control->WriteAllLeds(base);
      display->Hex_WriteNumber(base);
		}
		if (control->PushButtonGet() == 1)
		{
			base--;
			control->WriteAllLeds(base);
      display->Hex_WriteNumber(base);
		}
		if (control->PushButtonGet() == 2)
		{
			base = base >> 1;
			control->WriteAllLeds(base);
      display->Hex_WriteNumber(base);
		}
		if (control->PushButtonGet() == 3)
		{
			base = base << 1;
			control->WriteAllLeds(base);
      display->Hex_WriteNumber(base);
		}
		if (control->PushButtonGet() == 4)
		{
			base = control->ReadAllSwitches();
			control->WriteAllLeds(base);
      display->Hex_WriteNumber(base);
		}
    sleep(1);
	} 
    
    return 0;
}

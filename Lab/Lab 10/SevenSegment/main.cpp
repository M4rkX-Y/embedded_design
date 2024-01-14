#include "SevenSegment.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
    int count = -25;
    // Create a pointer object of the SevenSegment class
    SevenSegment *display = new SevenSegment;
    cout << "Program Starting...!" << endl;
    
    
    // Update the display every second
    while (count <= 25)
    {
        int value = count * count * count; // Value to display
        cout << "Count: " << count << ", Value = " << value << endl;
        display->Hex_WriteNumber(value); // display value
        sleep(1);                        // wait for 1 second
        count++;                         // increment count
    }
    cout << "Press any key to terminate..."; // wait before clearing the displays
    getchar();
    getchar();
    delete display; // delete class object
    cout << "Terminating...!" << endl;
    
    
    return 0;
}

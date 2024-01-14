#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// Physical base address of FPGA Devices
const unsigned int LW_BRIDGE_BASE = 0xFF200000; // Base offset

// Length of memory-mapped IO window
const unsigned int LW_BRIDGE_SPAN = 0x00005000; // Address map size

// Cyclone V FPGA device addresses
const unsigned int LEDR_BASE = 0x00000000; // Leds offset
const unsigned int SW_BASE = 0x00000040;   // Switches offset
const unsigned int KEY_BASE = 0x00000050;  // Push buttons offset

class DE1SoCfpga
{
	// private is the default permission label
	int fd;
	char *pBase;

public:
	DE1SoCfpga()
	{
		// Open /dev/mem to give access to physical addresses
		fd = open("/dev/mem", (O_RDWR | O_SYNC));
		if (fd == -1) //  check for errors in openning /dev/mem
		{
			cout << "ERROR: could not open /dev/mem..." << endl;
			exit(1);
		}

		// Get a mapping from physical addresses to virtual addresses
		char *pBase = (char *)mmap(NULL, LW_BRIDGE_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, LW_BRIDGE_BASE);
		if (pBase == MAP_FAILED) // check for errors
		{
			cout << "ERROR: mmap() failed..." << endl;
			close(fd); // close memory before exiting
			exit(1);   // Returns 1 to the operating system;
		}
	}
	~DE1SoCfpga()
	{
		if (munmap(pBase, LW_BRIDGE_SPAN) != 0)
		{
			cout << "ERROR: munmap() failed..." << endl;
			exit(1);
		}
		close(fd); // close memory
	}
	void RegisterWrite(unsigned int offset, int value)
	{
		*(volatile unsigned int *)(pBase + offset) = value;
		// volatile prevents the compiler from optimizing code
	}
	int RegisterRead(unsigned int offset)
	{
		return *(volatile unsigned int *)(pBase + offset);
	}
};

class LEDControl : public DE1SoCfpga
{
public:
	void WriteAllLeds(int value)
	{
		RegisterWrite(LEDR_BASE, value);
	}

	int Read1Switch(int switchNum)
	{
		return (ReadAllSwitches() >> switchNum) & 1;
	}

	int ReadAllSwitches()
	{
		return RegisterRead(SW_BASE) & 0x3ff;
	}

	int PushButtonGet()
	{
		int button = RegisterRead(KEY_BASE) & 0xf;
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
}

int
main()
{

	LEDControl control = new LEDControl;
	int base = control.ReadAllSwitches();
	control.WriteAllLeds(base);
	int tmp = control.PushButtonGet();
	while (true)
	{
		if (control.PushButtonGet() == 0)
		{
			base++;
			control.WriteAllLeds(base);
		}
		if (control.PushButtonGet() == 1)
		{
			base--;
			control.WriteAllLeds(base);
		}
		if (control.PushButtonGet() == 2)
		{
			base = base >> 1;
			control.WriteAllLeds(base);
		}
		if (control.PushButtonGet() == 3)
		{
			base = base << 1;
			control.WriteAllLeds(base);
		}
		if (control.PushButtonGet() == 4)
		{
			base = control.ReadAllSwitches();
			control.WriteAllLeds(base);
		}
	}
	return 0;
}

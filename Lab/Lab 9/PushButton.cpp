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

/**
 * Write a 4-byte value at the specified general-purpose I/O location.
 *
 * @param pBase		Base address returned by 'mmap'.
 * @parem offset	Offset where device is mapped.
 * @param value	Value to be written.
 */
void RegisterWrite(char *pBase, unsigned int reg_offset, int value)
{
	*(volatile unsigned int *)(pBase + reg_offset) = value;
	// volatile prevents the compiler from optimizing code
}

/**
 * Read a 4-byte value from the specified general-purpose I/O location.
 *
 * @param pBase		Base address returned by 'mmap'.
 * @param offset	Offset where device is mapped.
 * @return		Value read.
 */
int RegisterRead(char *pBase, unsigned int reg_offset)
{
	return *(volatile unsigned int *)(pBase + reg_offset);
}

/**
 * Initialize general-purpose I/O
 *  - Opens access to physical memory /dev/mem
 *  - Maps memory into virtual address space
 *
 * @param fd	File descriptor passed by reference, where the result
 *			of function 'open' will be stored.
 * @return	Address to virtual memory which is mapped to physical, or MAP_FAILED on error.
 */
char *Initialize(int *fd)
{
	// Open /dev/mem to give access to physical addresses
	*fd = open("/dev/mem", (O_RDWR | O_SYNC));
	if (*fd == -1) //  check for errors in openning /dev/mem
	{
		cout << "ERROR: could not open /dev/mem..." << endl;
		exit(1);
	}

	// Get a mapping from physical addresses to virtual addresses
	char *virtual_base = (char *)mmap(NULL, LW_BRIDGE_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, *fd, LW_BRIDGE_BASE);
	if (virtual_base == MAP_FAILED) // check for errors
	{
		cout << "ERROR: mmap() failed..." << endl;
		close(*fd); // close memory before exiting
		exit(1);	// Returns 1 to the operating system;
	}
	return virtual_base;
}

/**
 * Close general-purpose I/O.
 *
 * @param pBase	Virtual address where I/O was mapped.
 * @param fd	File descriptor previously returned by 'open'.
 */
void Finalize(char *pBase, int fd)
{
	if (munmap(pBase, LW_BRIDGE_SPAN) != 0)
	{
		cout << "ERROR: munmap() failed..." << endl;
		exit(1);
	}
	close(fd); // close memory
}

/** Reads all the switches and returns their value in a single integer.
*
* @param pBase Base address for general-purpose I/O
* @return
A value that represents the value of the switches
*/
int ReadAllSwitches(char *pBase)
{
	return RegisterRead(pBase, SW_BASE) & 0x3ff;
}

/** Set the state of the LEDs with the given value.
 *
 * @param pBase Base address for general-purpose I/O
 * @param value Value between 0 and 1023 written to the LEDs
 */
void WriteAllLeds(char *pBase, int value)
{
	RegisterWrite(pBase, LEDR_BASE, value);
}

int ControlLED(char *pBase)
{
	int sw = ReadAllSwitches(pBase);
	WriteAllLeds(pBase, sw);
	return sw;
}

/** Changes the state of an LED (ON or OFF)
* @param pBase Base address of I/O
* @param ledNum LED number (0 to 9)
* @param state
State to change to (ON or OFF)
*/
void Write1Led(char *pBase, int ledNum, int state)
{
	int newLED = ((RegisterRead(pBase, LEDR_BASE) & 0x3ff) & ~(1 << ledNum)) | (state << ledNum);
	WriteAllLeds(pBase, newLED);
}

/** Reads the value of a switch
* @param pBase
Base address of I/O
* @param switchNum Switch number (0 to 9)
* @return Switch value read
*/
int Read1Switch(char *pBase, int switchNum)
{

	return (ReadAllSwitches(pBase) >> switchNum) & 1;
}

int PushButtonGet(char *pBase)
{
	int button = RegisterRead(pBase, KEY_BASE) & 0xf;
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

int main()
{
	// Initialize
	int fd;
	char *pBase = Initialize(&fd);

	// ************** Put your code here **********************
	int base = ControlLED(pBase);
	int tmp = PushButtonGet(pBase);
	while (true)
	{
		int iter = PushButtonGet(pBase);
		if (tmp != iter)
		{
			if (iter == 0)
			{
				base++;
				WriteAllLeds(pBase, base);
			}
			if (iter == 1)
			{
				base--;
				WriteAllLeds(pBase, base);
			}
			if (iter == 2)
			{
				base = base >> 1;
				WriteAllLeds(pBase, base);
			}
			if (iter == 3)
			{
				base = base << 1;
				WriteAllLeds(pBase, base);
			}
			if (iter == 4)
			{
				base = ControlLED(pBase);
			}
			tmp = iter;
		}
	}

	// Done
	Finalize(pBase, fd);
}

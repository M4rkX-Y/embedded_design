#ifndef DE1SoCfpga_H
#define DE1SoCfpga_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>

using std::cout;
using std::endl;


// Physical base address of FPGA Devices
const unsigned int LW_BRIDGE_BASE = 0xFF200000; // Base offset

// Length of memory-mapped IO window
const unsigned int LW_BRIDGE_SPAN = 0x00005000; // Address map size

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
        pBase = (char *)mmap(NULL, LW_BRIDGE_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, fd, LW_BRIDGE_BASE);
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
    void RegisterWrite(unsigned int offset, int value);
    int RegisterRead(unsigned int offset);
};

#endif 

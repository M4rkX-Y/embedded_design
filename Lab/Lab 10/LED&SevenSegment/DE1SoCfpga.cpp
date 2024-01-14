#include "DE1SoCfpga.h"



void DE1SoCfpga::RegisterWrite(unsigned int offset, int value)
{
    *(volatile unsigned int *)(pBase + offset) = value;
    // volatile prevents the compiler from optimizing code
}
int DE1SoCfpga::RegisterRead(unsigned int offset)
{
    return *(volatile unsigned int *)(pBase + offset);
}
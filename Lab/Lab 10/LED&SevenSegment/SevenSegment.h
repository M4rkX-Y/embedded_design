#ifndef SevenSegment_H
#define SevenSegment_H
#include "DE1SoCfpga.h"


const unsigned int bit_values[16] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

// Cyclone V FPGA device addresses
const unsigned int SS_REG1 = 0x00000020;
const unsigned int SS_REG2 = 0x00000030;

class SevenSegment
{
    DE1SoCfpga *board;
    unsigned int dataReg1;
    unsigned int dataReg2;

public:
    SevenSegment(DE1SoCfpga *b)
    {
	      board = b;
        dataReg1 = (bit_values[0] << 7) | bit_values[0] << 7 | bit_values[0];
        dataReg2 = (bit_values[0] << 7) | bit_values[0];
        board->RegisterWrite(SS_REG1, dataReg1);
        board->RegisterWrite(SS_REG2, dataReg2);
    }
    SevenSegment() {
	      board = new DE1SoCfpga;
	      dataReg1 = (bit_values[0] << 7) | bit_values[0] << 7 | bit_values[0];
        dataReg2 = (bit_values[0] << 7) | bit_values[0];
        board->RegisterWrite(SS_REG1, dataReg1);
        board->RegisterWrite(SS_REG2, dataReg2);
    }
    ~SevenSegment()
    {
        Hex_ClearAll();
    }
    void Hex_ClearAll();
    void Hex_ClearSpecific(int index);
    void Hex_WriteSpecific(int display_id, int value);
    void Hex_WriteNumber(int number);
};

#endif 

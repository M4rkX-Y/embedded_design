#include "SevenSegment.h"
#include <iostream>

using std::cout;
using std::endl;

void SevenSegment::Hex_ClearAll()
{
    dataReg1 = 0;
    dataReg2 = 0;
    board->RegisterWrite(SS_REG1, dataReg1);
    board->RegisterWrite(SS_REG2, dataReg2);
}

void SevenSegment::Hex_ClearSpecific(int index)
{
    if (index < 4)
    {
        dataReg1 = dataReg1 | ~(0xff << index * 4);
    }
    else
    {
        dataReg2 = dataReg1 | ~(0xff << (index - 3) * 4);
    }
    board->RegisterWrite(SS_REG1, dataReg1);
    board->RegisterWrite(SS_REG2, dataReg2);
}

void SevenSegment::Hex_WriteSpecific(int display_id, int value)
{
    if (display_id < 4)
    {
        dataReg1 = dataReg1 | (bit_values[value] << display_id * 8  );
    }
    else
    {
        dataReg2 = dataReg2 | (bit_values[value] << (display_id - 4)*8);
    }
    board->RegisterWrite(SS_REG1, dataReg1);
    board->RegisterWrite(SS_REG2, dataReg2);
}

void SevenSegment::Hex_WriteNumber(int number)
{
    dataReg1 = 0;
    dataReg2 = 0;
    if (number < 0) {
      number = -number;
    }
    for (int i = 0; i < 6; i++)
    {
        Hex_WriteSpecific(i, number % 16);
        number = number / 16;
    }
}

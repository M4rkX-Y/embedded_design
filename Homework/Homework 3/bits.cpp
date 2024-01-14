#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void printBinary(int value);
int getBit(int data, int index);
void printUpdatedValue(int dataValue, int index, int state);

int main()
{
    // define the two integers
    int i1, i2;
    // check if the cin is valid, if it is not, give a error message and clear/discard the last few cin inputs.
    cout << "Input the first integer: ";
    while (!(cin >> i1))
    {
        cout << "Incorrect data type! Please try again: ";
        cin.clear();
        cin.ignore(10, '\n');
    }
    // do the same thing for second integer
    cout << "Input the second integer: ";
    while (!(cin >> i2))
    {
        cout << "Incorrect data type! Please try again: ";
        cin.clear();
        cin.ignore(10, '\n');
    }

    // call the printBinary function to print the binary format of the two integers.
    printBinary(i1);
    printBinary(i2);

    // checks if the two numbers are divisible by 4 by checking if the last two bits of its binary form is 0
    cout << i1;
    if (!getBit(i1, 0) && !getBit(i1, 1))
    {
        cout << " is ";
    }
    else
    {
        cout << " is not ";
    }
    // check if the number is positive or negative based on the first bit (two's compliment)
    cout << "divisible by 4 and is ";
    if (getBit(i1, (sizeof(int) * 8 - 1)))
    {
        cout << "negative." << endl;
    }
    else
    {
        cout << "positive." << endl;
    }

    // basically do the same thing for integer 2 as well
    cout << i2;
    if (!getBit(i2, 0) && !getBit(i2, 1))
    {
        cout << " is ";
    }
    else
    {
        cout << " is not ";
    }
    cout << "divisible by 4 and is ";
    if (getBit(i2, (sizeof(int) * 8 - 1)))
    {
        cout << "negative." << endl;
    }
    else
    {
        cout << "positive." << endl;
    }

    // call the printUpdatedValue function on the first number and change the last bit of the original integer to 1
    printUpdatedValue(i1, 0, 1);

    return 0;
}

void printBinary(int value)
{
    // This function takes in a integer and print the binary two's complement by looping through the bits of integer and bit operator
    cout << "The integer " << value << " in binary is: ";
    // looping through the integer bits the sizeof function gets the size of int in bytes
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--)
    {
        // shift the value to the first bit location and "and" with 1 to output if the bit is 0 or 1
        cout << ((value >> i) & 1);
    }
    cout << endl;
}

int getBit(int data, int index)
{
    // return the bit from given index
    return (data >> index) & 1;
}

void printUpdatedValue(int dataValue, int index, int state)
{
    // define the new integer
    int new_dataValue;
    // print the old integer
    printBinary(dataValue);
    // change the given index to the specific state
    new_dataValue = (dataValue & ~(1 << index)) | (state << index);
    printBinary(new_dataValue);
}

#include "CompMain.h"
#include "Comparator.h"
#include "Comparator.cpp"
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    // Create 1st object
    int int1 = 4;
    float f1 = 10.4;
    double d1 = 20.1;
    Evaluator object1(int1, f1, d1);

    // Create 2nd object
    int int2 = 7;
    float f2 = 0.0;
    double d2 = 3.5;
    Evaluator object2(int2, f2, d2);

    // Check operation on integer data type
    cout << "\nPrinting INTEGER operations..." << endl;
    object1.intOperations(object2);

    // Check operation on float data type
    cout << "\nPrinting FLOAT operations..." << endl;
    object1.floatOperations(object2);

    // Check operation on double data type
    cout << "\nPrinting DOUBLE operations..." << endl;
    object1.doubleOperations(object2);
} // end main
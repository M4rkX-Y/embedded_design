#include "CompMain.h"
#include "Comparator.h"
#include "Comparator.cpp"
#include <iostream>

using std::boolalpha;
using std::cout;
using std::endl;

template <class T2>
void Evaluator::printOperations(T2 *obj)
{
    // print the Operations and thier corresponding answers
    cout << boolalpha;
    cout << obj->getValue1() << " - " << obj->getValue2() << " = " << obj->getDiff() << endl;
    cout << obj->getValue1() << " || " << obj->getValue2() << " = " << obj->getLogicalOR() << endl;
    cout << obj->getValue1() << " < " << obj->getValue2() << " = " << obj->isLess() << endl;
}

void Evaluator::intOperations(Evaluator obj)
{
    // create a comparator object and print the results using printOperations function
    Comparator<int> *compint = new Comparator<int>(intData, obj.intData);
    printOperations(compint);
}
void Evaluator::floatOperations(Evaluator obj)
{
    // create a comparator object and print the results using printOperations function
    Comparator<float> *compfloat = new Comparator<float>(floatData, obj.floatData);
    printOperations(compfloat);
}
void Evaluator::doubleOperations(Evaluator obj)
{
    // create a comparator object and print the results using printOperations function
    Comparator<double> *comdouble = new Comparator<double>(doubleData, obj.doubleData);
    printOperations(comdouble);
}

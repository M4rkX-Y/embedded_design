#include "BarGraph.h"
#include <iostream>

using std::cout;
using std::endl;

void BarGraph::setSize(int sz)
{
    size = sz;
}

void BarGraph::setSymbol(char sym)
{
    symbol = sym;
}

void BarGraph::displayAxis(char sym)
{
    cout << "2  10   20   30   40   50   60   70   80   90   100%" << endl;
    cout << "|  |    |    |    |    |    |    |    |    |    |   " << endl;
    for (int i = 0; i < 49; i++)
    {
        cout << sym;
    }
    cout << endl;
}

void BarGraph::getBar()
{
    for (int i = 0; i < size; i++)
    {
        cout << symbol;
    }
    cout << endl;
}
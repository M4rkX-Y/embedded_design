#ifndef COMPARATOR_H
#define COMPARATOR_H

template <class T>
class Comparator
{
    T value1;
    T value2;

public:
    Comparator()
    {
        value1 = 0;
        value2 = 0;
    }
    Comparator(T v1, T v2)
    {
        value1 = v1;
        value2 = v2;
    }
    T getValue1();
    T getValue2();
    T getDiff();
    int getLogicalOR();
    bool isLess();
};

#endif
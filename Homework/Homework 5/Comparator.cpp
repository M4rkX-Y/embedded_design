#include "Comparator.h"

template <class T>
T Comparator<T>::getValue1()
{
    return value1;
}

template <class T>
T Comparator<T>::getValue2()
{
    return value2;
}

template <class T>
T Comparator<T>::getDiff()
{
    return value1 - value2;
}

template <class T>
int Comparator<T>::getLogicalOR()
{
    return value1 || value2;
}

template <class T>
bool Comparator<T>::isLess()
{
    return value1 < value2;
}

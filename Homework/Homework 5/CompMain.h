#ifndef COMPMAIN_H
#define COMPMAIN_H

class Evaluator
{
private:
    int intData;
    float floatData;
    double doubleData;
    template <class T2>
    void printOperations(T2 *obj);

public:
    Evaluator()
    {
        // initialize the attributes with 0
        intData = 0;
        floatData = 0;
        doubleData = 0;
    }
    Evaluator(int i, float f, double d)
    {
        // initialize the attributes with given numbers
        intData = i;
        floatData = f;
        doubleData = d;
    }
    void intOperations(Evaluator obj);
    void floatOperations(Evaluator obj);
    void doubleOperations(Evaluator obj);
};

#endif
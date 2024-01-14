#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

Point *init(int x, int y)
{
    Point *result = new Point();
    result->x = x;
    result->y = y;
    return result;
}

int main()
{
    Point *p1 = init(10, 20);
    cout << p1->x;
    cout << p1->y;
}
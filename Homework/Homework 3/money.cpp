#include <iostream>

using namespace std;

struct Money
{
    int value;
    string name;
    float exchange_rate;
};

bool worthMore(Money m1, Money m2)
{
    return m1.value * m1.exchange_rate > m2.value * m2.exchange_rate;
}

int main()
{
    Money m1, m2;
    m1.value = 10;
    m1.exchange_rate = 6;
    m2.value = 10;
    m2.exchange_rate = 5;
    cout << worthMore(m1, m2);
}
#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::sort;
using std::vector;

bool comparator(int a, int b)
{
    return abs(a) < abs(b);
}

template <class T>
void vecToList(vector<T> *v, list<T> *l)
{
    vector<T> tmp = *v;
    for (int i = 0; i < v->size(); i++)
    {
        l->push_back(tmp[i]);
    }
}

template <class Iter, class Seq>
void srcToSeq(Iter src_begin, Iter src_end, Seq *dest)
{
    while (src_begin != src_end)
    {
        dest->push_back(*src_begin);
        src_begin++;
    }
}

template <class T>
void printV(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <class T>
void printL(list<T> l)
{
    for (T i : l)
    {
        cout << i << " ";
    }
    cout << endl;
}
template <class Iter>
void printReverse(Iter b, Iter e)
{
    while (e != b)
    {
        e--;
        cout << *e << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Input a the length of the vector n: ";
    cin >> n;
    srand(time(NULL));
    vector<int> v1(n);

    for (int i = 0; i < n; i++)
    {
        v1[i] = rand() % 100 - 50;
    }
    list<int> l1;
    vecToList<int>(&v1, &l1);
    cout << "The random vector is: ";
    printV(v1);
    cout << "The random list is: ";
    printL(l1);
    sort(v1.begin(), v1.end(), comparator);
    cout << "The sorted vector is: ";
    printV(v1);

    vector<int> v2 = {1, 2, 3, 4};
    list<int> l2 = {5, 6, 7, 8};
    cout << endl
         << "The new vector is: ";
    printV(v2);
    cout << "The new list is: ";
    printL(l2);
    srcToSeq(l2.begin(), l2.end(), &v2);
    cout << "The modified vector is: ";
    printV(v2);
    v2 = {1, 2, 3, 4};
    l2 = {5, 6, 7, 8};
    srcToSeq(v2.begin(), v2.end(), &l2);
    cout << "The modified list is: ";
    printL(l2);

    vector<int> v3 = {10, 20, 30, 40};
    list<int> l3 = {50, 60, 70, 80};
    cout << endl
         << "The new vector is: ";
    printV(v3);
    cout << "The new list is: ";
    printL(l3);
    cout << "The reverse vector is: ";
    printReverse(v3.begin(), v3.end());
    cout << "The reverse list is: ";
    printReverse(l3.begin(), l3.end());
    return 0;
}


#include <iostream>
#include <cstdlib>

// input used function from std
using std::cout;
using std::endl;
using std::swap;

// defined the size of the array
int size = 10;

// declare the functions
void PrintArray(int v[], int size);
void RandomArray(int v[], int size);
void SortArray(int v[], int size);

int main()
{
        // initialize the array with defined size, put random numbers into the list, print the original list and sort it with selection sort, print the sorted list at last.

        int array[size];
        RandomArray(array, size);
        cout << "Original Array: ";
        PrintArray(array, 10);
        SortArray(array, 10);
        cout << "Sorted Array: ";
        PrintArray(array, 10);
        return 0;
}

void RandomArray(int v[], int size)
{
        // loop through the empty list and put random number into the specified index

        for (int i = 0; i < size; i++)
        {
                v[i] = rand() % 100;
        }
}

void PrintArray(int v[], int size)
{
        // loop through the list and print the number
        for (int i = 0; i < size; i++)
        {
                cout << v[i] << ", ";
        }
        cout << endl;
}

void SortArray(int v[], int size)
{
        // we sort list by first loop through each inidividual index
        for (int i = 0; i < size - 1; i++)
        {
                // we assume the first number is the minimum
                int Min = i;
                // loop through the other numbers after the first number
                for (int j = i + 1; j < size; j++)
                {
                        // compare each number with the first number and see if it is smaller, if it is smaller, the Min index become the index of the new small numebr,
                        if (v[j] < v[Min])
                        {
                                Min = j;
                        }
                }
                // swap the smallest number of the list so far with the first position.
                if (Min != i)
                {
                        swap(v[i], v[Min]);
                }
        }
}

#include <iostream>
#include <cstdlib>

// input used function from std
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::swap;

// defined the size of the array
int size = 10;

// declare the functions
void PrintArray(string v[], int size);
void InputArray(string v[], int size);
void SortArray(string v[], int size);
bool StringComparator(string a, string b);

int main()
{
    // initialize the array with defined size, ask user to input strings into the list, print the original list and sort it with selection sort, print the sorted list at last.

    string array[size];
    InputArray(array, size);
    cout << "Original Array: ";
    PrintArray(array, 10);
    SortArray(array, 10);
    cout << "Sorted Array: ";
    PrintArray(array, 10);
    return 0;
}

void InputArray(string v[], int size)
{
    // loop through the empty list and ask user to input string into the specified index
    for (int i = 0; i < size; i++)
    {
        string input;
        cout << "Input string " << i + 1 << ": ";
        cin >> input;
        v[i] = input;
    }
}

void PrintArray(string v[], int size)
{
    // loop through the list and print the string
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
}

void SortArray(string v[], int size)
{
    // we sort list by first loop through each inidividual index
    for (int i = 0; i < size - 1; i++)
    {
        // we assume the first string is the minimum
        int Min = i;
        // loop through the other strings after the first string
        for (int j = i + 1; j < size; j++)
        {
            // compare each string with the first string and see if it is smaller, if it is smaller, the Min index become the index of the new small numebr. In this case we define a new comparator to check which string is "smaller"
            if (StringComparator(v[j], v[Min]))
            {
                Min = j;
            }
        }
        // swap the smallest string of the list so far with the first position.
        if (Min != i)
        {
            swap(v[i], v[Min]);
        }
    }
}

bool StringComparator(string a, string b)
{
    // the string comparator frst check the length of the string and output true if the first string is shorter.
    int a_length = a.length();
    int b_length = b.length();
    if (a_length < b_length)
    {
        // if the first strings is shorter than the second string, loop through each characters in the first string and compare each one of them entile one is smaller than the other in the alphabatical order.
        for (int i = 0; i < a_length; i++)
        {
            // tolower() turns the character to their lower case to fix the ascii problem.
            char a_char = tolower(a[i]);
            char b_char = tolower(b[i]);
            if (a_char < b_char)
            {
                return true;
            }
            if (a_char > b_char)
            {
                return false;
            }
        }
        // the second string contains the first string, first string is smaller than the second string
        return true;
    }
    if (a_length >= b_length)
    {
        // if the first strings is longer than the second string, loop through each characters in the second string and compare each one of them entile one is smaller than the other in the alphabatical order.
        for (int i = 0; i < b_length; i++)
        {
            // tolower() turns the character to their lower case to fix the ascii problem.
            char a_char = tolower(a[i]);
            char b_char = tolower(b[i]);
            if (a_char < b_char)
            {
                return true;
            }
            if (a_char > b_char)
            {
                return false;
            }
        }
        // the first string contains the second string, first string is larger than the second string
        return false;
    }
}

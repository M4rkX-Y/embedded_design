#include <iostream>
void Print_menu();
void Initialize();
void Finalize();
void Grow();
void Shrink();
void AddElement();
void PrintVector();
void RemoveElement();
void InsertElement();

double *v;
int size = 0;
int capacity = 2;

int main()
{
    Initialize();
    Print_menu();
    int user_input;
    while (true)
    {
        std::cin >> user_input;
        switch (user_input)
        {
        case 1:
            std::cout << "You selected 'List vector's content'" << std::endl;
            PrintVector();
            Print_menu();
            break;
        case 2:
            std::cout << "You selected 'Append element at the end'" << std::endl;
            AddElement();
            Print_menu();
            break;
        case 3:
            std::cout << "You selected 'Remove last element'" << std::endl;
            RemoveElement();
            Print_menu();
            break;
        case 4:
            std::cout << "You selected 'Insert one element'" << std::endl;
            InsertElement();
            Print_menu();
            break;
        case 5:
            std::cout << "You selected 'Exit'" << std::endl;
            Finalize();
            return (0);
        default:
            std::cout << "Please input an integer between 1 and 5" << std::endl;
            Print_menu();
        }
    }
}
void Print_menu()
{
    std::cout << "\nMain menu:\n"
                 "1. List vector's contents\n"
                 "2. Append element at the end\n"
                 "3. Remove last element\n"
                 "4. Insert one element\n"
                 "5. Exit\n"
                 "Select an option: ";
}

void Initialize()
{
    v = (double *)malloc(capacity * sizeof(double));
}

void Finalize()
{
    free(v);
}

void Grow()
{
    std::cout << "Previous capacity: " << capacity << " elements" << std::endl;
    int new_capacity = capacity * 2;
    std::cout << "New capacity: " << new_capacity << " elements" << std::endl;
    double *nv = (double *)malloc(new_capacity * sizeof(double));
    for (int i = 0; i < capacity; i++)
    {
        nv[i] = v[i];
    }
    free(v);
    v = nv;
    capacity = new_capacity;
}

void AddElement()
{
    double input;
    std::cout << "Enter the new element: ";
    std::cin >> input;
    if (capacity == size)
    {
        Grow();
    }
    v[size] = input;
    size++;
}

void PrintVector()
{

    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            std::cout << v[i] << ", ";
        }
        else
        {
            std::cout << v[i];
        }
    }
    std::cout << std::endl;
}

void RemoveElement()
{
    if (size == 0)
    {
        std::cout << "Can't remove element on an empty array" << std::endl;
    }
    else
    {
        if (size <= capacity * 0.3)
        {
            Shrink();
        }
        size--;
    }
}

void InsertElement()
{
    int index;
    int input;
    std::cout << "Enter the index of new element: ";
    std::cin >> index;
    std::cout << "Enter the new element: ";
    std::cin >> input;
    if (capacity == size)
    {
        Grow();
    }
    if (index > size)
    {
        std::cout << "Invalid input";
        return;
    }
    int new_capacity = size - (index - 1);
    double *nv = (double *)malloc(new_capacity * sizeof(double));
    for (int i = 0; i < new_capacity; i++)
    {
        nv[i] = v[index + i];
    }
    v[index] = input;
    for (int i = 0; i < new_capacity; i++)
    {
        v[index + i + 1] = nv[i];
    }
    free(nv);
    size++;
}

void Shrink()
{
    std::cout << "Previous capacity: " << capacity << " elements" << std::endl;
    int new_capacity = capacity / 2;
    std::cout << "New capacity: " << new_capacity << " elements" << std::endl;
    double *nv = (double *)malloc(new_capacity * sizeof(double));
    for (int i = 0; i < new_capacity; i++)
    {
        nv[i] = v[i];
    }
    free(v);
    v = nv;
    capacity = new_capacity;
}
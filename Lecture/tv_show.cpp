#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

void Print_menu();
void AddTV();
void PrintTV();
void EditTV();

struct TV_Program
{
    string programName;
    char weekday; // M, T, W, R, F
    int minutes;  // Running time
};
vector<TV_Program> tv_array(0);

int main()
{

    int user_input;
    while (true)
    {
        Print_menu();
        cin >> user_input;
        switch (user_input)
        {
        case 1:
            AddTV();
            break;
        case 2:
            PrintTV();
            break;
        case 3:
            EditTV();
            break;
        case 4:
            return 0;
        }
    }
}

void Print_menu()
{
    cout << "\nMain menu:\n"
            "1. Add a new TV_Program to the vector\n"
            "2. Print the current vector state\n"
            "3. Edit an existing TV show's info\n"
            "4. Exit\n"
            "Select an option: ";
}

void AddTV()
{
    string pname;
    char wday;
    int min;
    cout << "Input the program name: ";
    cin >> pname;
    cout << "Input the weekday (M, T, W, R, F): ";
    cin >> wday;
    cout << "Input the minute: ";
    cin >> min;
    TV_Program np = {pname, wday, min};
    tv_array.push_back(np);
}

void PrintTV()
{
    for (int i = 0; i < tv_array.size(); i++)
    {
        cout << "TV Program " << i + 1 << ":" << endl;
        cout << "Program name: " << tv_array[i].programName << endl;
        cout << "Program weekday: " << tv_array[i].weekday << endl;
        cout << "Program minutes: " << tv_array[i].minutes << endl;
    }
}

void EditTV()
{
    int index;
    string pname;
    char wday;
    int min;
    cout << "Input the index: ";
    cin >> index;
    cout << "Input the program name: ";
    cin >> pname;
    cout << "Input the weekday (M, T, W, R, F): ";
    cin >> wday;
    cout << "Input the minute: ";
    cin >> min;
    TV_Program np = {pname, wday, min};
    tv_array.insert(tv_array.begin() + index, np);
}
#include <iostream>
#include <string>
using std::cout;
using std::string;
struct Person
{
    string name;
    int age;
};

void PrintPerson(Person *person)
{
    cout << person->name << " is " << person->age << " years old\n";
}

int main()
{
    PrintPerson(nullptr);
}
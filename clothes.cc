#include <iostream>
#include <string>
#include "clothes.h"
using namespace std;

double Clothes::cost()
{
    return 0;
}

void Clothes::input(istream &ins)
{
    if (&ins == &cin)
    {
        cout << "Enter product name: ";
        ins >> name;
        cout << "Enter color: ";
        ins >> color;
    }
    else
    {
        ins >> name;
        ins >> price;
        ins >> color;
    }
}

void Clothes::output(ostream &outs)
{
    if (&outs == &cout)
    {
        outs << "Department: " << department << endl;
        outs << "Name: " << name << endl;
        outs << "Cost: $" << cost() << endl;
        outs << "Color: " << color << endl;
    }
    else
    {
        outs << department << endl;
        outs << name << endl;
        outs << cost() << endl;
        outs << color << endl;
    }
}

void Clothes::set_name(string n)
{
    name = n;
}

void Clothes::set_color(std::string c)
{
    color = c;
}
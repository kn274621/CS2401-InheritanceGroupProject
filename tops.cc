#include <iostream>
#include <string>
#include "tops.h"

using namespace std;

Tops::Tops(char s, string sle, string d, string n, double p, string c)
{
    // set attributes for tops (child class)
    size = s;
    sleeves = sle;

    // set attributes for clothes (parent class)
    department = d;
    name = n;
    price = p;
    color = c;
}

double Tops::cost()
{
    price = 30;
    double total;
    double rate;

    if (sleeves == "long")
    {
        rate = 7.5;
    }
    else if (sleeves == "short")
    {
        rate = 5;
    }
    else
    {
        rate = 0;
    }

    total = price + rate;

    return total;
}

void Tops::input(istream &ins)
{
    Clothes::input(ins);
    department = "Tops";
    if (&ins == &cin)
    {

        cout << "Enter the size (s/m/l): ";
        ins >> size;
        cout << "Enter the sleeve type (long/short/none): ";
        ins >> sleeves;
    }
    else
    {
        ins >> size;
        ins >> sleeves;
    }
}

void Tops::output(ostream &outs)
{
    if (&outs == &cout)
    {
        Clothes::output(outs);
        outs << "Size: " << size << endl;
        outs << "Sleeves: " << sleeves << endl;
    }
    else
    {
        Clothes::output(outs);
        outs << size << endl;
        outs << sleeves << endl;
    }
}

void Tops::set_size(char s)
{
    size = s;
}

void Tops::set_sleeves(string s)
{
    sleeves = s;
}
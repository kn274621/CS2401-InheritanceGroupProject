#include "bottoms.h"
using namespace std;

Bottoms::Bottoms(double w, bool s, string d, string n, double p, string c)
{
    // set attributes for bottoms (child class)
    waist = w;
    is_shorts = s;

    // set attributes for clothes (parent class)
    department = d;
    name = n;
    price = p; // default price for bottoms is 20
    color = c;
}

void Bottoms::input(std::istream &ins)
{
    Clothes::input(ins);
    department = "Bottoms";

    char length;

    if (&ins == &cin)
    {
        cout << "Are the pants shorts? (y/n): ";
        ins >> length;
        length = tolower(length);
        if (length == 'y')
        {
            is_shorts = true;
        }
        else
        {
            is_shorts = false;
        }

        cout << "Enter waist size: ";
        ins >> waist;
    }
    else
    {
        ins >> length;
        if (length == 'y')
        {
            is_shorts = true;
        }
        else
        {
            is_shorts = false;
        }
        ins >> waist;
    }
}

void Bottoms::output(std::ostream &outs)
{
    Clothes::output(outs);

    if (&outs == &cout)
    {
        if (is_shorts)
        {
            outs << "Shorts, ";
        }
        else
        {
            outs << "Pants, ";
        }
        outs << "waist size: " << waist << endl;
    }
    else
    {
        if (is_shorts) {
            outs << 'y' << endl;
        }
        else {
        outs << 'n' << endl;
        }
        outs << waist << endl;
    }
}

double Bottoms::cost()
{
    price = 20;
    if (!is_shorts)
    {
        price += 5;
    }

    return price;
}

void Bottoms::set_waist(double w)
{
    waist = w;
}

void Bottoms::set_shorts(bool s)
{
    is_shorts = s;
}

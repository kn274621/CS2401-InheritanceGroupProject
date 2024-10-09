#include <iostream>
#include "shoes.h"

using namespace std;

Shoes::Shoes(double z, std::string y, std::string h, string d, std::string n, std::string c, double p)
{
    // set attributes for shoes (child class)
    size = z;
    style = y;
    height = h;
    
    // set attributes for clothes (parent class)
    department = d;
    name = n;
    color = c;
    price = p; // base price for shoes is 70
}

double Shoes::cost()
{
    price = 70;
    // adjust price based on shoe style
    if (style == "sneaker")
    {
        price += 5;
    }
    if (style == "boot")
    {
        price += 10;
    }
    // adjust price based on shoe height
    if (height == "calf")
    {
        price += 5;
    }
    if (height == "knee")
    {
        price += 10;
    }
    return price;
}

void Shoes::input(istream &ins)
{
    Clothes::input(ins);
    department = "Shoes";
    if (&ins == &cin)
    {
        cout << "Enter size: ";
        ins >> size;
        cout << "Enter style (sneaker/sandal/boot): ";
        ins >> style;
        cout << "Enter height (ankle/calf/knee): ";
        ins >> height;
    }
    else
    {
        ins >> size;
        ins >> style;
        ins >> height;
    }
}

void Shoes::output(ostream &outs)
{
    Clothes::output(outs);
    if (&outs == &cout)
    {
        outs << "Size: " << size << endl;
        outs << "Style: " << style << endl;
        outs << "Height: " << height << endl;
    }
    else
    {
        outs << size << endl;
        outs << style << endl;
        outs << height << endl;
    }
}

void Shoes::set_size(double z)
{
    size = z;
}
void Shoes::set_style(std::string y)
{
    style = y;
}
void Shoes::set_height(std::string h)
{
    height = h;
}
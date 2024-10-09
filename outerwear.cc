#include "outerwear.h"

using namespace std;

Outerwear::Outerwear(bool h, bool z, char s, string d, string n, double p, string c)
{
    // set attributes for outerwear (child class)
    hood = h;
    zipper = z;
    size = s;

    // set attributes for clothes (parent class)
    department = d;
    name = n;
    price = p;
    color = c;
}

double Outerwear::cost()
{
    price = 50;
    if (hood)
    {
        price += 10;
    }
    if (zipper)
    {
        price += 5;
    }

    return price;
}

void Outerwear::input(std::istream &ins)
{
    Clothes::input(ins);
    department = "Outerwear";
    if (&ins == &cin)
    {
        char mychar;
        cout << "Has hood or not (y/n): ";
        ins >> mychar;
        mychar = tolower(mychar);
        if (mychar == 'y')
        {
            hood = true;
        }
        else
            hood = false;

        cout << "Has zipper or not (y/n): ";
        ins >> mychar;
        mychar = tolower(mychar);
        if (mychar == 'y')
        {
            zipper = true;
        }
        else
            zipper = false;

        cout << "Select size (s/m/l): ";
        ins >> size;
        size = tolower(size);
    }
    else
    {
        char mychar;
        ins>>mychar;
        if(mychar=='y'){
            hood=true;
        }else{
            hood=false;
        }

        ins>>mychar;
        if(mychar=='y'){
            zipper=true;
        }else{
            zipper=false;
        }

        ins>>size;
    }
}

void Outerwear::output(std::ostream &outs)
{
    Clothes::output(outs);
    if (&outs == &cout)
    {
        if (hood)
            outs << "Has hood: yes" << endl;
        else if (!hood)
            outs << "Has hood: no" << endl;
        if (zipper)
            outs << "Has zipper: yes" << endl;
        else if (!zipper)
            outs << "Has zipper: no" << endl;
        outs << "Size: " << size << endl;
    }
    else
    {
        if(hood){
            outs << 'y' << endl;
        }else{
            outs<<'n'<<endl;
        }
        if(zipper){
            outs << 'y' << endl;
        }else{
            outs<<'n'<<endl;
        }
        outs << size << endl;
    }
}

void Outerwear::set_hood(bool h)
{
    hood = h;
}

void Outerwear::set_zipper(bool z)
{
    zipper = z;
}

void Outerwear::set_size(char s)
{
    size = s;
}
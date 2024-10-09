#include "order.h"

using namespace std;

Order::Order(string n, double t, std::list<Clothes *> ptr)
{
    order_name = n;
    total = t;
    items = ptr;
}

void Order::input(istream &ins, string dep)
{
    if (&cin == &ins)
    {
        if (order_name == "")
        {
            cout << "Enter a name for the order: ";
            ins >> order_name;
        }

        if (dep == "Tops")
        {
            Tops tmp;
            tmp.input(ins);
            Tops *ptr = new Tops(tmp);
            items.push_back(ptr);
            total += tmp.cost();
        }
        else if (dep == "Bottoms")
        {
            Bottoms tmp;
            tmp.input(ins);
            Bottoms *ptr = new Bottoms(tmp);
            items.push_back(ptr);
            total += tmp.cost();
        }
        else if (dep == "Shoes")
        {
            Shoes tmp;
            tmp.input(ins);
            Shoes *ptr = new Shoes(tmp);
            items.push_back(ptr);
            total += tmp.cost();
        }
        else if (dep == "Outerwear")
        {
            Outerwear tmp;
            tmp.input(ins);
            Outerwear *ptr = new Outerwear(tmp);
            items.push_back(ptr);
            total += tmp.cost();
        }
        else
        {
            std::cout << "BAD DEPARTMENT" << std::endl;
        }
    }
    else
    {
        string department;

        while (!ins.eof() && ins.peek() != '*')
        {
            if (order_name == "")
            {
                ins >> order_name;
            }

            ins >> department;

            if (department == "Tops")
            {
                Tops tmp;
                tmp.input(ins);
                Tops *ptr = new Tops(tmp);
                items.push_back(ptr);
                total += tmp.cost();
            }
            else if (department == "Bottoms")
            {
                Bottoms tmp;
                tmp.input(ins);
                Bottoms *ptr = new Bottoms(tmp);
                items.push_back(ptr);
                total += tmp.cost();
            }
            else if (department == "Shoes")
            {
                Shoes tmp;
                tmp.input(ins);
                Shoes *ptr = new Shoes(tmp);
                items.push_back(ptr);
                total += tmp.cost();
            }
            else if (department == "Outerwear")
            {
                Outerwear tmp;
                tmp.input(ins);
                Outerwear *ptr = new Outerwear(tmp);
                items.push_back(ptr);
                total += tmp.cost();
            }

            ins >> ws;
        }
    }
}

void Order::output(ostream &outs)
{
    if (&outs == &cout)
    {
        outs << "Order Name: " << order_name << endl;
        for (auto it = items.begin(); it != items.end(); ++it)
        {
            (*it)->output(outs);
        }
        outs << "Total: $" << total << endl;
    }
    else
    {
        outs << order_name << endl;
        for (auto it = items.begin(); it != items.end(); ++it)
        {
            (*it)->output(outs);
        }
    }
}

void Order::add_to_order(Clothes* ptr) {
    items.push_back(ptr);
}

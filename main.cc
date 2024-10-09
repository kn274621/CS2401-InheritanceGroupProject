/**
 * File name: "main.cc"
 * Description: Main program for a shopping application that allows you to make orders
 *      based on a specific set of options in the Clothes class and its child classes.
 * Authors: Karli Nadsady, Cooper Smith, Kalina Rabe Harinoro, Aiden Schmoll
 */

#include <iostream>
#include <fstream>
#include <cctype>
#include "order.h"
#include "clothes.h"
#include "tops.h"
#include "bottoms.h"
#include "outerwear.h"
#include "shoes.h"
#include <list>
#include <string>

using namespace std;

int menu(Order current_order);
void load(istream &ins, list<Order> &orders);
void save(ostream &outs, list<Order> orders);
void add_to_list(string dep, Order &o);
void view_orders(list<Order> orders);
void remove_order(list<Order>& orders);

int main()
{
    // declare variables
    list<Order> order_list;
    string dep;
    int choice;
    ifstream fin;
    ofstream fout;
    string username, filename, fullname;

    // welcome the user, then prompt for username for input/output file
    cout << "Welcome to Our Shopping center.\n\n";
    cout << "The departments of our items are (Tops, Bottoms, Shoes, Outerwear)\n";
    cout << "Begin by entering your username: ";
    cin >> username;
    filename = username + ".txt";
    fin.open(filename.c_str());

    string tmp;
    cout << "Enter name for the current order: ";
    cin >> tmp;

    Order myorder(tmp);

    // check if instream valid, then input orders
    if (!fin.fail())
    {
        load(fin, order_list);
        fin.close();
    }

    // prompt user for input from menu options
    choice = menu(myorder);
    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            cout << "Which department would you like to get an item from?\n";
            cin >> dep;
            add_to_list(dep, myorder);
            break;
        case 2:
            order_list.push_back(myorder);
            cout << "Enter name for new order: ";
            cin >> tmp;
            myorder.set_order_name(tmp);
            break;
        case 3:
            view_orders(order_list);
            break;
        case 4:
            remove_order(order_list);
            break;
        default:
            cout << "Invalid choice";
            break;
        }
        choice = menu(myorder);
    }

    // save data to outstream file
    fout.open(filename.c_str());
    if (!fout.fail())
        save(fout, order_list);
    else
        cout << "Problem with saving data!\n";
    fout.close();

    return 0;
}

// display the menu to the user
int menu(Order current_order)
{
    int c;
    cout << "Current Order: " << current_order.get_order_name() << endl
         << "1. Add a product to the current order" << endl
         << "2. Add the current order to the list" << endl
         << "3. View a list of all orders" << endl
         << "4. Remove an order that has been completed" << endl
         << "5. Exit the program" << endl;
    cin >> c;
    return c;
}

// import data from instream
void load(istream &ins, list<Order> &orders)
{
    while (!ins.eof())
    {
        Order temp;
        if (ins.peek() == '*')
        {
            ins.ignore();
        }
        ins >> ws;
        if (ins.eof())
        {
            return;
        }
        temp.input(ins, "");
        orders.push_back(temp);

        ins >> ws;
    }
}

// save data to outstream
void save(ostream &outs, list<Order> orders)
{
    for (auto it = orders.begin(); it != orders.end(); it++)
    {
        (*it).output(outs);
        outs << "*" << endl;
    }
}

// add an order to the current list
void add_to_list(string dep, Order &o)
{

    if (dep == "Tops")
    {
        Tops *ptr = new Tops;
        ptr->input(cin);
        o.add_to_order(ptr);
        o.set_total(ptr->cost());
    }
    else if (dep == "Bottoms")
    {
        Bottoms *ptr = new Bottoms;
        ptr->input(cin);
        o.add_to_order(ptr);
        o.set_total(ptr->cost());
    }
    else if (dep == "Shoes")
    {
        Shoes *ptr = new Shoes;
        ptr->input(cin);
        o.add_to_order(ptr);
        o.set_total(ptr->cost());
    }
    else if (dep == "Outerwear")
    {
        Outerwear *ptr = new Outerwear;
        ptr->input(cin);
        o.add_to_order(ptr);
        o.set_total(ptr->cost());
    }
    else
    {
        cout << "BAD DEPARTMENT\n";
    }
}

// view orders in the current list
void view_orders(list<Order> orders)
{
    for (auto it = orders.begin(); it != orders.end(); it++)
    {
        (*it).output(cout);
        cout << endl;
    }
}

// remove order from the current list
void remove_order(list<Order>& orders)
{
    string tmp;
    cout << "Name of the order to remove: ";
    cin >> tmp;

    for (auto it = orders.begin(); it != orders.end(); it++)
    {
        string tmp2 = (*it).get_order_name();
        if(tmp2 == tmp)
        {
            it = orders.erase(it);
        }
    }
}
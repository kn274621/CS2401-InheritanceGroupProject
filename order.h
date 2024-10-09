/**
 * File name: "order.h"
 * Description: Header file of the Order container class, which holds Clothes objects.
 * Authors: Karli Nadsady, Cooper Smith, Kalina Rabe Harinoro, Aiden Schmoll
 */

#include <list>
#include <iostream>
#include "clothes.h"
#include "tops.h"
#include "bottoms.h"
#include "outerwear.h"
#include "shoes.h"

class Order
{
public:
    // default constructor
    Order(std::string n = "", double t = 0, std::list<Clothes *> ptr = {});

    // in/outstream functions
    void input(std::istream &ins, std::string dep);
    void output(std::ostream &outs);
    void add_to_order(Clothes* ptr);

    // getter function
    std::string get_order_name() { return order_name; }

    // setter functions
    void set_total(int add) { total += add; }
    void set_order_name(std::string n) { order_name = n; }

private:
    // options for orders: name of the order, total cost of the order, items in the order
    std::string order_name;
    double total;
    std::list<Clothes *> items;
};
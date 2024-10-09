/**
 * File name: "clothes.h"
 * Description: Header file of Clothes parent class
 * Authors: Karli Nadsady, Cooper Smith, Kalina Rabe Harinoro, Aiden Schmoll
 */

#ifndef CLOTHES_H
#define CLOTHES_H

#include <iostream>

class Clothes
{
public:
    // virtual lets a function of the parent class call a function in the child class
    virtual double cost(); 

    // in/outstream functions
    virtual void input(std::istream &ins);
    virtual void output(std::ostream &outs);

    // setter functions
    void set_name(std::string n);
    void set_color(std::string c);

    // getter function
    std::string get_department() { return department; }

protected:
    // protected so child class can access
    // options for all clothes:
    // price ($), department (child class), item name, item color
    double price;
    std::string department;
    std::string name;
    std::string color;
};
#endif
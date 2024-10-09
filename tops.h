/**
 * File name: "tops.h"
 * Description: Header file of Tops child class of Clothes parent class.
 * Author: Aiden Schmoll
*/

#ifndef TOPS_H
#define TOPS_H

#include "clothes.h"

class Tops : public Clothes
{
public:
    // default constructor
    Tops(char s = 'm', std::string sle = "none", std::string d = "tops", std::string n = "", double p = 30, std::string c = "");

    // cost of the item
    double cost();

    // in/outstream functions
    void input(std::istream &ins);
    void output(std::ostream &outs);

    // setter functions
    void set_size(char s);
    void set_sleeves(std::string s);

private:
    // options for tops: size and sleeves
    char size; // small, medium, large
    std::string sleeves; // long, short, none
};

#endif

/**
 * File name: "bottoms.h"
 * Description: Header file of Bottoms child class of Clothes parent class.
 * Author: Cooper Smith
*/

#ifndef BOTTOMS_H
#define BOTTOMS_H

#include "clothes.h"

class Bottoms : public Clothes
{
public:
    // default constructor
    Bottoms(double w = 0, bool s = false, std::string d = "bottoms", std::string n = "", double p = 20, std::string c = "");
    
    // cost of the item
    double cost();

    // in/outstream functions
    void input(std::istream &ins);
    void output(std::ostream &outs);

    // setter functions
    void set_waist(double w);
    void set_shorts(bool s);

private:
    // options for bottoms:
    // waist size (in) and whether or not they are pants or shorts
    double waist;
    bool is_shorts;
};
#endif
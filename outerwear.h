/**
 * File name: "outerwear.h"
 * Description: Header file of Outerwear child class of Clothes parent class.
 * Author: Kalina Rabe Harinoro
*/
#include <string>
#ifndef OUTERWEAR_H
#define OUTERWEAR_H

#include "clothes.h"

class Outerwear : public Clothes
{
public:
    // default constructor
    Outerwear(bool h = false, bool z = false, char s = ' ', std::string d = "outerwear", std::string n = " ", double p = 50, std::string c = " ");
    
    // cost of the item
    double cost();

    // in/outstream functions
    void input(std::istream &ins);
    void output(std::ostream &outs);

    // setter functions
    void set_hood(bool h);
    void set_zipper(bool z);
    void set_size(char s);

private:
    // options for outerwear: hood, zipper, and size
    bool hood;
    bool zipper;
    char size; // s: small, m: medium, l: large
};

#endif

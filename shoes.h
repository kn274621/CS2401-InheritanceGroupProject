/**
 * File name: "shoes.h"
 * Description: Header file of Shoes child class of Clothes parent class.
 * Author: Karli Nadsady
*/

#ifndef SHOES_H
#define SHOES_H

#include "clothes.h"

class Shoes : public Clothes
{
public:
    // default constructor
    Shoes(double z = 0, std::string y = "", std::string h = "", std::string d = "shoes", std::string n = "", std::string c = "", double p = 70);
    
    // cost of item
    double cost();
    
    // in/outstream functions
    void input(std::istream &ins);
    void output(std::ostream &outs);

    // setter functions
    void set_size(double z);
    void set_style(std::string y);
    void set_height(std::string h);

private:
    // options for shoes: size, style, height
    double size;
    std::string style; // sneaker, sandal, boot
    std::string height; // ankle, calf, knee
};
#endif
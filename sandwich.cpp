/*Lydia Scharff 11/8*/

#include <string>
#include <iostream>
#include "sandwich.hpp"

using namespace std;

// used for Custom class
Sandwich::Sandwich(void)
{
    drink = false;
    chips = false;
}

//create sig sandwich based on menu values
Sandwich::Sandwich(string t, float p):type(t),price(p)
{
    drink = false;
    chips = false;
}

void Sandwich::setDrink(void)
{
    drink = true;
}

void Sandwich::setChips(void)
{
    chips = true;
}

string Sandwich::getType(void)
{
    return type;
}

//get price while taking into account discount
float Sandwich::getPrice(void)
{
    if(drink && chips)
    {
        price=price-1.50;
    }
    return price;
}

//format sandwich order
void Sandwich::printSand(void)
{
    cout << type;
    if(drink && chips)
    {
        cout << " with a drink and chips";
    } 
    else if(drink)
    {
        cout << " with a drink";
    }
    else if(chips)
    {
        cout << " with chips";
    }
    cout << " for $" << price << endl;
}




//class for custom sandwiches
Custom::Custom(string b, float p1, string m, float p2):bread(b), maintop(m)
{
    price = p1 + p2;
    type = "Custom: ";
    veg = false;
    che = false;
    cond = false;
}

void Custom::setVeg(void)
{
    veg=true;
    price+=1.0;
}

void Custom::setChe(void)
{
    che=true;
    price+=1.0;
}

void Custom::setCond(void)
{
    cond=true;
    price+=.25;
}

//format options in custom sandwich
void Custom::formatSand(void)
{
    type=type+maintop+" with ";
    if(veg)
    {
        type+=" vegetables,";
    } 
    if(che)
    {
        type+=" cheese,";
    } 
    if(cond)
    {
        type+=" condiments,";
    } 
    type+=" on "+bread;
}

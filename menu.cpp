/*Lydia Scharff 11/8*/


#include <string>
#include <iostream>
#include <vector>
#include "menu.hpp"


using namespace std;



Menu::Menu(int n):num(n),items(n),prices(n)
{
}

// format and print menu items
void Menu::printMenu(void)
{
    cout << "# \t Item \t\t Price" << endl;
    for(int j = 0; j < num; j++)
    {
        cout << j+1 << "\t " << items[j] << "\t\t " << prices[j] << endl;
    }
}

// set menu items from vector
void Menu::setItems(vector<string> i)
{
    items=i;
}

// set menu prices from vector
void Menu::setPrices(vector<float> p)
{
    prices=p;
}

// return name associated with item number 
string Menu::getItem(int n)
{
    return items[n];
}

// return price associated with item number 
float Menu::getPrice(int m)
{
    return prices[m];
}

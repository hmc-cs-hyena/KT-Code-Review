/* Lydia Scharff 11/8*/

#include <string>
#include <iostream>
#include <vector>
#include "menu.hpp"
#include "sandwich.hpp"
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

Sandwich custom(void)
{
    //Set up custom sandwich menus
    Menu mainMenu(3);
    mainMenu.setItems({"Tuna","Bacon","Falafel"});
    mainMenu.setPrices({6.0,5.0,6.50});
    Menu breadMenu(3);
    breadMenu.setItems({"Wheat","Sourdough","Rye"});
    breadMenu.setPrices({1.0,2.0,1.50});
    

    int n=0,m=0;
    string s;
    string in;
    bool isvaldig=false;
    
    while(!isvaldig)
    {
        // print toppings menu and get user choice
        mainMenu.printMenu();
        cout << "Enter the list number for the main topping you want to order:";
        cin >>  in;
        // check input is a number
        if(isdigit(in[0]))
        {
            m = stoi(in);
        }
        //check input is a valid list number
        if(m>0 && m<4)
        {
            m--;
            isvaldig = true;
        }
        else
        {
            cout<<"Please enter a valid number from the list"<<endl;
        }
    }
    isvaldig = false;
    while(!isvaldig)
    {
        // print bread menu and get user choice
        breadMenu.printMenu();
        cout << "Enter the list number for the bread you want to order:";
        cin >>  in;
        if(isdigit(in[0]))
        {
            n = stoi(in);
        }
        if(n>0 && n<4)
        {
            n--;
            isvaldig = true;
        }
        else
        {
            cout<<"Please enter a valid number from the list"<<endl;
        }
    }

    //custom sandwich based on user inputs
    Custom sand = Custom(breadMenu.getItem(n),breadMenu.getPrice(n),mainMenu.getItem(m),mainMenu.getPrice(m));

    // get user input for other toppings
    cout << "Do you want vegetables? (y/n)";
    cin >> in;
    if(in.compare("y")==0)
    {
        sand.setVeg();
    }
    cout << "Do you want cheeses? (y/n)";
    cin >> in;
    if(in.compare("y")==0)
    {
        sand.setChe();
    }
    cout << "Do you want condiments? (y/n)";
    cin >> in;
    if(in.compare("y")==0)
    {
        sand.setCond();
    }
    sand.formatSand();
    return sand;
}

int main()
{
    
    Menu sandMenu(4);
    sandMenu.setItems({"BLT", "Ruben", "Club", "Custom"});
    sandMenu.setPrices({7.0,8.0,9.0,0.0});

    bool ordering = true;
    string in;
    int n=0;
    float p =0.0;
    bool isvaldig=false;
    vector<Sandwich> order;

    cout << setprecision(2) << fixed;
    
    cout<<"\n\n\n"<<endl;
    cout<<"Welcome to the sandwich ordering system"<<endl;
    //repeat as needed for multiple orders
    while(ordering)
    {         
        while(!isvaldig)
        {
            // print sadnwich menu and get user choice
            sandMenu.printMenu();
            cout << "Enter the list number for the sandwich you want to order:";
            cin >>  in;
            
            //check for valid input
            if(isdigit(in[0]))
            {
                n = stoi(in);
            }
            if(n>0 && n<5)
            {
                n--;
                isvaldig = true;
                if(n==3)
                {   
                    //create custom sandwich 
                    order.push_back(custom());
                }
                else if(n<3)
                {
                    Sandwich s = Sandwich(sandMenu.getItem(n),sandMenu.getPrice(n));
                    order.push_back(s);
                } 
            }
            else
            {
                cout<<"Please enter a valid number from the list"<<endl;
            }
        }       

        // get user input on drink / chips
        cout << "Do you want a drink? (y/n)";
        cin >> in;
        if(in.compare("y")==0)
        {
            order.back().setDrink();
            cout << "Do you want to make that a meal combo with chips? (y/n)";
        }
        else
        {
            cout << "Do you want chips? (y/n)";
        }
        cin >> in;
        if(in.compare("y")==0)
        {
            order.back().setChips();
        }

        //check if end of order
        cout << "Do you want to order another sandwich? (y/n)";
        cin >> in;
        if(in.compare("n")==0)
        {
            ordering = false;
        }
        else
        {     
            isvaldig = false;
        }
    }
    //print complete order
    cout << "Your order is:"<<endl;
    for(size_t i = 0; i <order.size();i++)
    {
        p+=order[i].getPrice();
        order[i].printSand();
    }
    cout << "for a total of $" << p << endl;
    cout << "Is that correct? (y/n)";
    cin >> in;
    if(in.compare("y")==0)
    {
        cout << "Your order has been placed" <<endl;
    }
    else if(in.compare("n")==0)
    {
        cout << "Oops, Sorry" <<endl;
    }

return 0;

}
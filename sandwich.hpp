/*Lydia Scharff 11/8*/

#include <string>
#include <iostream>


using namespace std;

class Sandwich {
public:

Sandwich(void);
Sandwich(string t, float p);

void setDrink(void);

void setChips(void);

string getType(void);

float getPrice(void);

void printSand(void);

protected:
    string type;
    float price;
    bool drink;
    bool chips;
};



class Custom: public Sandwich {
public:

Custom(string b, float p1, string m, float p2);

void setVeg(void);
void setChe(void);
void setCond(void);

void formatSand(void);

private:
    string bread, maintop;
    bool veg, che, cond;

};
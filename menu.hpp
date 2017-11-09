/*Lydia Scharff 11/8*/


#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Menu {
public:

Menu(int n);

void printMenu(void);

void setItems(vector<string> i);

void setPrices(vector<float> p);

string getItem(int n);

float getPrice(int m);

private:
    int num;
    vector<string> items;
    vector<float> prices;
};
#include <bits/stdc++.h>
#include "hashtable.h"
using namespace std;

int main()
{
    HashTable<int> price_menu;

    price_menu.insert("Burger", 120);
    price_menu.insert("Pepsi", 60);
    price_menu.insert("Noodles", 65);
    price_menu.insert("Coke", 47);
    price_menu.insert("Beer", 99);

    price_menu.print();

    int *price = price_menu.search("Beer");
    if (price == NULL)
        cout << "Not present" << endl;
    else
        cout << *price << endl;

    price_menu["Coke"] += 10;
    cout << price_menu["Coke"] << endl;
}

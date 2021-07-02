#ifndef MENU_H
#define MENU_H

using namespace std;

void menu() {
    cin.get();
    system("cls");
    cout << "\n----------What would you like to do next?----------\n";
    cout << " A - Add Item to the Cart\n";
    cout << " D - Delete Item from Cart\n";
    cout << " L - List Prices for Items in your Shopping Cart\n";
    cout << " P - Show Total Shopping Cart Price\n";
    cout << " I - Show Total Number of Items from Shopping Cart\n";
    cout << " Q - Print Bill and Exit\n\n";
}

#endif // MENU_H

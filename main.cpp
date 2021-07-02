#include <iostream>
#include <stdlib.h>
#include <string>
#include "Menu.h"
#include "ShoppingCart.h"


using namespace std;
char option;

int main()
{
    cout << "Press any key to start.\n";

    do {

        menu();

        cin >> option;

        switch (option) {
            case 'A':
                system("cls");
                AddItem();
                break;
            case 'D':
                system("cls");
                DeleteItem();
                cout << "Press any key to continue!\n";
                cin.get();
                break;
            case 'L':
                system("cls");
                ListProducts();
                cout << "\nPress any key to continue!\n";
                cin.get();
                break;
            case 'P':
                system("cls");
                TotalPrice();
                cout << "\nPress any key to continue!\n";
                cin.get();
                break;
            case 'I':
                system("cls");
                TotalItems();
                cin.get();
                break;
            case 'Q':
                system("cls");
                ShowBill();
                cout << "\nHave a nice day!\n";
                break;
        }
    } while (option != 'Q');

    return 0;
}

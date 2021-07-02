#include <iostream>
#include <string>
#include "ShoppingCart.h"
#include "Product.h"

using namespace std;
ShoppingCart* first = NULL;
ShoppingCart* last = NULL;

void AddItem()
{
    int id;
    float price;

    cout << "  Introduce product ID:\n";
    cin >> id;
    cout << "  Introduce product price:\n";
    cin >> price;

    struct ShoppingCart* sc = new ShoppingCart;
    sc->product = new Product(id, price);
    sc->next = NULL;
    sc->prev = NULL;

    if(first == NULL)
    {
        first = sc;
    }
    else
    {
        struct ShoppingCart* s = first;
        while(s->next != NULL)
        {
            s = s->next;
        }
        s->next = sc;
        sc->prev = s;
    }
}

void ListProducts() {
    cout << "\n  Product ID ----- Product Price (EUR)\n";
    struct ShoppingCart* p = first;
    while(p != NULL) {
        cout << "       " << p->product->getId() << "                " << p->product->getPrice() << "\n";
        p = p->next;
    }

}

void DeleteItem() {
    int idNumber;
    cout << "  Introduce ID of product you'd like to delete:\n";
    cin >> idNumber;

    struct ShoppingCart* p = first;
    if(p == NULL) {
        cout << "  Your cart is already empty.\n";
        return;
	}
    while(p->next != NULL && p->product->getId() != idNumber){
		p = p->next;
	}
	if(p->next == NULL && p->product->getId() != idNumber) {
		cout << "  This product does not exist in your cart.\n";
	}
	if(p->product->getId() == first->product->getId()){
		first = p->next;
		delete p;
	}
	if(p->product->getId() == idNumber && p->next != NULL && p->prev != NULL){
		p->next->prev = p->prev;
		p->prev->next = p->next;
		delete p;
	}
	if(p->product->getId() == idNumber && p->next == NULL){
		p->prev->next = NULL;
		delete p;
	}
}

void TotalItems() {
    int total = 0;
    struct ShoppingCart* p = first;
    while(p != NULL) {
        total++;
        p = p->next;
    }
    cout << "  You have " << total << " items in your cart.\n";
    cout << "  \nPress any key to continue!\n";
}

float GetTotalPrice () {
    int sum = 0;
    struct ShoppingCart* p = first;
    while(p != NULL) {
        sum += p->product->getPrice();
        p = p->next;
    }
}

void TotalPrice() {
    char value;
    cout << "Please select preferred currency:\n A - EUR;\n B - USD;\n";
    cin >> value;
    switch (value) {
        case 'A':
            cout << "  The total price of your order is " << GetTotalPrice() << " EUR.\n";
            break;
        case 'B':
            cout << "  The total price of your order is " << GetTotalPrice()*1.19 << " USD.\n";
            break;
    }
}


void ShowBill() {
    string name;
    cout << "Please enter client name: \n";
    cin.ignore();
    getline(cin, name);
    char value;
    cout << "Please select preferred currency:\n A - EUR;\n B - USD;\n";
    cin >> value;
    cout << "\n     ----- Bill Details -----\n";
    ListProducts();
    switch (value) {
        case 'A':
            cout << "  Total _______________ " << GetTotalPrice() << " EUR.\n";
            break;
        case 'B':
            cout << "  Total _______________ " << GetTotalPrice()*1.19 << " USD.\n";
            break;
    }

    cout << "\n";
    cout << "  Client __________ " << name << "\n\n";
}

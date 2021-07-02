#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Product.h"
using namespace std;

struct ShoppingCart {
    Product* product;
    ShoppingCart* next;
    ShoppingCart* prev;
};

void AddItem();
void ListProducts();
void DeleteItem();
void TotalItems();
float GetTotalPrice();
void TotalPrice();
void ShowBill();

#endif // SHOPPINGCART_H

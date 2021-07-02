#include "Product.h"

using namespace std;

Product::Product(int id, float price) {
    this->id = id;
    this->price = price;
}

int Product::getId() {
    return this->id;
}

float Product::getPrice() {
    return this->price;
}

Product::~Product() {
}

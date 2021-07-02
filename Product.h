#ifndef PRODUCT_H
#define PRODUCT_H

using namespace std;

class Product {
    private:
        int id;
        float price;
    public:
        Product(int id, float price);
        virtual ~Product();
        int getId();
        float getPrice ();
};

#endif // PRODUCT_H

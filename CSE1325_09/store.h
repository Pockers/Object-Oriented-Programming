#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED
#include <vector>
#include <iostream>
#include <istream>
#include <ostream>
#include "product.h"
#include "donut.h"
#include "java.h"

class Store{
public:
    Store(std::string store_name);
    std::string name();
    void add_product(Product* product);
    int number_of_products();
    std::string product_to_string(int product);
    std::string all_products();
    friend std::ostream& operator<<(std::ostream& ost, const Product& product);
private:
    std::string _name;
    std::vector<Product*> _products;
};

#endif

#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include <map>

class Product{

protected:
    std::string _name;
    double _price;
    double _cost;

public:
    Product(std::string name, double price, double cost);
    std::string name() const;
    virtual std::string to_string() const;
};

#endif

#include "product.h"
#include <string>
#include <iostream>

Product::Product(std::string name, double price, double cost)
    : _name{name}, _price{price}, _cost{cost} {}


std::string Product::name() const
{
    return _name;
}

std::string Product::to_string() const
{
    std::string productInformation;
    productInformation = _name + " " + std::to_string(_price) + " " + std::to_string(_cost);
    return productInformation;
}

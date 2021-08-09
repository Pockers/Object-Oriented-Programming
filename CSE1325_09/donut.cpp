#include "donut.h"
#include <string>
#include <iostream>

Donut::Donut(std::string name, double price, double cost, Frosting frosting, bool sprinkles, Filling filling)
    : Product::Product(name, price, cost), _frosting{frosting}, _sprinkles{sprinkles}, _filling{filling} {}

std::string Donut::to_string() const
{
    std::string convertedFilling = Donut::convert_filling(_filling);
    std::string convertedFrosting = Donut::convert_frosting(_frosting);
    std::string donutString;
    if (_sprinkles == true)
    {
        donutString = convertedFrosting + " frosted " + convertedFilling + " jelly-filled donut with sprinkles.";
    }
    else if (_sprinkles == false)
    {
        donutString = convertedFrosting + " frosted " + convertedFilling + " jelly-filled donut.";
    }
    //Product::_name = donutString;
    return donutString;
}

std::string Donut::convert_frosting(Frosting f) const
{
    std::map<Frosting, std::string> f_to_str =
    {
        {Frosting::UNFROSTED, "Unfrosted"},
        {Frosting::CHOCOLATE_TOP, "Chocolate Top"},
        {Frosting::VANILLA_TOP, "Vanilla Top"},
        {Frosting::PINK_TOP, "Pink Top"},
    };
    return f_to_str[f];
}

std::string Donut::convert_filling(Filling f) const
{
    std::map<Filling, std::string> f_to_str =
    {
        {Filling::UNFILLED, "Unfilled"},
        {Filling::CREME, "Creme"},
        {Filling::BAVARIAN, "Bavarian"},
        {Filling::STRAWBERRY, "Strawberry"},
    };
    return f_to_str[f];
}

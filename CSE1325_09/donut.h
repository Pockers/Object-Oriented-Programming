#ifndef DONUT_H_INCLUDED
#define DONUT_H_INCLUDED
#include <map>
#include "product.h"

enum class Frosting {UNFROSTED, CHOCOLATE_TOP, VANILLA_TOP, PINK_TOP};
enum class Filling {UNFILLED, CREME, BAVARIAN, STRAWBERRY};

class Donut : public Product{
public:
    Donut(std::string name, double price, double cost, Frosting frosting, bool sprinkles, Filling filling);
    std::string to_string() const override;
    std::string convert_frosting(Frosting f) const;
    std::string convert_filling(Filling f) const;
private:
    Frosting _frosting;
    bool _sprinkles;
    Filling _filling;
};

#endif

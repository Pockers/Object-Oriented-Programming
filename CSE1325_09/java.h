#ifndef JAVA_H_INCLUDED
#define JAVA_H_INCLUDED
#include <map>
#include <vector>
#include "product.h"

enum class Shot {NONE, CHOCOLATE, VANILLA, PEPPERMINT, HAZELNUT};

class Java : public Product{
public:
    Java(std::string name, double price, double cost, int darkness);
    std::string to_string() const override;
    std::string convert_shot(Shot s) const;
    void add_shots(Shot shot);
private:
    int _darkness;
    std::vector<Shot> _shots;
};

#endif

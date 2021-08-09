#include "store.h"
#include <iostream>
#include <sstream>
#include <fstream>

Store::Store(std::string store_name)
	: _name{store_name} 
	{
			Donut donut("Testing", 2.20, 3.20, Frosting::CHOCOLATE_TOP, true, Filling::BAVARIAN);
			Java java("Testing2", 2.20, 3.30, 2);
	}

std::string Store::name()
{
	return _name;
}

void Store::add_product(Product* product)
{
	_products.push_back(product);
}

int Store::number_of_products()
{
	return _products.size();
}

std::ostream& operator<<(std::ostream& ost, const Product& product)
{
	ost << product.name() << "\n" << product.to_string();
	return ost;
}

std::string Store::all_products()
{
	std::ostringstream ost;
	for (auto product : _products)
	{
		ost << product << std::endl;
	}
	
	return ost.str();
}



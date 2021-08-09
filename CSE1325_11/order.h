#pragma once
#include <vector>
#include <ostream>
#include <istream>
#include <sstream>
#include "product.h"

class Order {
	private:
	std::vector<Product*> _products;
	static int _next_order_number;
	int _order_number;
	bool _is_paid = false;
	bool _is_filled = false;
	
	public:
	Order();
	int order_number();
	void add_product(Product* product);
	bool paid();
	void pay();
	bool filled();
	void fill();
	bool operator<(const Order& rhs) const;
	std::string order_string() const;
	friend std::ostream& operator<<(std::ostream& ost, const Order& order);
};

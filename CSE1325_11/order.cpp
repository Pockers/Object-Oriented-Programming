#include "order.h"

Order::Order() { _order_number += 1; }

int Order::order_number(){
	//return _order_number;
}

void Order::add_product(Product* product){
	_products.push_back(product);
}

bool Order::paid(){
	return _is_paid;
}

void Order::pay(){
	_is_paid = true;
}

bool Order::filled(){
	return _is_filled;
}

void Order::fill(){
	_is_filled = true;
}

bool Order::operator<(const Order& rhs) const {
	if(rhs._order_number < this->_order_number){
		return true;
	}
}

std::string Order::order_string() const{
	std::ostringstream oss;
	for (auto p : _products) {
		oss << p->to_string() << std::endl;
	}
	
	return oss.str();
}

std::ostream& operator<<(std::ostream& ost, const Order& order) {
	ost << order.order_string();
	return ost;
}

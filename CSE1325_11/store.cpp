#include "store.h"
#include <sstream>

Store::Store(std::string store_name) : _name{store_name} { }
std::string Store::name() {return _name;}

void Store::add_product(Product* product) {_products.push_back(product);}
int Store::number_of_products() {return _products.size();}
std::string Store::product_to_string(int product) {
    std::ostringstream oss;
    oss << _products[product];
    return oss.str();
}

void Store::add_customer(Customer* customer) {_customers.push_back(customer);}
int Store::number_of_customers() {return _customers.size();}
std::string Store::customer_to_string(int customer) {
    std::ostringstream oss;
    oss << *_customers[customer];
    return oss.str();
}

// Order Code for Store
void Store::place_order(Order order, int customer) {
	std::pair <Order, Customer> orderPair; 
	orderPair = std::make_pair(order, *_customers[customer]);
	_orders.insert(std::make_pair(order, *_customers[customer]));
}
int Store::number_of_orders() {return _orders.size();}

std::string Store::order_to_string(int order_number) {
	std::ostringstream oss;
	std::map<Order, Customer>::iterator end = _orders.end();
	int counter = 0;
	oss << "Order #" << order_number << "\n";
	for (std::map<Order, Customer>::iterator it = _orders.begin(); it != end; ++it) {
		if (counter == order_number)
		{
			oss << it->first << '\n' << it->second;
		}
		counter++;
	}
	

	return oss.str();
}

std::ostream& operator<<(std::ostream& ost, Store& store) {
    ost << "Store " << store._name << std::endl << std::endl;
    ost << "Products: " << std::endl;
    for (auto p : store._products) ost << "  " << p->to_string() << std::endl;
    return ost;
}

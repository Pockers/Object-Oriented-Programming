#include "customer.h"

Customer::Customer(std::string renter, std::string renter_phone)
	: _customer{renter}, _customer_phone{renter_phone} { }

Customer::Customer() : Customer("", "") { }

Customer::Customer(std::istream& ist)
{
	std::getline(ist, _customer);
	std::getline(ist, _customer_phone);
}

void Customer::save(std::ostream& ost)
{
	ost << _customer << std::endl;
	ost << _customer_phone << std::endl;
}

std::string Customer::to_string() const 
{
	return _customer + ", " + _customer_phone;
}

std::ostream& operator<<(std::ostream& ost, const Customer& customer)
{
	ost << customer.to_string();
	return ost;
}

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <ostream>
#include <istream>

class Customer{
	private:
	std::string _customer;
	std::string _customer_phone;
	
	public:
	Customer(std::string renter, std::string renter_phone);
	Customer();
	Customer(std::istream& ist);
	void save(std::ostream& ost);
	std::string to_string() const;
	friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
};

#endif


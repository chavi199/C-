#include "Address.h"
#include <iostream>

Address::Address()
{
	city = "";
	street = "";
	house_number = 1;
}

Address::Address(string city, string street, string house_number)
{
	this->city = city;
	this->street = street;
	this->house_number = house_number;
}

void Address::print() const
{
	std::cout << "City: " << city << std::endl;
	std::cout << "Street: " << street << std::endl;
	std::cout << "House number: " << house_number << std::endl;
}


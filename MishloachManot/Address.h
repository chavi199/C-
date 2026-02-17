#pragma once
#include <string>
using namespace std;
class Address
{
	string city;
	string street;
	string house_number;

public:
	Address();
	Address(string city, string street, string house_number);
	void print()const;

};



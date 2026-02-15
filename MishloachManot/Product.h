#pragma once
#include<iostream>
#include <string>
using namespace std;
enum Kashrut
{
	badats,
	rubin,
	lando
};
class Product
{
	string productName;
	double price;
	int amount;
	Kashrut KashrutType;
public:

	//Kashrut KashrutType;
	Product();
	Product(string, double, int, Kashrut);
	double Sum();
	void Print();
	Kashrut getKashrut() const { return KashrutType; }


};


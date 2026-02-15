#pragma once
using namespace std;
#include <string>
#include<iostream>
#include <vector>
#include "Product.h"
#include "Address.h"



class Mishloach
{
	string SenderName;
	string RecipientName;
	Address ShippingAddress;
	int ToolPrice;
	vector<Product>Vector;
	static int DesignPrice;
public:
	Mishloach();
	Mishloach(string , string , Address );
	void AddProduct(Product);
	virtual double CalPrice() const;
	friend bool operator>(Mishloach&, Mishloach&);
	friend bool operator==(Mishloach&, Mishloach&);
	void Print() const;
	bool IsSameKashrut(Kashrut);





};


#include "Product.h"
using namespace std;

Product::Product()
{
	productName = " ";
	price = 0;
	amount = 0;
	KashrutType = badats;
}

Product::Product(string pname, double p, int a, Kashrut k) :productName(pname), price(p), amount(a), KashrutType(k)
{
}

double Product::Sum()
{
	return amount * price;
}

void Product::Print()
{
	cout << "productName " << productName << "price" << price << "amount" << amount << endl;

}



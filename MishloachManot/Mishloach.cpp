#include "Mishloach.h"

int Mishloach::DesignPrice = 10;

Mishloach::Mishloach()
{
	this->ToolPrice = 15;
}

Mishloach::Mishloach(string SenderName, string RecipientName, Address ShippingAddress)
{
	this->SenderName = SenderName;
	this->RecipientName = RecipientName;
	this->ShippingAddress = ShippingAddress;
	this->ToolPrice = 15;

}

void Mishloach::AddProduct(Product p)
{
	Vector.push_back(p);
}

double Mishloach::CalPrice()const
{
	double sum = 0;
	for(Product item : Vector)
	{
		sum += item.Sum();
	}
	sum += ToolPrice;
	sum += DesignPrice;
	return sum;
}

void Mishloach::Print() const
{
	cout << "Sender Name: " << SenderName << endl;
	cout << "Recipient Name: " << RecipientName << endl;
	cout << "Shipping Address: " <<  endl;
	ShippingAddress.print();

	cout << "Products: " << endl;
	for (Product item : Vector)
	{
		item.Print();
	}
	/*cout << "Total Price: " << CalPrice() << endl;*/
}

bool Mishloach::IsSameKashrut(Kashrut k)
{
	for (Product item : Vector)
	{
		if(item.getKashrut() != k)
			return false;
	}
	return true;
}

bool operator>(Mishloach& m1, Mishloach& m2)
{
	return m1.CalPrice() > m2.CalPrice();
}

bool operator==(Mishloach& m1, Mishloach& m2)
{
	return m1.CalPrice() ==m2.CalPrice() ;
}

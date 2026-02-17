#include "Gift.h"
#include <iostream>
using namespace std;

// Constructor
Gift::Gift(string name, double price, GiftSize size, string sender, string recipient, Address address)
    : Mishloach(sender, recipient, address), giftName(name), giftPrice(price), giftSize(size)
{
}

//double Gift::CalPrice() const
//{
//    
//     return Base::CalPrice() + giftPrice; // ����� �� ����� ����� �� ����� ���� ���� ����� �� ����� �����
//    
//}




Gift::Gift()
    : Mishloach(), giftName("Default Gift"), giftPrice(0.0), giftSize(Small)
{
   
}



//string Gift::GetGiftName() const
//{
//    return giftName;
//}
//
//double Gift::GetGiftPrice() const
//{
//    return giftPrice;
//}
//
GiftSize Gift::GetGiftSize() const
{
   return giftSize;
}
//
// (Setters)
//void Gift::SetGiftName(const string& name)
//{
//    giftName = name;
//}
//
//void Gift::SetGiftPrice(double price)
//{
//    giftPrice = price;
//}
//
//void Gift::SetGiftSize(GiftSize size)
//{
//    giftSize = size;
//}


void Gift::PrintGiftDetails() const
{
    cout << "Gift Name: " << giftName << endl;
    cout << "Gift Price: " << giftPrice << endl;
    cout << "Gift Size: ";
    switch (giftSize)
    {
    case Small:
        cout << "Small";
        break;
    case Medium:
        cout << "Medium";
        break;
    case Large:
        cout << "Large";
        break;
    }
    cout << endl;
}



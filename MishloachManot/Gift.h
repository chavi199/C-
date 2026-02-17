#pragma once
#include "Mishloach.h" // ��� ���� ���� �� ����� �� ������ �������
#include <string>
using namespace std;


// ����� enum ���� ���� �����
enum GiftSize
{
    Small,
    Medium,
    Large
};

class Gift : public Mishloach
{
private:
    string giftName;    // �� �����
    double giftPrice;   // ���� �����
    GiftSize giftSize;  // ���� �����

public:
    Gift();
    Gift(string name, double price, GiftSize size, string sender, string recipient, Address address);

    // ������� ������� ������ �����
    //double CalPrice() const override;
   

    //// �������� ���� (Getters)
    //string GetGiftName() const;
    GiftSize GetGiftSize() const;

    //// �������� ����� (Setters)
    //void SetGiftName(const string& name);
    //void SetGiftPrice(double price);
    //void SetGiftSize(GiftSize size);

    //// ������� ������ ���� �����
    void PrintGiftDetails() const;

};


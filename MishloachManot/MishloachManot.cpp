#include <iostream>
#include "Mishloach.h"
#include "Gift.h"

int main()
{
	// יצירת מוצרים
	Product p1("cake", 20.0, 2, badats);
	Product p2("cookies", 10.0, 5, badats);
	Product p3("wine", 50.0, 1, rubin);
	Product p4("candy", 15.0, 3, badats);

	// יצירת כתובות
	Address a1("bb", "chazon hish", "14");
	Address a2("modiin ilit", "chfez chaim", "45");
	Address a3("jerusalem", "king george", "10");

	// יצירת משלוחי מנות רגילים
	Mishloach m1("Shlomo", "Shimon", a1);
	Mishloach m2("chavi", "st", a2);
	m1.AddProduct(p1);
	m2.AddProduct(p2);
	m2.AddProduct(p4);

	// יצירת משלוחי מנות עם מתנה
	Gift g1("Flowers", 100.0, Large, "David", "Sarah", a3);
	g1.AddProduct(p3);
	Gift g2("Chocolate Box", 30.0, Small, "Moshe", "Rachel", a1);
	g2.AddProduct(p1);
	Gift g3("Wine Set", 80.0, Large, "Yossi", "Miriam", a2);
	g3.AddProduct(p4);

	// מערכים נפרדים למשלוחים רגילים ולמתנות
	Mishloach arrMishloach[10];
	arrMishloach[0] = m1;
	arrMishloach[1] = m2;
	int mishloachSize = 2;

	Gift arrGifts[10];
	arrGifts[0] = g1;
	arrGifts[1] = g2;
	arrGifts[2] = g3;
	int giftsSize = 3;

	// ============================================
	// משימה 2: הדפסת כל פרטי משלוחי המנות
	// ============================================
	cout << "========================================" << endl;
	cout << "2. All Mishloach Manot Details:" << endl;
	cout << "========================================" << endl;
	
	// הדפסת משלוחים רגילים
	for (int i = 0; i < mishloachSize; i++)
	{
		cout << "--- Mishloach #" << (i + 1) << " ---" << endl;
		arrMishloach[i].Print();
		cout << "Total Price: " << arrMishloach[i].CalPrice() << endl;
		cout << endl;
	}
	
	// הדפסת משלוחים עם מתנה
	for (int i = 0; i < giftsSize; i++)
	{
		cout << "--- Gift #" << (i + 1) << " ---" << endl;
		arrGifts[i].Print();
		arrGifts[i].PrintGiftDetails();
		cout << "Total Price: " << arrGifts[i].CalPrice() << endl;
		cout << endl;
	}

	// ============================================
	// משימה 3: ממוצע מחיר של משלוח מנות עם מתנה
	// ============================================
	double sumGifts = 0;
	
	// סוכמים את כל המחירים של המתנות
	for (int i = 0; i < giftsSize; i++)
	{
		sumGifts += arrGifts[i].CalPrice();
	}
	
	cout << "========================================" << endl;
	cout << "3. Average Price of Gifts:" << endl;
	cout << "========================================" << endl;
	if (giftsSize > 0)
	{
		cout << "Total gifts: " << giftsSize << endl;
		cout << "Sum of prices: " << sumGifts << endl;
		cout << "Average: " << (sumGifts / giftsSize) << endl;
	}
	else
	{
		cout << "No gifts found" << endl;
	}
	cout << endl;

	// ============================================
	// משימה 4: כמה מתנות גדולות (Large) קיימות
	// ============================================
	int largeCount = 0;
	
	// עוברים על כל המתנות וסופרים כמה Large
	for (int i = 0; i < giftsSize; i++)
	{
		if (arrGifts[i].GetGiftSize() == Large)
		{
			largeCount++;
		}
	}
	
	cout << "========================================" << endl;
	cout << "4. Number of Large Gifts:" << endl;
	cout << "========================================" << endl;
	cout << "Large gifts count: " << largeCount << endl;
	cout << endl;

	// ============================================
	// משימה 6: עלות העיצוב של המשלוח
	// ============================================
	//cout << "========================================" << endl;
	//cout << "6. Design Price:" << endl;
	//cout << "========================================" << endl;
	//cout << "Design Price: " << Mishloach::GetDesignPrice() << endl;
	//cout << endl;

	// ============================================
	// משימה 7: כמה משלוחים כל מוצריהם בהכשר בד"ץ
	// ============================================
	int badatsCount = 0;
	
	// בודקים משלוחים רגילים
	for (int i = 0; i < mishloachSize; i++)
	{
		if (arrMishloach[i].IsSameKashrut(badats))
		{
			badatsCount++;
		}
	}
	
	// בודקים משלוחים עם מתנה
	for (int i = 0; i < giftsSize; i++)
	{
		if (arrGifts[i].IsSameKashrut(badats))
		{
			badatsCount++;
		}
	}
	
	cout << "========================================" << endl;
	cout << "7. Mishloachim with All Badats Products:" << endl;
	cout << "========================================" << endl;
	cout << "Count: " << badatsCount << endl;
	cout << endl;

	return 0;
}

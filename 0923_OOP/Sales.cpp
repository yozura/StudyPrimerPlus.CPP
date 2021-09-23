#include <iostream>
#include "Sales.h"

SALES::Sales::Sales()
{
	using namespace std;

	double total = 0;
	for (int i = 0; i < QUARTERS; i++) 
	{
		cout << "#" << i + 1 << "�б� �Ǹž�: ";
		cin >> sales[i];
		total += sales[i];
	}

	double tempMax = sales[0];
	double tempMin = sales[0];
	for (int i = 1; i < QUARTERS; i++)
	{
		if (sales[i] > max)
			tempMax = sales[i];
		if (sales[i] < min)
			tempMin = sales[i];
	}

	average = total / QUARTERS;
	max = tempMax;
	min = tempMin;
}

SALES::Sales::Sales(const double ar[], int n)
{
	using namespace std;

	int numbers = n < QUARTERS ? n : QUARTERS;
	for (int i = 0; i < QUARTERS; i++)
		sales[i] = 0;

	double total = 0;
	for (int i = 0; i < numbers; i++)
	{
		sales[i] = ar[i];
		total += sales[i];
	}
	
	double tempMax = sales[0];
	double tempMin = sales[0];
	for (int i = 1; i < numbers; i++)
	{
		if (sales[i] > max)
			tempMax = sales[i];
		if (sales[i] < min)
			tempMin = sales[i];
	}

	average = total / numbers;
	max = tempMax;
	min = tempMin;
}

void SALES::Sales::showSales() const
{
	using namespace std;
	
	cout << "\n<�Ǹž� ����>\n";
	for (int i = 0; i < QUARTERS; i++)
		cout << "#" << i + 1 << "�б� �Ǹž�: $" << sales[i] << '\n';

	cout << "��հ�: " << average << '\n';
	cout << "�ִ밪: " << max << '\n';
	cout << "�ּҰ�: " << min << '\n';
}

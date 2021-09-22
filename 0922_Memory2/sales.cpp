#include <iostream>
#include "sales.h"

namespace SALES
{
	void setSales(Sales& s, const double ar[], int n)
	{
		for (int i = 0; i < QUARTERS; i++)
			s.sales[i] = 0;

		int numbers = n < QUARTERS ? n : QUARTERS;
		double total = 0;
		for (int i = 0; i < numbers; i++)
		{
			s.sales[i] = ar[i];
			total += s.sales[i];
		}

		double max = s.sales[0];
		double min = s.sales[0];
		for (int i = 0; i < numbers; i++)
		{
			if (s.sales[i] > max)
				max = s.sales[i];
			if (s.sales[i] < min)
				min = s.sales[i];
		}

		s.average = total / numbers;
		s.max = max;
		s.min = min;
	}

	void setSales(Sales& s)
	{
		double total = 0;
		for (int i = 0; i < QUARTERS; i++)
		{
			std::cout << "#" << i + 1 << "�б� �Ǹž�: ";
			std::cin >> s.sales[i];
			total += s.sales[i];
		}

		double max = s.sales[0];
		double min = s.sales[0];
		for (int i = 0; i < QUARTERS; i++)
		{
			if (s.sales[i] > max)
				max = s.sales[i];
			if (s.sales[i] < min)
				min = s.sales[i];
		}
		
		s.average = total / QUARTERS;
		s.max = max;
		s.min = min;
	}

	void showSales(const Sales& s)
	{
		std::cout << "\n<����ü ����>\n";

		for (int i = 0; i < QUARTERS; i++)
			std::cout << "#" << i + 1 << "�б� �Ǹž�: " << s.sales[i] << std::endl;

		std::cout << "�ִ밪: " << s.max << "\n";
		std::cout << "�ּҰ�: " << s.min << "\n";
		std::cout << "��հ�: " << s.average << "\n\n";
	}
}
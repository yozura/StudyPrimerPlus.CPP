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
			std::cout << "#" << i + 1 << "분기 판매액: ";
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
		std::cout << "\n<구조체 내역>\n";

		for (int i = 0; i < QUARTERS; i++)
			std::cout << "#" << i + 1 << "분기 판매액: " << s.sales[i] << std::endl;

		std::cout << "최대값: " << s.max << "\n";
		std::cout << "최소값: " << s.min << "\n";
		std::cout << "평균값: " << s.average << "\n\n";
	}
}
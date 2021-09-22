#include <iostream>
#include "sales.h"

int main()
{
	using SALES::Sales;

	Sales one;
	Sales two;

	double arr[4] = { 1.5, 2.1, 3.5, 5.0 };
	SALES::setSales(one, arr, 3);
	SALES::showSales(one);

	SALES::setSales(two);
	SALES::showSales(two);

	return 0;
}

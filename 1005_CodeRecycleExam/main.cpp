#include <iostream>
#include "wine.h"

using namespace std;

int main()
{
	cout << "���� �̸��� �Է��Ͻʽÿ�: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "��Ȯ �⵵ ������ �Է��Ͻÿ�: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << more.Label() << " ��ü ����:" << more.sum() << endl;
	cout << "���α׷��� �����մϴ�.";

	return 0;
}

void useValArrayContainment()
{
	cout << "���� �̸��� �Է��Ͻʽÿ�: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "��Ȯ �⵵ ������ �Է��Ͻÿ�: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YRS, y, b);
	more.Show();
	cout << more.Label() << " ��ü ����:" << more.sum() << endl;
	cout << "���α׷��� �����մϴ�.";
}
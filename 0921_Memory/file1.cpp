#include <iostream>
#include "coordin.h"

using namespace std;

void recttopolar()
{
	rect rplace;
	polar pplace;

	cout << "x���� y���� �Է��Ͻʽÿ�: ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "x���� y���� �Է��Ͻʽÿ� (�������� q�� �Է�) : ";
	}
	cout << "���α׷��� �����մϴ�.\n";
}
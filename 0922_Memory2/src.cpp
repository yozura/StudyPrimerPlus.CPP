#include <iostream>

using namespace std;

double warming = 0.3;

void update(double dt);
void local();

void src()
{
	cout << "���� warming�� " << warming << "���Դϴ�.\n";
	update(0.1); // warming�� �����ϴ� �Լ��� ȣ��
	cout << "���� warming�� " << warming << "���Դϴ�.\n";
	local(); // ���� warming���� �Լ��� ȣ��
	cout << "���� warming�� " << warming << "���Դϴ�.\n";
}
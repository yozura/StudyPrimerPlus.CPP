#pragma once
#include <iostream>
#include <climits>
#include <cctype>

using namespace std;

bool is_int(double);
void showmenu();
void report();
void comfort();

const int Max = 5;
const int Fave = 27;
const int ArSize = 80;
const char* qualify[4] =
{
	"������ �޸���",
	"�𷡻��� ����",
	"��ġ �߸�",
	"�θ޶� ������"
};

enum { red, orange, yellow, green, blue, violet, indigo };

void showmenu()
{
	cout << "1, 2, 3, 4, 5�� �߿��� �ϳ��� �����Ͻʽÿ�:\n";
	cout << "1) �����			2) ����\n";
	cout << "3) �˸�����			4) �ݷ���\n";
	cout << "5) ����\n";
}

void report()
{
	cout << "�̹� �б�� �濵 ������ ���� �����ϴ�.\n";
	cout << "�Ǹŷ��� 120% �þ��, ����� 35% �پ����ϴ�.\n";
}

void comfort()
{
	cout << "������� ����� ���� �ְ��� CEO��� �����ϰ� �ֽ��ϴ�.\n";
	cout << "�̻�ȸ�� ����� ���� �ְ��� CEO��� �����ϰ� �ֽ��ϴ�.\n";
}

bool is_int(double x)
{
	if (x <= INT_MAX && x >= INT_MIN)
		return true;
	else
		return false;
}
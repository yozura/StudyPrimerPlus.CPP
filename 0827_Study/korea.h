#pragma once
#include <iostream>
#include <cmath>

using namespace std;

void exam01()
{
	cout << "�� �̸��� �̿����̾�" << endl;
	cout << "�׸��� �� �ּҴ� ü�������̾�";
}

void exam02()
{
	int mile;
	cout << "�̵� �Ÿ��� �Է��ϼ���(����) : ";
	cin >> mile;
	
	cout << mile << "������ " << mile * 1.60934 << "km�Դϴ�.";
}

void tbm()
{
	cout << "Three blind mice" << endl;
}

void shtr()
{
	cout << "See how they run\n";
}

void exam03()
{
	tbm();
	tbm();
	shtr();
	shtr();
}

void exam04()
{
	int age;
	cout << "Enter your age: ";
	cin >> age;

	cout << "����� ���̸� ���� ȯ���ϸ� " << age * 12 << "�Դϴ�.";
}

double celtofa(double cel)
{
	return 1.8 * cel + 32.0;
}

void exam05()
{
	double celsius;
	cout << "���� �µ��� �Է��ϰ� Enter�� ��������: ";
	cin >> celsius;

	cout << "���� " << celsius << "���� ȭ���� " << celtofa(celsius) << "���Դϴ�.";
}

double lytoau(double ly)
{
	return ly * 63240;
}

void exam06()
{
	double lightYear;
	cout << "���� ���� �Է��ϰ� Enter�� ��������: ";
	cin >> lightYear;

	cout << lightYear << " ������ " << lytoau(lightYear) << " õ�� �����Դϴ�.";
}

void timer(int hour, int minute)
{
	cout << "�ð�: " << hour << ":" << minute;
}

void exam07()
{
	int hour, minute;
	cout << "�ð� ���� �Է��Ͻÿ�: ";
	cin >> hour;
	cout << "�� ���� �Է��Ͻÿ�: ";
	cin >> minute;

	timer(hour, minute);
}
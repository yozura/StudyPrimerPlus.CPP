#pragma once
#include <iostream>
#include <climits>
#include <cmath>

#define ZERO 0

using namespace std;

void exam7()
{
	double gas_E;
	
	cout << "100ų�ι��ʹ� ���� ���� �Է��ϼ��� : ";
	cin >> gas_E;
	
	double gas_U = (1 / gas_E) * (62.14 * 3.875);
	
	cout << "������ ������ ���� ���� : " << gas_U << "�Դϴ�.";
}

void exam6()
{
	double km, liter;
	double answer;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "���� �Ÿ��� �Է��ϼ���(ų�ι���) : ";
	cin >> km;
	cout << "�Һ��� ���ᷮ�� �Է��ϼ���(����) : ";
	cin >> liter;

	cout << "������ 100ų�ι��ʹ� ���� ���� : " << (km / liter) * 100 << "�Դϴ�.";
}

void exam5()
{	
	long long america, global;
	long double rate = 0.0;
	cout.setf(ios_base::fixed, ios_base::floatfield);

	cout << "���� �α����� �Է��Ͻÿ� : ";
	cin >> global;
	cout << "�̱��� �α����� �Է��Ͻÿ� : ";
	cin >> america;

	rate = (double)america / (double)global * 100;

	cout << "���� �α������� �̱��� �����ϴ� ������ " << rate << "%�̴�.";
}

void exam4()
{
	const int DAY_HOUR = 24;
	const int HOUR_MIN = 3600;
	const int MIN_SEC = 60;
	long input_sec;
	int day, hour, min, sec;
	cout << "�� ���� �Է��Ͻÿ�: ";
	cin >> input_sec;

	sec = input_sec;

	day = sec / 86400;
	sec = sec % 86400;
	hour = sec / HOUR_MIN;
	sec = sec % HOUR_MIN;
	min = sec / MIN_SEC;
	sec = sec % MIN_SEC;

	cout << input_sec << "�� = ";
	cout << day << "��, " << hour << "�ð�, " << min << "��, " << sec << "��";
}

void exam3()
{
	const double TEMP_ONE = 60;
	const double TEMP_TWO = 60;
	double hour, min, sec;
	double latitude;

	cout << "������ ��, ��, �� ������ �Է��ϼ���.\n";
	cout << "����, ������ �Է��Ͻÿ�: ";
	cin >> hour;
	cout << "������, �а��� �Է��Ͻÿ�: ";
	cin >> min;
	cout << "������, �ʰ��� �Է��Ͻÿ�: ";
	cin >> sec;
	
	latitude = hour + ((min + (sec / TEMP_TWO)) / TEMP_ONE);
	
	cout << hour << "��, " << min << "��, " << sec << "�� = " << latitude << "��";
}

void exam2()
{
	const int TWELVE = 12;
	const double METER = 0.0254;
	const float GRAM = 2.2f;

	double feet, inch, founds, bmi, height;

	cout << "����� ��Ʈ�� �Է��ϼ��� : ";
	cin >> feet;
	cout << "����� ��ġ�� �Է��ϼ��� : ";
	cin >> inch;
	cout << "����� �Ŀ�带 �Է��ϼ��� : ";
	cin >> founds;
	
	inch = inch + (feet * TWELVE);
	height = inch * METER;
	founds /= GRAM;
	bmi = founds / (height * height);
	cout << height << endl;

	cout << "����� bmi ��ġ�� : " << bmi << "�Դϴ�.";
}

void exam1()
{
	const int THAT { 100 };
	int height, meter, cmeter;

	cout << "����� Ű�� �Է��ϼ���(cm) : ___\b\b\b";
	cin >> height;

	meter = height / THAT;
	cmeter = height % THAT;
	
	cout << "����� Ű�� " << meter << "m " << cmeter << "cm �Դϴ�.";
}
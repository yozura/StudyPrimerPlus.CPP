#pragma once
#include <iostream>
#include <cmath>

using namespace std;

void exam01()
{
	cout << "내 이름은 이왕훈이야" << endl;
	cout << "그리고 내 주소는 체육공원이야";
}

void exam02()
{
	int mile;
	cout << "이동 거리를 입력하세요(마일) : ";
	cin >> mile;
	
	cout << mile << "마일은 " << mile * 1.60934 << "km입니다.";
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

	cout << "당신의 나이를 월로 환산하면 " << age * 12 << "입니다.";
}

double celtofa(double cel)
{
	return 1.8 * cel + 32.0;
}

void exam05()
{
	double celsius;
	cout << "섭씨 온도를 입력하고 Enter를 누르세요: ";
	cin >> celsius;

	cout << "섭씨 " << celsius << "도는 화씨로 " << celtofa(celsius) << "도입니다.";
}

double lytoau(double ly)
{
	return ly * 63240;
}

void exam06()
{
	double lightYear;
	cout << "광년 수를 입력하고 Enter를 누르세요: ";
	cin >> lightYear;

	cout << lightYear << " 광년은 " << lytoau(lightYear) << " 천문 단위입니다.";
}

void timer(int hour, int minute)
{
	cout << "시각: " << hour << ":" << minute;
}

void exam07()
{
	int hour, minute;
	cout << "시간 값을 입력하시오: ";
	cin >> hour;
	cout << "분 값을 입력하시오: ";
	cin >> minute;

	timer(hour, minute);
}
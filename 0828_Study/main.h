#pragma once
#include <iostream>
#include <climits>
#include <cmath>

#define ZERO 0

using namespace std;

void exam7()
{
	double gas_E;
	
	cout << "100킬로미터당 리터 수를 입력하세요 : ";
	cin >> gas_E;
	
	double gas_U = (1 / gas_E) * (62.14 * 3.875);
	
	cout << "고객님의 갤런당 마일 수는 : " << gas_U << "입니다.";
}

void exam6()
{
	double km, liter;
	double answer;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "주행 거리를 입력하세요(킬로미터) : ";
	cin >> km;
	cout << "소비한 연료량을 입력하세요(리터) : ";
	cin >> liter;

	cout << "고객님의 100킬로미터당 리터 수는 : " << (km / liter) * 100 << "입니다.";
}

void exam5()
{	
	long long america, global;
	long double rate = 0.0;
	cout.setf(ios_base::fixed, ios_base::floatfield);

	cout << "세계 인구수를 입력하시오 : ";
	cin >> global;
	cout << "미국의 인구수를 입력하시오 : ";
	cin >> america;

	rate = (double)america / (double)global * 100;

	cout << "세계 인구수에서 미국이 차지하는 비중은 " << rate << "%이다.";
}

void exam4()
{
	const int DAY_HOUR = 24;
	const int HOUR_MIN = 3600;
	const int MIN_SEC = 60;
	long input_sec;
	int day, hour, min, sec;
	cout << "초 수를 입력하시오: ";
	cin >> input_sec;

	sec = input_sec;

	day = sec / 86400;
	sec = sec % 86400;
	hour = sec / HOUR_MIN;
	sec = sec % HOUR_MIN;
	min = sec / MIN_SEC;
	sec = sec % MIN_SEC;

	cout << input_sec << "초 = ";
	cout << day << "일, " << hour << "시간, " << min << "분, " << sec << "초";
}

void exam3()
{
	const double TEMP_ONE = 60;
	const double TEMP_TWO = 60;
	double hour, min, sec;
	double latitude;

	cout << "위도를 도, 분, 초 단위로 입력하세요.\n";
	cout << "먼저, 도각을 입력하시오: ";
	cin >> hour;
	cout << "다음에, 분각을 입력하시오: ";
	cin >> min;
	cout << "끝으로, 초각을 입력하시오: ";
	cin >> sec;
	
	latitude = hour + ((min + (sec / TEMP_TWO)) / TEMP_ONE);
	
	cout << hour << "도, " << min << "분, " << sec << "초 = " << latitude << "도";
}

void exam2()
{
	const int TWELVE = 12;
	const double METER = 0.0254;
	const float GRAM = 2.2f;

	double feet, inch, founds, bmi, height;

	cout << "당신의 피트를 입력하세요 : ";
	cin >> feet;
	cout << "당신의 인치를 입력하세요 : ";
	cin >> inch;
	cout << "당신의 파운드를 입력하세요 : ";
	cin >> founds;
	
	inch = inch + (feet * TWELVE);
	height = inch * METER;
	founds /= GRAM;
	bmi = founds / (height * height);
	cout << height << endl;

	cout << "당신의 bmi 수치는 : " << bmi << "입니다.";
}

void exam1()
{
	const int THAT { 100 };
	int height, meter, cmeter;

	cout << "당신의 키를 입력하세요(cm) : ___\b\b\b";
	cin >> height;

	meter = height / THAT;
	cmeter = height % THAT;
	
	cout << "당신의 키는 " << meter << "m " << cmeter << "cm 입니다.";
}
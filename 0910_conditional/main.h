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
	"만미터 달리기",
	"모래사장 씨름",
	"비치 발리",
	"부메랑 던지기"
};

enum { red, orange, yellow, green, blue, violet, indigo };

void showmenu()
{
	cout << "1, 2, 3, 4, 5번 중에서 하나를 선택하십시오:\n";
	cout << "1) 경고음			2) 보고서\n";
	cout << "3) 알리바이			4) 격려사\n";
	cout << "5) 종료\n";
}

void report()
{
	cout << "이번 분기는 경영 실적이 아주 좋습니다.\n";
	cout << "판매량은 120% 늘어났고, 비용은 35% 줄었습니다.\n";
}

void comfort()
{
	cout << "사원들은 당신을 업계 최고의 CEO라고 생각하고 있습니다.\n";
	cout << "이사회도 당신을 업계 최고의 CEO라고 생각하고 있습니다.\n";
}

bool is_int(double x)
{
	if (x <= INT_MAX && x >= INT_MIN)
		return true;
	else
		return false;
}
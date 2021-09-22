#include <iostream>

using namespace std;

double warming = 0.3;

void update(double dt);
void local();

void src()
{
	cout << "전역 warming은 " << warming << "도입니다.\n";
	update(0.1); // warming을 갱신하는 함수를 호출
	cout << "전역 warming은 " << warming << "도입니다.\n";
	local(); // 지역 warming으로 함수를 호출
	cout << "전역 warming은 " << warming << "도입니다.\n";
}
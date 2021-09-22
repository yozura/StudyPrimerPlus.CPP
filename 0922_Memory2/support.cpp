#include <iostream>

extern double warming; // 다른 파일로부터 warming 사용

void update(double dt);
void local();

using std::cout;

void update(double dt)
{
	extern double warming; // 선택적 재선언
	warming += dt; // 전역 warming 사용
	cout << "전역 warming이 " << warming << "도로 갱신되었습니다.\n";
}

void local()
{
	double warming = 0.8; // 새 변수로 외부 변수 warming을 가림.
	cout << "지역 warming은 " << warming << "도입니다.\n";
	cout << "그러나, 전역 warming은 " << ::warming;
	cout << "도입니다.\n";
}

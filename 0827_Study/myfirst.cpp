#include "korea.h"

void simon(int);
int stonetolb(int);

int main()
{
	exam07();
	return 0;
}

int convert()
{
	int stone;
	cout << "체중을 스톤 단위로 입력하시오: ";
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << " 스톤은 ";
	cout << pounds << " 파운드입니다." << endl;

	return 0;
}

int stonetolb(int sts)
{
	return 14 * sts;
}

int ourfunc()
{
	simon(3);
	cout << "정수를 하나 고르시오: ";
	int count;
	cin >> count;
	simon(count);
	cout << "끝!" << endl;
	return 0;
}

void simon(int n)
{
	cout << "Simon 왈, 발가락을 " << n << "번 두드려라." << endl;
}

int sqrt()
{
	double area;
	cout << "마루 면적을 평방피트 단위로 입력하시오: ";
	cin >> area;
	double side;
	side = sqrt(area);
	cout << "사각형 마루라면 한 변이 " << side << "피트에 상당합니다." << endl;
	cout << "멋지네요!" << endl;

	return 0;
}

int getinfo()
{
	int carrots;

	cout << "당근을 몇 개나 가지고 있니?" << endl;
	cin >> carrots;
	cout << "여기 두 개가 더 있다.";
	carrots = carrots + 2;

	cout << "이제 당근은 모두 " << carrots << "개이다." << endl;
	return 0;
}

int carrots()
{
	int carrots;

	carrots = 25;
	cout << "나는 당근을 ";
	cout << carrots;
	cout << "개 가지고 있다.";
	cout << endl;
	carrots = carrots - 1;
	cout << "아삭아삭, 이제 당근은 " << carrots << "개이다." << endl;
	return 0;
}

int myfirst()
{
	cout << "C++의 세계로 오십시오.";
	cout << endl;
	cout << "후회하지 않으실 겁니다!" << endl;
	return 0;
}
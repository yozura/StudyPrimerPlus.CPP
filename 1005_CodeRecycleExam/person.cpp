#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include "person.h"

using namespace std;

void Person::Data() const
{
	cout << fname << ", " << lname << '\n';
}

void Person::Show() const
{
	Data();
}

void Gunslinger::Data() const
{
	cout << "총 기스: " << notch << '\n';
}

void Gunslinger::Show() const
{
	Person::Data();
	Data();
}

double Gunslinger::Draw()
{
	// 함수 정의 안에서 난수를 어떻게 해야할까 고민해봐야할 문제...
	double r = (double)(rand()) / ((double)(RAND_MAX / 3));
	r = (double)(rand()) / ((double)(RAND_MAX / 3));
	return r;
}

void PokerPlayer::Data() const
{
}

void PokerPlayer::Show() const
{
	Person::Data();
	Data();
}

int PokerPlayer::Draw()
{
	// 놀랍게도 이거는 정상 작동한다!
	return (rand() * 52 / (RAND_MAX)) + 1;
}

double BadDude::Gdraw()
{
	return Gunslinger::Draw();
}

int BadDude::Cdraw()
{
	return PokerPlayer::Draw();
}

void BadDude::Data() const
{
}

void BadDude::Show() const
{
	Person::Data();
	Gunslinger::Data();
	PokerPlayer::Data();
	Data();
}

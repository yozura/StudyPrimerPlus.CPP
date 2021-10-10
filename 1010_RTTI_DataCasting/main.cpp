#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include "rtti1.h"

using namespace std;

void change(const int* pt, int n);

int main()
{
	int pop1 = 38383;
	const int pop2 = 2000;

	cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;
	change(&pop1, -103);
	change(&pop2, -103);
	cout << "pop1, pop2: " << pop1 << ", " << pop2 << endl;

	return 0;
}

void change(const int* pt, int n)
{
	int* pc;
	pc = const_cast<int*>(pt);
	*pc += n;
}

void useConstCast()
{

}

Grand* GetOne()
{
	Grand* p;
	switch (rand() % 3)
	{
	case 0: p = new Grand(rand() % 100); break;
	case 1: p = new Superb(rand() % 100); break;
	case 2: p = new Magnificent(rand() % 100, 'A' + rand() % 26); break;
	default: p = new Grand(rand() % 100); break;
	}

	return p;
}

void useTypeid()
{
	srand(time(0));
	Grand* pg;
	Superb* ps;
	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		cout << "지금 " << typeid(*pg).name() << "형을 처리하고 있습니다.\n";
		pg->Speak();
		if (ps = dynamic_cast<Superb*>(pg))
			ps->Say();
		if (typeid(Magnificent) == typeid(*pg))
			cout << "그래, 너야말로 진짜 Magnificent 클래스이다.\n";
	}
}

void useRTTI_dynamic_cast()
{
	srand(time(0));
	Grand* pg;
	Superb* ps;
	for (int i = 0; i < 5; i++)
	{
		pg = GetOne();
		pg->Speak();
		if (ps = dynamic_cast<Superb*>(pg))
			ps->Say();
	}
}
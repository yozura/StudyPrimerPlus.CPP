#include <iostream>
#include "wine.h"

using namespace std;

Wine::Wine()
	: string("No Name"), year(0), PairArray(ArrayInt(0), ArrayInt(0))
{
}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	: string(l), year(y), PairArray(ArrayInt(y), ArrayInt(y))
{
	for (int i = 0; i < year; i++)
	{
		PairArray::first()[i] = yr[i];
		PairArray::second()[i] = bot[i];
	}
}

Wine::Wine(const char* l, int y)
	: string(l), year(y), PairArray(ArrayInt(y), ArrayInt(y))
{
}

void Wine::GetBottles()
{
	for (int i = 0; i < year; i++)
	{
		std::cout << "년도 입력: ";
		std::cin >> PairArray::first()[i];
		std::cout << "수량 입력: ";
		std::cin >> PairArray::second()[i];

		while (std::cin.get() != '\n')
			continue;
	}
}

const std::string& Wine::Label() const
{
	return (const string&)*this;
}

int Wine::sum() const
{
	int total = 0;
	for (int i = 0; i < year; i++)
		total += PairArray::second()[i];

	return total;
}

void Wine::Show() const
{
	std::cout << "와인: " << (const string&)*this << '\n';
	std::cout << "\t년도\t수량\n";
	for (int i = 0; i < year; i++)
	{
		std::cout << "\t" << PairArray::first()[i];
		std::cout << "\t" << PairArray::second()[i] << '\n';
	}
}

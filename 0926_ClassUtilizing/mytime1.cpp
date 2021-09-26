#include <iostream>
#include "mytime1.h"

Tim::Tim()
{
    hours = minutes = 0;
}

Tim::Tim(int h, int m)
{
	if (m >= 60)
	{
		hours = h + m / 60;
		minutes = m % 60;
	}
	else
	{
		hours = h;
		minutes = m;
	}
}

void Tim::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Tim::AddHr(int h)
{
	hours += h;
}

void Tim::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Tim Tim::operator+(const Tim& t) const
{
	Tim sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

void Tim::show() const
{
	std::cout << hours << "½Ã°£, " << minutes << "ºĞ";
}

#include <iostream>
#include "mytime2.h"

Tm::Tm()
{
    hours = minutes = 0;
}

Tm::Tm(int h, int m)
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

void Tm::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Tm::AddHr(int h)
{
	hours += h;
}

void Tm::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Tm Tm::operator+(const Tm& t) const
{
	Tm sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

Tm Tm::operator-(const Tm& t) const
{
	Tm diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.minutes = (tot2 - tot1) % 60;
	diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Tm Tm::operator*(double n) const
{
	Tm result;
	long totalminutes = hours * n * 60 + minutes * n;
	result.hours = totalminutes / 60; // ���� �ð����� ȯ��
	result.minutes = totalminutes % 60; // ���� �ð����� ȯ���� ���� �������� ����
    return result;
}

std::ostream& operator<<(std::ostream& os, const Tm& t)
{
	// private ��� �����鵵 ����� �����ϴ�. friend �Լ�������!
	os << t.hours << "�ð�, " << t.minutes << "��";
	return os;
}

void Tm::show() const
{
	std::cout << hours << "�ð�, " << minutes << "��";
}

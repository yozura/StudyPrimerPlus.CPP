#include <iostream>
#include <cmath>
#include "vect.h"
using std::sqrt;
using std::atan;
using std::atan2;
using std::sin;
using std::cos;
using std::cout;

namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);

	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POLAR)
		{
			x = n1 * cos(n2);
			y = n1 * sin(n2);
		}
		else
		{
			cout << "Vector()�� ���޵� �� 3�� �Ű������� �߸��Ǿ���.\n";
			cout << "�׷��� ���͸� 0���� �����Ͽ���.\n";
			x = y = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
		}
		else if (form == POLAR)
		{
			x = n1 * cos(n2);
			y = n1 * sin(n2);
		}
		else
		{
			cout << "Vector()�� ���޵� �� 3�� �Ű������� �߸��Ǿ���.\n";
			cout << "�׷��� ���͸� 0���� �����Ͽ���.\n";
			x = y = 0.0;
			mode = RECT;
		}
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	void Vector::polar_mode()
	{
		mode = POLAR;
	}

	Vector Vector::operator+(const Vector& v) const
	{
		return Vector(x + v.x, y + v.y);
	}

	Vector Vector::operator-(const Vector& v) const
	{
		return Vector(x - v.x, y - v.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	Vector Vector::operator*(double n) const
	{
		return Vector(x * n, y * n);
	}

	Vector operator*(double n, const Vector& v)
	{
		return v * n;
	}

	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
			os << "(x, y) = (" << v.x << ", " << v.y << ")\n";
		else if (v.mode == Vector::POLAR)
			os << "(m, g) = (" << v.magval() << ", " << v.angval() * Rad_to_deg << ")\n";
		else
			os << "Vector ��ü�� ��� ������ Ʋ�Ƚ��ϴ�.\n";
		return os;
	}
}
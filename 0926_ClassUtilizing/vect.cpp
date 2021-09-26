#include <iostream>
#include <cmath>
#include "vect.h"

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	// 1 ���� ���� ������ ����Ͽ��� (1 ���ȿ� ���� degree ���� ���)
	const double Rad_to_deg = 45.0 / atan(1.0);
	// arctan(1.0) = (pi / 4)(Rad), �� 45���� �ǹ��ϰ�
	// 45.0 / arctan(1.0) = 1Rad, �� 57.2957795421...���� �ǹ��Ѵ�.
	// Rad_to_deg = rad * 180 / PI �� ���� �� ����. rad�� �˰� ���� ��
	// Deg_to_rad = deg * PI / 180 �� ���� �� ����. deg�� �˰� ���� ��

	// x���� y������ ũ��, ������ ����
	void Vector::set_mag()
	{
		// ��Ÿ����� ������ �̿��ؼ� ������ ����(������ ũ��)�� ����.
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		// x, y���� 0���� ��� ���� 0��
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x); // ��ũź��Ʈ�� x���� y���� �������� ���Ѵ�.
	}

	// ũ��, ������ x, y���� ����
	void Vector::set_x()
	{
		// ������ǥ x ���ϴ� ����
		// x = R(�Ÿ�)*cos(����);
		x = mag * cos(ang);
	}

	void Vector::set_y()
	{
		// ������ǥ y ���ϴ� ����
		// y = R(�Ÿ�)*sin(����);
		y = mag * sin(ang);
	}

	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}

	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POLAR)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Vector()�� ���޵� �� 3�� �Ű������� �߸��Ǿ���.\n";
			cout << "�׷��� ���͸� 0���� �����Ͽ���.\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POLAR)
		{
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else
		{
			cout << "Vector()�� ���޵� �� 3�� �Ű������� �߸��Ǿ���.\n";
			cout << "�׷��� ���͸� 0���� �����Ͽ���.\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{
	}

	void Vector::polar_mode()
	{
		mode = POLAR;
	}

	void Vector::rect_mode()
	{
		mode = RECT;
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
		return Vector(n * x, n * y);
	}

	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}

	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		// TODO: ���⿡ return ���� �����մϴ�.
		if (v.mode == Vector::RECT)
			os << "(x, y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POLAR)
			os << "(m, g) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
		else
			os << "Vector ��ü�� ��� ������ Ʋ�Ƚ��ϴ�.\n";
		return os;
	}
}
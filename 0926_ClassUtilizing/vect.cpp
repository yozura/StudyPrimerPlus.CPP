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
	// 1 라디안 내의 각도를 계산하여라 (1 라디안에 대한 degree 값을 계산)
	const double Rad_to_deg = 45.0 / atan(1.0);
	// arctan(1.0) = (pi / 4)(Rad), 즉 45도를 의미하고
	// 45.0 / arctan(1.0) = 1Rad, 즉 57.2957795421...도를 의미한다.
	// Rad_to_deg = rad * 180 / PI 로 구할 수 있음. rad를 알고 있을 때
	// Deg_to_rad = deg * PI / 180 로 구할 수 있음. deg를 알고 있을 때

	// x값과 y값으로 크기, 각도를 구함
	void Vector::set_mag()
	{
		// 피타고라스의 정리를 이용해서 빗변의 길이(벡터의 크기)를 구함.
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		// x, y값이 0도일 경우 각도 0도
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x); // 아크탄젠트는 x분의 y값을 라디안으로 구한다.
	}

	// 크기, 각도로 x, y값을 구함
	void Vector::set_x()
	{
		// 직교좌표 x 구하는 공식
		// x = R(거리)*cos(각도);
		x = mag * cos(ang);
	}

	void Vector::set_y()
	{
		// 직교좌표 y 구하는 공식
		// y = R(거리)*sin(각도);
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
			cout << "Vector()에 전달된 제 3의 매개변수가 잘못되었다.\n";
			cout << "그래서 벡터를 0으로 설정하였다.\n";
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
			cout << "Vector()에 전달된 제 3의 매개변수가 잘못되었다.\n";
			cout << "그래서 벡터를 0으로 설정하였다.\n";
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
		// TODO: 여기에 return 문을 삽입합니다.
		if (v.mode == Vector::RECT)
			os << "(x, y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POLAR)
			os << "(m, g) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
		else
			os << "Vector 객체의 모드 지정이 틀렸습니다.\n";
		return os;
	}
}
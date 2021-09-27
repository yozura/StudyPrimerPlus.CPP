#pragma once
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <cmath>
namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode { RECT, POLAR };
	private:
		double x;
		double y;
		Mode mode;
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		~Vector();
		void reset(double n1, double n2, Mode form = RECT);
		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return sqrt(x * x + y * y); }
		double angval() const { return atan2(y, x); }
		void rect_mode();
		void polar_mode();
		Vector operator+(const Vector& v) const;
		Vector operator-(const Vector& v) const;
		Vector operator-() const;
		Vector operator*(double n) const;
		friend Vector operator*(double n, const Vector& v);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}
#endif


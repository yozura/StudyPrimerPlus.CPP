#include "complex0.h"

complex::complex()
{
	real = imag = 0.0;
}

complex::complex(double n1, double n2)
{
	real = n1;
	imag = n2;
}

complex::~complex()
{
}

complex complex::operator+(const complex& comp) const
{
	return complex(real + comp.real, imag + comp.imag);
}

complex complex::operator-(const complex& comp) const
{
	return complex(real - comp.real, imag - comp.imag);
}

complex complex::operator*(const complex& comp) const
{
	return complex(real * comp.real - imag * comp.imag,
				   real * comp.imag + imag * comp.real);
}

complex complex::operator*(double n) const
{
	return complex(n * real, n * imag);
}

complex complex::operator~() const
{
	return complex(real, -imag);
}

complex operator*(double n, const complex& comp)
{
	return comp * n;
}

std::ostream& operator<<(std::ostream& os, const complex& comp)
{
	os << "(" << comp.real << ", " << comp.imag << "i)";
	return os;
}

std::istream& operator>>(std::istream& is, complex& comp)
{
	std::cout << "실수부: ";
	is >> comp.real;
	std::cout << "허수부: ";
	is >> comp.imag;
	return is;
}

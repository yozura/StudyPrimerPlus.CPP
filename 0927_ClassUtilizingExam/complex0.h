#pragma once
#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
class complex
{
private:
	double real;
	double imag;
public:
	complex();
	complex(double n1, double n2);
	~complex();
	complex operator+(const complex& comp) const;
	complex operator-(const complex& comp) const;
	complex operator*(const complex& comp) const;
	complex operator*(double n) const;
	complex operator~() const;
	friend complex operator*(double n, const complex& comp);
	friend std::ostream& operator<<(std::ostream& os, const complex& comp);
	friend std::istream& operator>>(std::istream& is, complex& comp);
};
#endif
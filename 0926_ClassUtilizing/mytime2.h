#pragma once
#ifndef MYTIME2_H_
#define MYTIME2_H_
#include <ostream>
class Tm
{
private:
	int hours;
	int minutes;
public:
	Tm();
	Tm(int h, int m);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Tm operator+(const Tm& t) const;
	Tm operator-(const Tm& t) const;
	Tm operator*(double n) const;
	friend Tm operator*(double m, const Tm& t) { return t * m; }
	friend std::ostream& operator<<(std::ostream& os, const Tm& t);
	void show() const;
};
#endif


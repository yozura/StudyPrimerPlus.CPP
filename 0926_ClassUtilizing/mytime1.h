#pragma once
#ifndef MYTIME1_H_
#define MYTIME1_H_
class Tim
{
private:
	int hours;
	int minutes;
public:
	Tim();
	Tim(int h, int m);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Tim operator+(const Tim& t) const;
	void show() const;
};
#endif
#include <iostream>
#include "Move.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}

Move Move::add(const Move& m) const
{
	double xx = this->x + m.x;
	double yy = this->y + m.y;

	return Move(xx, yy);
}

void Move::showMove() const
{
	using std::cout;
	cout << "(x, y) = " << "(" << x << ", " << y << ")\n";
}
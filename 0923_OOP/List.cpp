#include <iostream>
#include "List.h"

List::List(int num)
{
	max = num;
	items = new Atem[max];
	top = 0;
}

List::~List()
{
	delete[] items;
}

bool List::add(Atem atem)
{
	if (top < max)
	{
		items[top++] = atem;
		return true;
	}
	else
		return false;
}

bool List::isEmpty() const
{
	return top == 0;
}

bool List::isFull() const
{
	return top == max;
}

void List::visit(void(*pf)(Atem&))
{
	for (int i = 0; i < top; i++)
		pf(items[i]);
}

void List::show()
{
	for (int i = 0; i < top; i++)
		std::cout << i << "¹ø ÀÎµ¦½º: " << items[i] << '\n';
}

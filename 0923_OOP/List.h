#pragma once
#ifndef LIST_H_
#define LIST_H_

typedef double Atem;

class List
{
private:
	Atem* items;
	int top, max;
public:
	List(int num = 0);
	~List();
	bool add(Atem);
	bool isEmpty() const;
	bool isFull() const;
	void visit(void (*pf)(Atem&));
	void show();
};

#endif
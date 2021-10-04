#pragma once
#include <iostream>

template <typename T>
class HasFriend
{
private:
	T item;
	static int ct;
public:
	HasFriend(const T& i) : item(i) { ct++; }
	~HasFriend() { ct--; }
	friend void counts();
	friend void report(HasFriend<T>&);
};

template <typename T>
int HasFriend<T>::ct = 0;

void counts()
{
	std::cout << "int 카운트: " << HasFriend<int>::ct << "; ";
	std::cout << "double 카운트: " << HasFriend<double>::ct << std::endl;
}

void report(HasFriend<int>& hf)
{
	std::cout << "HasFriend<int>: " << hf.item << std::endl;
}

void report(HasFriend<double>& hf)
{
	std::cout << "HasFriend<double>: " << hf.item << std::endl;
}
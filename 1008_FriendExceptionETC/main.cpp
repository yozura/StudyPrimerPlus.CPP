#include <iostream>
#include "tv.h"

int main()
{
	

	return 0;
}

void useFriendClass()
{
	using std::cout;
	Tv s42;
	cout << "42\" TV�� �ʱ� ������:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\n42\" TV�� ����� ������:\n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n������ ��� �� 42\" TV�� ������:\n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" TV�� ������:\n";
	s58.settings();
}
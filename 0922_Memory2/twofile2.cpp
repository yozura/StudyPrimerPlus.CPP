#include <iostream>

extern int tom;
static int dick = 10;
int harry = 200;

void remote_access()
{
	using namespace std;
	cout << "remote_access()가 보고하는덴 세 변수의 주소:\n";
	cout << &tom << " = &tom, " << &dick << " = &dick, " << &harry << " = &harry\n";
}
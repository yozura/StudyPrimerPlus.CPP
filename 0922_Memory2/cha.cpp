#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <new>
#include <cstring>

const int BUF = 512;
const int N = 2;

char buffertemp[BUF];

struct chaff
{
	char dross[20];
	int slag;
};

void testing()
{
	chaff* cf = new (buffertemp) chaff[N];

	strcpy(cf[0].dross, "numberOne");
	cf[0].slag = 1;

	strcpy(cf[1].dross, "numberTwo");
	cf[1].slag = 2;

	for (int i = 0; i < N; i++)
	{
		std::cout << "dross : " << cf[i].dross << std::endl;
		std::cout << "slag : " << cf[i].slag << std::endl << std::endl;
	}

	std::cout << "&buffertemp = " << &buffertemp << std::endl;
	std::cout << "&cf[0] = " << &cf[0] << std::endl;
	std::cout << "&cf[1] = " << &cf[1] << std::endl;
}

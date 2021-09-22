#include "main.h"

int main()
{

	return 0;
}

void address()
{
	int donuts = 6;
	double cups = 4.5;

	cout << "donuts의 값 = " << donuts;
	cout << ", donuts의 주소 = " << &donuts << endl;

	cout << "cups의 값 = " << cups;
	cout << ", cups의 주소 = " << &cups << endl;
}

void arrstruc()
{
	inflatable guests[2] =
	{
		{"Bambi", 0.5, 21.99},
		{"Godzilla", 2000, 565.99},
	};

	cout << guests[0].name << "와 " << guests[1].name << "의 부피를 합하면\n";
	cout << guests[0].volume + guests[1].volume << "세제곱피트입니다.\n";
}

void assgn_st()
{
	inflatable bouquet =
	{
		"sunflowers",
		0.20,
		12.49
	};

	inflatable choice;

	cout << "bouquet: " << bouquet.name << " for $";
	cout << bouquet.price << endl;

	choice = bouquet;
	cout << "choice: " << choice.name << " for $";
	cout << choice.price << endl;
}

void structur()
{
	inflatable guest =
	{
		"Glorious Gloria",
		1.88,
		29.99
	};

	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	};

	cout << "지금 판매하고 있는 모형풍선은\n" << guest.name;
	cout << "와 " << pal.name << "입니다.\n";
	cout << "두 제품을 $";
	cout << guest.price + pal.price << "에 드리겠습니다!\n";

}
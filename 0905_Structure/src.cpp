#include "main.h"

int main()
{

	return 0;
}

void address()
{
	int donuts = 6;
	double cups = 4.5;

	cout << "donuts�� �� = " << donuts;
	cout << ", donuts�� �ּ� = " << &donuts << endl;

	cout << "cups�� �� = " << cups;
	cout << ", cups�� �ּ� = " << &cups << endl;
}

void arrstruc()
{
	inflatable guests[2] =
	{
		{"Bambi", 0.5, 21.99},
		{"Godzilla", 2000, 565.99},
	};

	cout << guests[0].name << "�� " << guests[1].name << "�� ���Ǹ� ���ϸ�\n";
	cout << guests[0].volume + guests[1].volume << "��������Ʈ�Դϴ�.\n";
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

	cout << "���� �Ǹ��ϰ� �ִ� ����ǳ����\n" << guest.name;
	cout << "�� " << pal.name << "�Դϴ�.\n";
	cout << "�� ��ǰ�� $";
	cout << guest.price + pal.price << "�� �帮�ڽ��ϴ�!\n";

}
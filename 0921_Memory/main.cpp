#include "main.h"

int main()
{
	int texas = 31;
	int year = 2011;
	cout << "main()에서, texas = " << texas << ", &texas = " << &texas << endl;
	cout << "main()에서, year = " << year << ", &year = " << &year << endl;
	oil(texas);
	cout << "main()에서, texas = " << texas << ", &texas = " << &texas << endl;
	cout << "main()에서, year = " << year << ", &year = " << &year << endl;

	return 0;
}

void oil(int x)
{
	int texas = 5;
	
	cout << "oil()에서, texas = " << texas << ", &texas = " << &texas << endl;
	cout << "oil()에서, x = " << x << ", &x = " << &x << endl;
	{
		int texas = 113;
		cout << "블록에서, texas = " << texas << ", &texas = " << &texas << endl;
		cout << "블록에서, x = " << x << "&x" << &x << endl;
	}
	cout << "블록을 통과한 후, texas = " << texas;
	cout << ", &texas = " << &texas << endl;
}
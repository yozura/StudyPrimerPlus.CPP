#include "main.h"

int main()
{


	return 0;
}

void textin4()
{
	int ch;
	int count = 0;

	while ((ch = cin.get()) != EOF)
	{
		cout.put(char(ch));
		++count;
	}

	cout << count << " ���ڸ� �о����ϴ�.";
}

void textin2()
{
	char ch;
	int count = 0;
	cin.get(ch);
	while (cin.fail() == false)
	{
		cout << ch;
		++count;;
		cin.get(ch);
	}
	cout << count << " ���ڸ� �о����ϴ�.\n";
}

void textin1()
{
	char ch;
	int count = 0;
	cout << "���ڵ��� �Է��Ͻÿ�; �������� #�� �Է��Ͻÿ�:\n";
	cin >> ch;
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin >> ch;
	}

	cout << endl << count << " ���ڸ� �о����ϴ�.\n";
}

void waiting()
{
	cout << "���� �ð��� �� ������ �Է��Ͻʽÿ�: ";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;

	cout << "ī��Ʈ�� �����մϴ�.\a\n";
	clock_t start = clock();
	while (clock() - start < delay)
		;
	cout << "����\a\n";
}

void compstr2()
{
	string word = "?ate";
	for (char ch = 'a'; word != "mate"; ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}

	cout << "������ ���� �Ŀ� �ܾ�� " << word << "�Դϴ�.\n";
}

void bigstep()
{
	cout << "������ �ϳ� �Է��Ͻʽÿ�: ";
	int by;
	cin >> by;

	cout << "���� ũ�� " << by << "s:\n";
	for (int i = 0; i < 100; i = i + by)
		cout << i << endl;
}

void formore()
{
	long long factorials[ArSize];
	factorials[1] = factorials[0] = 1LL;
	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];
	for (int i = 0; i < ArSize; i++)
		cout << i << "! = " << factorials[i] << endl;
}
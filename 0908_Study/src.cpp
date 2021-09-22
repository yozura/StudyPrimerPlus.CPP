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

	cout << count << " 문자를 읽었습니다.";
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
	cout << count << " 문자를 읽었습니다.\n";
}

void textin1()
{
	char ch;
	int count = 0;
	cout << "문자들을 입력하시오; 끝내려면 #을 입력하시오:\n";
	cin >> ch;
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin >> ch;
	}

	cout << endl << count << " 문자를 읽었습니다.\n";
}

void waiting()
{
	cout << "지연 시간을 초 단위로 입력하십시오: ";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;

	cout << "카운트를 시작합니다.\a\n";
	clock_t start = clock();
	while (clock() - start < delay)
		;
	cout << "종료\a\n";
}

void compstr2()
{
	string word = "?ate";
	for (char ch = 'a'; word != "mate"; ch++)
	{
		cout << word << endl;
		word[0] = ch;
	}

	cout << "루프가 끝난 후에 단어는 " << word << "입니다.\n";
}

void bigstep()
{
	cout << "정수를 하나 입력하십시오: ";
	int by;
	cin >> by;

	cout << "갱신 크기 " << by << "s:\n";
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
#include <iostream>
#include "student.h"
using std::cin;
using std::cout;
using std::endl;

const int pupils = 3;
const int quizzes = 5;

int main()
{
	

	return 0;
}

void set(Student& sa, int n)
{
	cout << "�л��� �̸��� �Է��Ͻʽÿ�: ";
	getline(cin, sa);
	cout << n << "ȸ�� �ɸ� ���� ������ ��� �Է��Ͻʽÿ�:\n";
	for (int i = 0; i < n; i++)
		cin >> sa[i];
	while (cin.get() != '\n')
		continue;
}

void useStudent()
{
	Student ada[pupils] = {
		Student(quizzes),
		Student(quizzes),
		Student(quizzes)
	};

	int i;
	for (i = 0; i < pupils; ++i)
		set(ada[i], quizzes);
	cout << "\n�л� ����Ʈ:\n";
	for (i = 0; i < pupils; ++i)
		cout << ada[i].Name() << endl;
	cout << "\n���� ���:";
	for (i = 0; i < pupils; ++i)
	{
		cout << endl << ada[i];
		cout << "���: " << ada[i].Average() << endl;
	}
	cout << "���α׷��� �����մϴ�.\n";
}
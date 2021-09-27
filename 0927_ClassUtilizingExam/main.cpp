#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vect.h"
#include "complex0.h"

int main()
{
	using namespace std;
	complex a(3.0, 4.0);
	complex c;
	cout << "�ϳ��� ���Ҽ��� �Է��Ͻʽÿ�(�������� q): \n";
	while (cin >> c)
	{
		cout << "c = " << c << '\n';
		cout << "���׺��Ҽ� = " << ~c << '\n';
		cout << "a = " << a << '\n';
		cout << "a + c = " << a + c << '\n';
		cout << "a - c = " << a - c << '\n';
		cout << "a * c = " << a * c << '\n';
		cout << "2 * c = " << 2 * c << '\n';
		cout << "�ϳ��� ���Ҽ��� �Է��Ͻʽÿ�(�������� q):\n";
	}
	cout << "���α׷��� �����մϴ�.";

	return 0;
}

void randwalk02()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	int n;
	double total = 0;
	double* arr;
	ofstream fout;

	cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q): ";
	while (cin >> target)
	{
		cout << "���� �Ÿ��� �Է��Ͻʽÿ�: ";
		if (!(cin >> dstep))
			break;

		cout << "���� Ƚ���� �Է��Ͻʽÿ�: ";
		if (!(cin >> n))
			break;

		arr = new double[n];
		fout.open("randwalk02.txt");
		for (int i = 0; i < n; i++)
		{
			steps = 0;
			result.reset(0.0, 0.0);
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POLAR);
				result = result + step;
				steps++;
			}

			fout << i << " : " << steps << '\n';

			arr[i] = steps;
			total += steps;
		}

		double max = arr[0];
		double min = arr[0];
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > max)
				max = arr[i];
			if (arr[i] < min)
				min = arr[i];

			fout << i << " : " << arr[i] << '\n';
		}

		fout << "�ְ� ���� �� : " << max << '\n';
		fout << "���� ���� �� : " << min << '\n';
		fout << "��� ���� �� : " << total / n << '\n';

		fout.close();
		cout << "������ ���Ͽ� ��ϵǾ����ϴ�.\n";
		cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q): ";
	}

	cout << "���α׷��� �����մϴ�.\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
}

void randwalk01()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	ofstream fout;

	cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q): ";
	while (cin >> target)
	{
		cout << "���� �Ÿ��� �Է��Ͻʽÿ�: ";
		if (!(cin >> dstep))
			break;

		fout.open("randwalk.txt");
		fout << "��ǥ �Ÿ�: " << target << ", ����: " << dstep << '\n';
		fout << steps << ": " << result;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POLAR);
			result = result + step;
			steps++;
			fout << steps << ": " << result;
		}

		fout << steps << " ���� �� ������ �� �ִ� ��ġ\n";
		fout << result;
		result.polar_mode();
		fout << " �Ǵ�\n" << result;
		fout << "������ ��տ��� ��� ��� �Ÿ� = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		fout.close();
		cout << "������ ���Ͽ� ��ϵǾ����ϴ�.\n";
		cout << "��ǥ �Ÿ��� �Է��Ͻʽÿ�(�������� q): ";
	}

	cout << "���α׷��� �����մϴ�.\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
}
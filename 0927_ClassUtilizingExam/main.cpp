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
	cout << "하나의 복소수를 입력하십시오(끝내려면 q): \n";
	while (cin >> c)
	{
		cout << "c = " << c << '\n';
		cout << "공액복소수 = " << ~c << '\n';
		cout << "a = " << a << '\n';
		cout << "a + c = " << a + c << '\n';
		cout << "a - c = " << a - c << '\n';
		cout << "a * c = " << a * c << '\n';
		cout << "2 * c = " << 2 * c << '\n';
		cout << "하나의 복소수를 입력하십시오(끝내려면 q):\n";
	}
	cout << "프로그램을 종료합니다.";

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

	cout << "목표 거리를 입력하십시오(끝내려면 q): ";
	while (cin >> target)
	{
		cout << "보폭 거리를 입력하십시오: ";
		if (!(cin >> dstep))
			break;

		cout << "실행 횟수를 입력하십시오: ";
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

		fout << "최고 걸음 수 : " << max << '\n';
		fout << "최저 걸음 수 : " << min << '\n';
		fout << "평균 걸음 수 : " << total / n << '\n';

		fout.close();
		cout << "정보가 파일에 기록되었습니다.\n";
		cout << "목표 거리를 입력하십시오(끝내려면 q): ";
	}

	cout << "프로그램을 종료합니다.\n";
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

	cout << "목표 거리를 입력하십시오(끝내려면 q): ";
	while (cin >> target)
	{
		cout << "보폭 거리를 입력하십시오: ";
		if (!(cin >> dstep))
			break;

		fout.open("randwalk.txt");
		fout << "목표 거리: " << target << ", 보폭: " << dstep << '\n';
		fout << steps << ": " << result;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POLAR);
			result = result + step;
			steps++;
			fout << steps << ": " << result;
		}

		fout << steps << " 걸음 후 술고래가 서 있는 위치\n";
		fout << result;
		result.polar_mode();
		fout << " 또는\n" << result;
		fout << "걸음당 기둥에서 벗어난 평균 거리 = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		fout.close();
		cout << "정보가 파일에 기록되었습니다.\n";
		cout << "목표 거리를 입력하십시오(끝내려면 q): ";
	}

	cout << "프로그램을 종료합니다.\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
}
#include "main.h"

int main()
{
	int cookies[ArSize] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "먹은 과자 수 합계: " << sum << endl;
	sum = sum_arr(cookies, cookies + 3);
	cout << "처음 세사람은 과자 " << sum << "개를 먹었습니다.\n";
	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "마지막 네 사람은 과자 " << sum << "개를 먹었습니다.\n";

	return 0;
}

int sum_arr(const int* begin, const int* end)
{
	const int* pt;
	int total = 0;
	
	for (pt = begin; pt != end; pt++)
		total += *pt;
	return total;
}

void arrfun4()
{

}

int fill_array(double* ar, int limit)
{
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << (i + 1) << "번 부동산의 가격: $";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "입력 불량; 입력 과정을 끝내겠습니다.\n";
			break;
		}
		else if (temp < 0)
			break;

		ar[i] = temp;
	}

	return i;
}

void show_array(const double* ar, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << (i + 1) << "번 부동산: $";
		cout << ar[i] << endl;
	}
}

void revalue(double r, double* ar, int n)
{
	for (int i = 0; i < n; i++)
		ar[i] *= r;
}

void arrfun3()
{
	double properties[Max];

	int size = fill_array(properties, Max);
	show_array(properties, size);
	if (size > 0)
	{
		cout << "재평가율을 입력하십시오: ";
		double factor;
		while (!(cin >> factor)) // 입력이 잘못되었다면 입력 스트림 비우기
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "잘못 입력했습니다, 수치를 입력하세요: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}

	cout << "프로그램을 종료합니다.\n";
	cin.get();
	cin.get();
}

void arrfun2()
{
	int cookies[ArSize] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	std::cout << cookies << " = 배열 주소, ";
	std::cout << "sizeof cookies = " << sizeof cookies << std::endl;
	int sum = sum_arr(cookies, ArSize);
	std::cout << "먹은 과자 수 합계: " << sum << std::endl;
	sum = sum_arr(cookies, 3);
	std::cout << "처음 세 사람은 과자 " << sum << "개를 먹었습니다.\n";
	sum = sum_arr(cookies + 4, 4);
	std::cout << "마지막 네 사람은 과자 " << sum << "개를 먹었습니다.\n";
}

void arrfun()
{
	int cookies[ArSize] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	int sum = sum_arr(cookies, ArSize);
	cout << "먹은 과자 수 합계: " << sum << "\n";
}

int sum_arr(int arr[], int n)
{
	int sum = 0;
	std::cout << arr << " = arr, ";
	std::cout << "sizeof arr = " << sizeof arr << std::endl;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	return result;
}

void lotto()
{
	double total, choices;
	cout << "전체 수의 개수와 뽑을 수의 개수를 입력하십시오:\n";
	while ((cin >> total >> choices) && choices <= total)
	{
		cout << "당신이 이길 확률은 ";
		cout << probability(total, choices);
		cout << "번 중에서 한 번입니다.\n";
		cout << "다시 두 수를 입력하십시오. (끝내려면 q를 입력): ";
	}
	cout << "프로그램을 종료합니다.\n";
}

void n_chars(char c, int n)
{
	while (n-- > 0)
		cout << c;
}

void twoarg()
{
	int times;
	char ch;
	cout << "문자 하나를 입력하십시오: ";
	cin >> ch;
	while (ch != 'q')
	{
		cout << "정수를 하나 입력하십시오: ";
		cin >> times;
		n_chars(ch, times);
		cout << "\n계속하려면 다른 문자를 입력하고, 끝내려면 q를 누르세요 : ";
		cin >> ch;
	}
	cout << "현재 times의 값은 " << times << "입니다.\n";
	cout << "프로그램을 종료합니다.\n";
}

void cheers(int n)
{
	for (int i = 0; i < n; i++)
		cout << "Cheers!";
	cout << endl;
}

double cube(double x)
{
	return x * x * x;
}

void protos()
{
	cheers(5);
	cout << "하나의 수를 입력하십시오: ";
	double side;
	cin >> side;
	double volume = cube(side);
	cout << "한 변의 길이가 " << side << " 센티미터인 정육면체의 부피는 ";
	cout << volume << " 세제곱센티미터입니다.\n";
	cheers(cube(2));
}

void simple()
{
	cout << "여기는 simple() 함수입니다.\n";
}

void calling()
{
	cout << "main()에서 simple() 함수를 호출합니다:\n";
	simple();
	cout << "main()이 simple() 함수와 종료됩니다.\n";
}
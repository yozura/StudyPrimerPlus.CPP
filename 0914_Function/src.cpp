#include "main.h"

int main()
{
	int cookies[ArSize] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "���� ���� �� �հ�: " << sum << endl;
	sum = sum_arr(cookies, cookies + 3);
	cout << "ó�� ������� ���� " << sum << "���� �Ծ����ϴ�.\n";
	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "������ �� ����� ���� " << sum << "���� �Ծ����ϴ�.\n";

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
		cout << (i + 1) << "�� �ε����� ����: $";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "�Է� �ҷ�; �Է� ������ �����ڽ��ϴ�.\n";
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
		cout << (i + 1) << "�� �ε���: $";
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
		cout << "�������� �Է��Ͻʽÿ�: ";
		double factor;
		while (!(cin >> factor)) // �Է��� �߸��Ǿ��ٸ� �Է� ��Ʈ�� ����
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "�߸� �Է��߽��ϴ�, ��ġ�� �Է��ϼ���: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}

	cout << "���α׷��� �����մϴ�.\n";
	cin.get();
	cin.get();
}

void arrfun2()
{
	int cookies[ArSize] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	std::cout << cookies << " = �迭 �ּ�, ";
	std::cout << "sizeof cookies = " << sizeof cookies << std::endl;
	int sum = sum_arr(cookies, ArSize);
	std::cout << "���� ���� �� �հ�: " << sum << std::endl;
	sum = sum_arr(cookies, 3);
	std::cout << "ó�� �� ����� ���� " << sum << "���� �Ծ����ϴ�.\n";
	sum = sum_arr(cookies + 4, 4);
	std::cout << "������ �� ����� ���� " << sum << "���� �Ծ����ϴ�.\n";
}

void arrfun()
{
	int cookies[ArSize] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	int sum = sum_arr(cookies, ArSize);
	cout << "���� ���� �� �հ�: " << sum << "\n";
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
	cout << "��ü ���� ������ ���� ���� ������ �Է��Ͻʽÿ�:\n";
	while ((cin >> total >> choices) && choices <= total)
	{
		cout << "����� �̱� Ȯ���� ";
		cout << probability(total, choices);
		cout << "�� �߿��� �� ���Դϴ�.\n";
		cout << "�ٽ� �� ���� �Է��Ͻʽÿ�. (�������� q�� �Է�): ";
	}
	cout << "���α׷��� �����մϴ�.\n";
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
	cout << "���� �ϳ��� �Է��Ͻʽÿ�: ";
	cin >> ch;
	while (ch != 'q')
	{
		cout << "������ �ϳ� �Է��Ͻʽÿ�: ";
		cin >> times;
		n_chars(ch, times);
		cout << "\n����Ϸ��� �ٸ� ���ڸ� �Է��ϰ�, �������� q�� �������� : ";
		cin >> ch;
	}
	cout << "���� times�� ���� " << times << "�Դϴ�.\n";
	cout << "���α׷��� �����մϴ�.\n";
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
	cout << "�ϳ��� ���� �Է��Ͻʽÿ�: ";
	double side;
	cin >> side;
	double volume = cube(side);
	cout << "�� ���� ���̰� " << side << " ��Ƽ������ ������ü�� ���Ǵ� ";
	cout << volume << " ��������Ƽ�����Դϴ�.\n";
	cheers(cube(2));
}

void simple()
{
	cout << "����� simple() �Լ��Դϴ�.\n";
}

void calling()
{
	cout << "main()���� simple() �Լ��� ȣ���մϴ�:\n";
	simple();
	cout << "main()�� simple() �Լ��� ����˴ϴ�.\n";
}
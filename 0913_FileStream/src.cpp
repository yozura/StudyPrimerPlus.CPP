#include "main.h"

int main()
{
	exam9();

	return 0;
}

void sumafile()
{
	char fileName[SIZE];
	ifstream inFile;
	cout << "������ ������ �̸��� �Է��Ͻÿ�: ";
	cin.getline(fileName, SIZE);
	inFile.open(fileName); // �Է¹��� ���ڿ��� ���� �̸����� ����
	if (!inFile.is_open())
	{
		cout << fileName << " ������ �� �� �����ϴ�." << endl;
		cout << "���α׷��� �����մϴ�.\n";
		exit(EXIT_FAILURE);
	}

	double value;
	double sum = 0.0;
	int count = 0;

	inFile >> value;
	while (inFile.good())
	{
		++count;
		sum += value;
		inFile >> value;
	}

	if (inFile.eof())
		cout << "������ ���� �����߽��ϴ�.\n";
	else if (inFile.fail())
		cout << "������ ����ġ�� �Է��� ����Ǿ����ϴ�.\n";
	else
		cout << "�� �� ���� ������ �Է��� ����Ǿ����ϴ�.\n";

	if (count == 0)
		cout << "�����Ͱ� �����ϴ�.";
	else
	{
		cout << "���� �׸��� ����: " << count << endl;
		cout << "�հ�: " << sum << endl;
		cout << "���: " << sum / count << endl;
	}

	inFile.close();
}

void outfile()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile; // ����� ���� ��ü ����
	outFile.open("carinfo.txt"); // ���Ͽ� ����

	cout << "�ڵ��� ����Ŀ�� ������ �Է��Ͻÿ�: ";
	cin.getline(automobile, 50);
	cout << "������ �Է��Ͻÿ� : ";
	cin >> year;
	cout << "���԰��� �Է��Ͻÿ� : ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	// cout���� ��ũ���� ���÷���
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "����Ŀ�� ����: " << automobile << endl;
	cout << "����: " << year << endl;
	cout << "���԰� $" << a_price << endl;
	cout << "�߰� $" << d_price << endl;

	// outFile�� ���Ͽ� ���
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "����Ŀ�� ����: " << automobile << endl;
	outFile << "����: " << year << endl;
	outFile << "���԰� $" << a_price << endl;
	outFile << "�߰� $" << d_price << endl;
	outFile.close();
}
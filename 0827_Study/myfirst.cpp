#include "korea.h"

void simon(int);
int stonetolb(int);

int main()
{
	exam07();
	return 0;
}

int convert()
{
	int stone;
	cout << "ü���� ���� ������ �Է��Ͻÿ�: ";
	cin >> stone;
	int pounds = stonetolb(stone);
	cout << stone << " ������ ";
	cout << pounds << " �Ŀ���Դϴ�." << endl;

	return 0;
}

int stonetolb(int sts)
{
	return 14 * sts;
}

int ourfunc()
{
	simon(3);
	cout << "������ �ϳ� ���ÿ�: ";
	int count;
	cin >> count;
	simon(count);
	cout << "��!" << endl;
	return 0;
}

void simon(int n)
{
	cout << "Simon ��, �߰����� " << n << "�� �ε����." << endl;
}

int sqrt()
{
	double area;
	cout << "���� ������ �����Ʈ ������ �Է��Ͻÿ�: ";
	cin >> area;
	double side;
	side = sqrt(area);
	cout << "�簢�� ������ �� ���� " << side << "��Ʈ�� ����մϴ�." << endl;
	cout << "�����׿�!" << endl;

	return 0;
}

int getinfo()
{
	int carrots;

	cout << "����� �� ���� ������ �ִ�?" << endl;
	cin >> carrots;
	cout << "���� �� ���� �� �ִ�.";
	carrots = carrots + 2;

	cout << "���� ����� ��� " << carrots << "���̴�." << endl;
	return 0;
}

int carrots()
{
	int carrots;

	carrots = 25;
	cout << "���� ����� ";
	cout << carrots;
	cout << "�� ������ �ִ�.";
	cout << endl;
	carrots = carrots - 1;
	cout << "�ƻ�ƻ�, ���� ����� " << carrots << "���̴�." << endl;
	return 0;
}

int myfirst()
{
	cout << "C++�� ����� ���ʽÿ�.";
	cout << endl;
	cout << "��ȸ���� ������ �̴ϴ�!" << endl;
	return 0;
}
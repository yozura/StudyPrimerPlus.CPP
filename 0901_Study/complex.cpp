#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

int main()
{


	return 0;
}

void strtype4()
{
	char charr[20];
	string str;

	cout << "�Է� ������ charr�� �ִ� ���ڿ��� ����: " << strlen(charr) << endl;
	cout << "�Է� ������ str�� �ִ� ���ڿ��� ����: " << str.size() << endl;
	cout << "�ؽ�Ʈ �� ���� �Է��Ͻÿ�:\n";
	cin.getline(charr, 20);
	cout << "�Է��� �ؽ�Ʈ: " << charr << endl;
	cout << "�� �ٸ� �ؽ�Ʈ �� ���� �Է��Ͻÿ�:\n";
	getline(cin, str);
	cout << "�Է��� �ؽ�Ʈ: " << str << endl;
	cout << "�Է� ���Ŀ� charr�� �ִ� ���ڿ��� ����: ";
	cout << strlen(charr) << endl;
	cout << "�Է� ���Ŀ� str�� �ִ� ���ڿ��� ����: ";
	cout << str.size() << endl;
}

void strtype3()
{
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	str1 = str2;
	strcpy(charr1, charr2);

	str1 += " paste";
	strcat(charr1, " juice");

	int len1 = str1.size();
	int len2 = strlen(charr1);

	cout << str1 << " ���ڿ����� " << len1 << "���� ���ڰ� ����ִ�.\n";
	cout << charr2 << " ���ڿ����� " << len2 << "���� ���ڰ� ����ִ�.\n";
}

void strtype2()
{
	string s1 = "penguin";
	string s2, s3;

	cout << "string ��ü�� string ��ü�� ������ �� �ִ�: s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << ", s2: " << s2 << endl;
	cout << "string ��ü�� C ��Ÿ�� ���ڿ��� ������ �� �ִ�.\n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2: " << s2 << endl;
	cout << "string ��ü���� ������ �� �ִ�: s3 = s1 + s2\n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "string ��ü���� �߰��� �� �ִ�.\n";
	s1 += s2;
	cout << "s1 += s2 --> s1 = " << s1 << endl;
	s2 += " for a day";
	cout << "s2 += \" for a day\" --> s2 = " << s2 << endl;
}

void strtype1()
{
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	cout << "����̰��� ���� �� ���� �Է��Ͻÿ�: ";
	cin >> charr1;
	cout << "����̰��� �� �ٸ� ���� �� ���� �Է��Ͻÿ�: ";
	cin >> str1;
	cout << "�Ʒ� �������� ��� ����̰��Դϴ�:\n";
	cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;
	cout << charr2 << "���� �� ��° ����: " << charr2[2] << endl;
	cout << str2 << "���� �� ��° ���� : " << str2[2] << endl;
}

void numstr()
{
	cout << "���� ��ô� ����Ʈ�� ���� �����ϼ̽��ϱ�?\n";
	int year;
	(cin >> year).get();
	cout << "��ô� ���ø� ������ �ֽðڽ��ϱ�?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "����Ʈ ���� ����: " << year << endl;
	cout << "����: " << address << endl;
	cout << "����� �Ϸ�Ǿ����ϴ�!\n";
}

void instr3()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "�̸��� �Է��Ͻʽÿ�: \n";
	cin.get(name, ArSize).get();
	cout << "�����ϴ� ����Ʈ�� �Է��Ͻʽÿ�:\n";
	cin.get(dessert, ArSize).get();
	cout << "���ִ� " << dessert;
	cout << " ����Ʈ�� �غ��ϰڽ��ϴ�. " << name << "��!\n";
}

void instr2()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "�̸��� �Է��Ͻʽÿ�:\n";
	cin.getline(name, ArSize);
	cout << "�����ϴ� ����Ʈ�� �Է��Ͻʽÿ�:\n";
	cin.getline(dessert, ArSize);
	cout << "���ִ� " << dessert;
	cout << " ����Ʈ�� �غ��ϰڽ��ϴ�. " << name << " ��! \n";
}

void instr1()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "�̸��� �Է��Ͻʽÿ�:\n";
	cin >> name;
	cout << "�����ϴ� ����Ʈ�� �Է��Ͻʽÿ�:\n";
	cin >> dessert;
	cout << "���ִ� " << dessert;
	cout << " ����Ʈ�� �غ��ϰڽ��ϴ�. " << name << " ��! \n";
}

void strings()
{
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	cout << "�ȳ��ϼ���! ���� " << name2;
	cout << "�Դϴ�! �Ƿ����� ������?\n";
	cin >> name1;

	cout << "��, " << name1 << " ��! ����� �̸��� ";
	cout << strlen(name1) << "���Դϴٸ� \n";
	cout << sizeof(name1) << "����Ʈ ũ���� �迭�� ����Ǿ����ϴ�.\n";
	cout << "�̸��� " << name1[0] << "�ڷ� �����ϴ±���.\n";
	name2[3] = '\0';
	cout << "�� �̸��� ó�� �� ���ڴ� ������ �����ϴ�: ";
	cout << name2 << endl;
}

void arrayone()
{
	int yams[3];
	yams[0] = 7;
	yams[1] = 8;
	yams[2] = 6;

	int yamcosts[3] = { 200, 300, 50 };

	cout << "���� �հ� = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << yams[1] << "���� ��� �ִ� ������ ";
	cout << "���� " << yamcosts[1] << "�����Դϴ�.\n";

	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1] + yams[2] * yamcosts[2];
	cout << "�� ������ �� ������ " << total << "�� �Դϴ�.\n";
	cout << "\nyams �迭�� ũ��� " << sizeof yams;
	cout << "����Ʈ�Դϴ�.";
	cout << "���� �ϳ��� ũ��� " << sizeof yams[0];
	cout << "����Ʈ�Դϴ�.\n";
}
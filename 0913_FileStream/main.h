#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <string>

using namespace std;

const int SIZE = 60;
const int ArSize = 10;
const int strsize = 128;

struct contributor_temp
{
	string name;
	double donation;
};

void exam9()
{
	contributor_temp* contributor;
	ifstream inFile;
	int headCount;
	int i = 0;
	inFile.open("donateList.txt");
	if (!inFile.is_open())
		exit(EXIT_FAILURE);
	
	inFile >> headCount;
	contributor = new contributor_temp[headCount];
	cout << headCount << "\n";
	inFile.ignore(1000, '\n');
	while (!inFile.eof() && i < headCount)
	{
		getline(inFile, contributor[i].name);
		inFile >> contributor[i].donation;
		inFile.ignore(1000, '\n');

		cout << contributor[i].name << " : " << contributor[i].donation << "\n";
		i++;
	}

	inFile.close();
}

void exam8()
{
	ifstream inFile;
	int count = 0;
	char ch;
	inFile.open("something.txt");
	if (!inFile.is_open())
		exit(EXIT_FAILURE);
	
	while (!inFile.eof())
	{
		inFile >> ch;
		if(isprint(ch))
			count++;
	}

	cout << "���� ���� ���� : " << count;
	inFile.close();
}

void exam7()
{
	string str;
	char ch;
	int vowelCount = 0;
	int consonantCount = 0;
	int etcCount = 0;
	cout << "�ܾ���� �Է��Ͻÿ� (�������� q) :\n";
	while (cin >> str && str != "q")
	{
		ch = tolower(str[0]);
		if (isalpha(ch))
		{
			switch (ch)
			{
			case 'a': vowelCount++; break;
			case 'e': vowelCount++; break;
			case 'i': vowelCount++; break;
			case 'o': vowelCount++; break;
			case 'u': vowelCount++; break;
			default: consonantCount++; break;
			}
		}
		else if (isdigit(ch))
			etcCount++;
	}

	cout << "�������� �����ϴ� �ܾ� �� : " << vowelCount << "\n";
	cout << "�������� �����ϴ� �ܾ� �� : " << consonantCount << "\n";
	cout << "��Ÿ: " << etcCount << "\n";
}

void exam6()
{
	contributor_temp* contributor;
	int headCount;
	cout << "Society for the Preservation of Rightful Influence�� ���� ����� ����\n";
	cout << "����� �ο� �Է� : ";
	cin >> headCount;
	cin.ignore(1000, '\n');
	if (headCount <= 0)
	{
		cout << "����ڰ� �����ϴ�.";
		return;
	}

	contributor = new contributor_temp[headCount];

	int i = 0;
	while (i < headCount)
	{
		cout << "��� #" << i + 1 << "\n";
		cout << "�����: ";
		getline(cin, contributor[i].name);
		cout << "��α�: $";
		cin >> contributor[i].donation;
		cin.ignore(1000, '\n');
		i++;
	}

	cout << "<��� �����>\n";
	for (int i = 0; i < headCount; i++)
	{
		if (contributor[i].donation >= 10000)
			cout << contributor[i].name << " : " << contributor[i].donation << "\n";
	}

	cout << "<�Ҿ� �����>\n";
	for (int i = 0; i < headCount; i++)
	{
		if (contributor[i].donation < 10000)
			cout << contributor[i].name << " : " << contributor[i].donation << "\n";
	}
}

void exam5()
{
	int tvarp;
	cout << "�ҵ��� Ʈ���� ������ �Է��ϼ���: ";
	while (cin >> tvarp && tvarp > 0)
	{
		cout << "�ҵ�: " << tvarp;
		int tax = 0;


		cout << "�ҵ漼: " << tax;
	}
}

struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

void exam4()
{
	char ch;
	bop bops[5] =
	{
		{ "Anne Mayer", "Knight Run", "Anne", 0 },
		{ "Deepflow", "VMC", "639", 1 },
		{ "Paloalto", "HILITE", "Palo", 1},
		{ "Orca", "Whale", "Killer Whale", 2},
		{ "Yazawa Nico", "Lovelive", "Nico", 0},
	};

	cout << "Benevolent Order of Programmers\n";
	cout << "a. �Ǹ����� ����\t\tb. �������� ����\n";
	cout << "c. BOP ���̵�� ����\t\td. ȸ���� ������ ������ ����\n";
	cout << "q. ����\n";

	cin >> ch;
	while (true)
	{
		switch (ch)
		{
			case 'a':
				for (int i = 0; i < 5; i++)
					cout << bops[i].fullname << "\n";
				break;
			case 'b':
				for (int i = 0; i < 5; i++)
					cout << bops[i].title << "\n";
				break;
			case 'c':
				for (int i = 0; i < 5; i++)
					cout << bops[i].bopname << "\n";
				break;
			case 'd':
				for (int i = 0; i < 5; i++)
				{
					switch (bops[i].preference)
					{
						case 0: cout << bops[i].fullname << "\n"; break;
						case 1: cout << bops[i].title << "\n"; break;
						case 2: cout << bops[i].bopname << "\n"; break;
					}
				}
				break;
			case 'q':
				cout << "���α׷��� �����մϴ�.";
				return;
		}
		cout << "���ϴ� ���� �����Ͻʽÿ�: ";
		cin >> ch;
	}
}

void exam3()
{
	char ch;

	cout << "���� ���� ���� �߿��� �ϳ��� �����Ͻʽÿ�. (�������� q)\n";
	cout << "c) camera\tp) pianist\n";
	cout << "t) tree\t\tg) game\n";
	cin >> ch;
	while (ch != 'q')
	{
		switch (ch)
		{
			case 'c':
				cout << "ī�޶� ��� ���ִ� ����� ���� �Ʒ��ϴ�.\n\n";
				break;
			case 'p':
				cout << "�ǾƴϽ�Ʈ�� �հ����� ��� �����ߴ�.\n\n";
				break;
			case 't':
				cout << "��ǳ������ ���� ��ó�� ������ϴ�.\n\n";
				break;
			case 'g':
				cout << "������ ������ ������ �ƴϴ�.\n\n";
				break;
		}

		cout << "c, p, t, g �߿��� �ϳ��� �����Ͻʽÿ�. (�������� q) : \n";
		cin >> ch;
	}
}

void exam2()
{
	double donation[ArSize];
	double sum = 0;
	int count1 = 0;
	int	count2 = 0;

	std::cout << "��α��� �Է��ϼ��� : ";
	int i = 0;	
	while (i < ArSize && cin >> donation[i])
	{
		i++;
		sum += donation[i];
		count1++;
	}
	
	std::cout << "��α� ��� : " << sum / count1 << endl;
	for (int i = 0; i < count1; i++)
	{
		if (donation[i] > sum)
			count2++;
	}
	std::cout << "��պ��� ���� ��α��� ���� : " << count2;
}

void exam1()
{
	char ch;

	while ((ch = cin.get()) != '@')
	{
		char temp = ch;
		if (isalpha(ch))
		{
			if (isupper(ch))
				temp = tolower(ch);
			else if (islower(ch))
				temp = toupper(ch);
		}

		std::cout << temp;
	}
}
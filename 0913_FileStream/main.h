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

	cout << "읽은 문자 개수 : " << count;
	inFile.close();
}

void exam7()
{
	string str;
	char ch;
	int vowelCount = 0;
	int consonantCount = 0;
	int etcCount = 0;
	cout << "단어들을 입력하시오 (끝내려면 q) :\n";
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

	cout << "모음으로 시작하는 단어 수 : " << vowelCount << "\n";
	cout << "자음으로 시작하는 단어 수 : " << consonantCount << "\n";
	cout << "기타: " << etcCount << "\n";
}

void exam6()
{
	contributor_temp* contributor;
	int headCount;
	cout << "Society for the Preservation of Rightful Influence에 대한 기부자 내역\n";
	cout << "기부자 인원 입력 : ";
	cin >> headCount;
	cin.ignore(1000, '\n');
	if (headCount <= 0)
	{
		cout << "기부자가 없습니다.";
		return;
	}

	contributor = new contributor_temp[headCount];

	int i = 0;
	while (i < headCount)
	{
		cout << "기부 #" << i + 1 << "\n";
		cout << "기부자: ";
		getline(cin, contributor[i].name);
		cout << "기부금: $";
		cin >> contributor[i].donation;
		cin.ignore(1000, '\n');
		i++;
	}

	cout << "<고액 기부자>\n";
	for (int i = 0; i < headCount; i++)
	{
		if (contributor[i].donation >= 10000)
			cout << contributor[i].name << " : " << contributor[i].donation << "\n";
	}

	cout << "<소액 기부자>\n";
	for (int i = 0; i < headCount; i++)
	{
		if (contributor[i].donation < 10000)
			cout << contributor[i].name << " : " << contributor[i].donation << "\n";
	}
}

void exam5()
{
	int tvarp;
	cout << "소득을 트바프 단위로 입력하세요: ";
	while (cin >> tvarp && tvarp > 0)
	{
		cout << "소득: " << tvarp;
		int tax = 0;


		cout << "소득세: " << tax;
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
	cout << "a. 실명으로 열람\t\tb. 직함으로 열람\n";
	cout << "c. BOP 아이디로 열람\t\td. 회원이 지정한 것으로 열람\n";
	cout << "q. 종료\n";

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
				cout << "프로그램을 종료합니다.";
				return;
		}
		cout << "원하는 것을 선택하십시오: ";
		cin >> ch;
	}
}

void exam3()
{
	char ch;

	cout << "다음 선택 사항 중에서 하나를 선택하십시오. (끝내려면 q)\n";
	cout << "c) camera\tp) pianist\n";
	cout << "t) tree\t\tg) game\n";
	cin >> ch;
	while (ch != 'q')
	{
		switch (ch)
		{
			case 'c':
				cout << "카메라를 들고 서있는 모습은 무언가 아련하다.\n\n";
				break;
			case 'p':
				cout << "피아니스트의 손가락은 얇고 길쭉했다.\n\n";
				break;
			case 't':
				cout << "단풍나무는 잎이 별처럼 생겼습니다.\n\n";
				break;
			case 'g':
				cout << "게임의 목적은 경쟁이 아니다.\n\n";
				break;
		}

		cout << "c, p, t, g 중에서 하나를 선택하십시오. (끝내려면 q) : \n";
		cin >> ch;
	}
}

void exam2()
{
	double donation[ArSize];
	double sum = 0;
	int count1 = 0;
	int	count2 = 0;

	std::cout << "기부금을 입력하세요 : ";
	int i = 0;	
	while (i < ArSize && cin >> donation[i])
	{
		i++;
		sum += donation[i];
		count1++;
	}
	
	std::cout << "기부금 평균 : " << sum / count1 << endl;
	for (int i = 0; i < count1; i++)
	{
		if (donation[i] > sum)
			count2++;
	}
	std::cout << "평균보다 많은 기부금의 갯수 : " << count2;
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
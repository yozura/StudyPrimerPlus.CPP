#include "main.h"

int main()
{

	
	return 0;
}

void cingolf()
{
	int golf[Max];
	cout << "골프 점수를 입력하십시오.\n";
	cout << "총 " << Max << " 라운드 점수를 입력해야 합니다.\n";
	int i;
	for (i = 0; i < Max; i++)
	{
		cout << "round #" << i + 1 << ": ";
		while (!(cin >> golf[i]))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;

			cout << "골프 점수를 입력하십시오: ";
		}
	}

	double total = 0.0;
	for (i = 0; i < Max; i++)
		total += golf[i];

	cout << "총 " << Max << "라운드의 평균 점수 = " << total / Max << endl;
}

void cinfish()
{
	double fish[Max];
	cout << "오늘 낚은 물고기의 무게를 입력하십시오.\n";
	cout << "물고기는 최대 " << Max << "마리까지 낚을 수 있습니다.\n";
	cout << "<입력을 끝내려면 q를 누르십시오.>\n";
	cout << "fish #1: ";
	int i = 0;
	while (i < Max && cin >> fish[i])
	{
		if (++i < Max)
			cout << "fish #" << i + 1 << ": ";
	}

	double total = 0.0;
	for (int j = 0; j < i; j++)
		total += fish[j];

	if (i == 0)
		cout << "물고기를 한 마리도 낚지 못하셨군요.\n";
	else
		cout << "물고기 " << i << "마리의 평균 무게는 " << total / i << "그램입니다.\n";
	cout << "프로그램을 종료합니다.\n";
}

void jump()
{
	char line[ArSize];
	int spaces = 0;
	cout << "한 행의 텍스트를 입력하십시오:\n";
	cin.get(line, ArSize);
	cout << "전체 텍스트:\n" << line << endl;
	cout << "첫 마침표까지의 텍스트:\n";

	for (int i = 0; line[i] != '\0'; i++)
	{
		cout << line[i];
		if (line[i] == '.')
			break;
		if (line[i] != ' ')
			continue;
		spaces++;
	}
	cout << "\n빈칸 문자는 " << spaces << "개입니다.\n";
	cout << "종료.\n";
}

void enumswt()
{
	cout << "컬러 코드(0, 1, 2, 3, 4, 5, 6)을 입력하십시오: ";
	int code;
	cin >> code;
	while (code >= red && code <= indigo)
	{
		switch (code)
		{
		case red: cout << "입술은 붉었습니다.\n"; break;
		case orange: cout << "머리카락은 귤색이었습니다.\n"; break;
		case yellow: cout << "신발은 노랑색이었습니다.\n"; break;
		case green: cout << "손톱은 초록색이었습니다.\n"; break;
		case blue: cout << "스웨터는 파란색이었습니다.\n"; break;
		case violet: cout << "눈은 보라색이었습니다.\n"; break;
		case indigo: cout << "분위기는 쪽빛이었습니다.\n"; break;
		}

		cout << "컬러 코드(0, 1, 2, 3, 4, 5, 6)을 입력하십시오: ";
		cin >> code;

	}

	cout << "프로그램을 종료합니다.";
}

void swt()
{
	showmenu();
	int choice;
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			cout << "\a\n";
			break;
		case 2:
			report();
			break;
		case 3:
			cout << "사장님은 오늘 회사에 계셨습니다.\n";
			break;
		case 4:
			comfort();
			break;
		default:
			cout << "그것은 선택할 수 없습니다.\n";
		}
		showmenu();
		cin >> choice;
	}

	cout << "프로그램을 종료합니다!\n";
}

void condit()
{
	int a, b;
	cout << "두 개의 정수를 입력하십시오: ";
	cin >> a >> b;
	cout << "둘 중에서 더 큰 정수는 ";
	int c = a > b ? a : b;
	cout << c << "입니다.\n";
}

void cctypes()
{
	cout << "분석할 텍스트를 입력하십시오. ";
	cout << "입력의 끝을 @으로 표기하십시오.\n";

	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;

	cin.get(ch);
	while (ch != '@')
	{
		if (isalpha(ch))
			chars++;
		else if (isspace(ch))
			whitespace++;
		else if (isdigit(ch))
			digits++;
		else if (ispunct(ch))
			punct++;
		else
			others++;
		cin.get(ch);
	}
	cout << "알파벳 : " << chars << "\n";
	cout << "빈 칸 : " << whitespace << "\n";
	cout << "숫자 : " << digits << "\n";
	cout << "구두점 : " << punct << "\n";
	cout << "기타 : " << others << "\n";
}

void bang()
{
	double num;

	cout << "정수 값을 하나 입력하십시오: ";
	cin >> num;
	while (!is_int(num))
	{
		cout << "int형에 대입할 수 없는 값입니다. 다시 입력하십시오: ";
		cin >> num;
	}
	int val = int(num);
	cout << "당신이 입력한 정수는 " << val << "입니다.\n";
}

void moreand()
{
	int age;
	cout << "나이를 입력하십시오: ";
	cin >> age;
	int index;

	if (age > 17 && age < 35)
		index = 0;
	else if (age >= 35 && age < 50)
		index = 1;
	else if (age >= 50 && age < 65)
		index = 2;
	else
		index = 3;

	cout << "당신은 " << qualify[index] << "에 참가할 수 있습니다.\n";
}

void naaq()
{
	float naaq[ArSize];
	cout << "동료들의 뉴에이지 자각 지수(NAAQ)를 입력하십시오.\n" << ArSize
		<< "명의 데이터를 모두 입력했거나, 음수를 입력하면\n"
		<< "while 루프를 탈출합니다.\n";

	int i = 0;
	float temp;
	cout << "첫 번째 값: ";
	cin >> temp;
	while (i < ArSize && temp >= 0)
	{
		naaq[i] = temp;
		++i;
		if (i < ArSize)
		{
			cout << "그 다음 값: ";
			cin >> temp;
		}
	}

	if (i == 0)
		cout << "입력한 데이터가 없으므로 프로그램을 종료합니다.\n";
	else
	{
		cout << "당신의 NAAQ를 입력하십시오: ";
		float you;
		cin >> you;
		int count = 0;
		for (int j = 0; j < i; j++)
			if (naaq[j] > you)
				++count;
		cout << "동료들 중에서 " << count;
		cout << "명이 당신보다 NAAQ가 높습니다.\n";
	}
}

void orr()
{
	cout << "이 프로그램은 하드 디스크를 다시 포맷합니다.\n"
		"하드 디스크에 있는 모든 데이터가 지워집니다.\n"
		"계속하시겠습니까? <y/n>";

	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		cout << "당신에게 분명히 경고를 했습니다.\a\a\n";
	else if (ch == 'n' || ch == 'N')
		cout << "현명한 선택입니다. 프로그램을 종료합니다.\n";
	else
		cout << "y나 n을 입력하지 않았습니다.\n"
		"지시사항을 따를 수 없습니다."
		"휴지통을 비우고 디스크를 정리하겠습니다.";
}

void ifesleif()
{
	int n;

	cout << "1부터 100까지 범위에서 하나의 수를 알아맞히는 게임입니다.\n";
	cout << "내가 좋아하는 수는 무엇일까요?";
	do
	{
		cin >> n;
		if (n < Fave)
			cout << "그것보다 큽니다. 무엇일까요? ";
		else if (n > Fave)
			cout << "그것보다 작습니다. 무엇일까요? ";
		else
			cout << "맞았습니다. 정답은 " << Fave << "입니다.\n";
	} while (n != Fave);
}

void ifelse()
{
	char ch;

	cout << "타이핑하시면, 반복 수행하겠습니다.\n";
	cin.get(ch);
	while (ch != '.')
	{
		if (ch == '\n')
			cout << ch;
		else
			cout << ++ch;
		cin.get(ch);
	}

	cout << "\n혼란스럽게 해서 죄송합니다.";
}

void testif()
{
	int spaces = 0;
	int total = 0;
	char ch;
	cin.get(ch);
	while (ch != '.')
	{
		if (ch == ' ')
			++spaces;
		++total;
		cin.get(ch);
	}

	cout << "이 문장의 총 문자 수는 " << total << "이고, ";
	cout << "그 중에서 빈칸은 " << spaces << "개입니다.\n";
}
#include "main.h"

int main()
{

	
	return 0;
}

void cingolf()
{
	int golf[Max];
	cout << "���� ������ �Է��Ͻʽÿ�.\n";
	cout << "�� " << Max << " ���� ������ �Է��ؾ� �մϴ�.\n";
	int i;
	for (i = 0; i < Max; i++)
	{
		cout << "round #" << i + 1 << ": ";
		while (!(cin >> golf[i]))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;

			cout << "���� ������ �Է��Ͻʽÿ�: ";
		}
	}

	double total = 0.0;
	for (i = 0; i < Max; i++)
		total += golf[i];

	cout << "�� " << Max << "������ ��� ���� = " << total / Max << endl;
}

void cinfish()
{
	double fish[Max];
	cout << "���� ���� ������� ���Ը� �Է��Ͻʽÿ�.\n";
	cout << "������ �ִ� " << Max << "�������� ���� �� �ֽ��ϴ�.\n";
	cout << "<�Է��� �������� q�� �����ʽÿ�.>\n";
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
		cout << "����⸦ �� ������ ���� ���ϼ̱���.\n";
	else
		cout << "����� " << i << "������ ��� ���Դ� " << total / i << "�׷��Դϴ�.\n";
	cout << "���α׷��� �����մϴ�.\n";
}

void jump()
{
	char line[ArSize];
	int spaces = 0;
	cout << "�� ���� �ؽ�Ʈ�� �Է��Ͻʽÿ�:\n";
	cin.get(line, ArSize);
	cout << "��ü �ؽ�Ʈ:\n" << line << endl;
	cout << "ù ��ħǥ������ �ؽ�Ʈ:\n";

	for (int i = 0; line[i] != '\0'; i++)
	{
		cout << line[i];
		if (line[i] == '.')
			break;
		if (line[i] != ' ')
			continue;
		spaces++;
	}
	cout << "\n��ĭ ���ڴ� " << spaces << "���Դϴ�.\n";
	cout << "����.\n";
}

void enumswt()
{
	cout << "�÷� �ڵ�(0, 1, 2, 3, 4, 5, 6)�� �Է��Ͻʽÿ�: ";
	int code;
	cin >> code;
	while (code >= red && code <= indigo)
	{
		switch (code)
		{
		case red: cout << "�Լ��� �Ӿ����ϴ�.\n"; break;
		case orange: cout << "�Ӹ�ī���� �ֻ��̾����ϴ�.\n"; break;
		case yellow: cout << "�Ź��� ������̾����ϴ�.\n"; break;
		case green: cout << "������ �ʷϻ��̾����ϴ�.\n"; break;
		case blue: cout << "�����ʹ� �Ķ����̾����ϴ�.\n"; break;
		case violet: cout << "���� ������̾����ϴ�.\n"; break;
		case indigo: cout << "������� �ʺ��̾����ϴ�.\n"; break;
		}

		cout << "�÷� �ڵ�(0, 1, 2, 3, 4, 5, 6)�� �Է��Ͻʽÿ�: ";
		cin >> code;

	}

	cout << "���α׷��� �����մϴ�.";
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
			cout << "������� ���� ȸ�翡 ��̽��ϴ�.\n";
			break;
		case 4:
			comfort();
			break;
		default:
			cout << "�װ��� ������ �� �����ϴ�.\n";
		}
		showmenu();
		cin >> choice;
	}

	cout << "���α׷��� �����մϴ�!\n";
}

void condit()
{
	int a, b;
	cout << "�� ���� ������ �Է��Ͻʽÿ�: ";
	cin >> a >> b;
	cout << "�� �߿��� �� ū ������ ";
	int c = a > b ? a : b;
	cout << c << "�Դϴ�.\n";
}

void cctypes()
{
	cout << "�м��� �ؽ�Ʈ�� �Է��Ͻʽÿ�. ";
	cout << "�Է��� ���� @���� ǥ���Ͻʽÿ�.\n";

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
	cout << "���ĺ� : " << chars << "\n";
	cout << "�� ĭ : " << whitespace << "\n";
	cout << "���� : " << digits << "\n";
	cout << "������ : " << punct << "\n";
	cout << "��Ÿ : " << others << "\n";
}

void bang()
{
	double num;

	cout << "���� ���� �ϳ� �Է��Ͻʽÿ�: ";
	cin >> num;
	while (!is_int(num))
	{
		cout << "int���� ������ �� ���� ���Դϴ�. �ٽ� �Է��Ͻʽÿ�: ";
		cin >> num;
	}
	int val = int(num);
	cout << "����� �Է��� ������ " << val << "�Դϴ�.\n";
}

void moreand()
{
	int age;
	cout << "���̸� �Է��Ͻʽÿ�: ";
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

	cout << "����� " << qualify[index] << "�� ������ �� �ֽ��ϴ�.\n";
}

void naaq()
{
	float naaq[ArSize];
	cout << "������� �������� �ڰ� ����(NAAQ)�� �Է��Ͻʽÿ�.\n" << ArSize
		<< "���� �����͸� ��� �Է��߰ų�, ������ �Է��ϸ�\n"
		<< "while ������ Ż���մϴ�.\n";

	int i = 0;
	float temp;
	cout << "ù ��° ��: ";
	cin >> temp;
	while (i < ArSize && temp >= 0)
	{
		naaq[i] = temp;
		++i;
		if (i < ArSize)
		{
			cout << "�� ���� ��: ";
			cin >> temp;
		}
	}

	if (i == 0)
		cout << "�Է��� �����Ͱ� �����Ƿ� ���α׷��� �����մϴ�.\n";
	else
	{
		cout << "����� NAAQ�� �Է��Ͻʽÿ�: ";
		float you;
		cin >> you;
		int count = 0;
		for (int j = 0; j < i; j++)
			if (naaq[j] > you)
				++count;
		cout << "����� �߿��� " << count;
		cout << "���� ��ź��� NAAQ�� �����ϴ�.\n";
	}
}

void orr()
{
	cout << "�� ���α׷��� �ϵ� ��ũ�� �ٽ� �����մϴ�.\n"
		"�ϵ� ��ũ�� �ִ� ��� �����Ͱ� �������ϴ�.\n"
		"����Ͻðڽ��ϱ�? <y/n>";

	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		cout << "��ſ��� �и��� ��� �߽��ϴ�.\a\a\n";
	else if (ch == 'n' || ch == 'N')
		cout << "������ �����Դϴ�. ���α׷��� �����մϴ�.\n";
	else
		cout << "y�� n�� �Է����� �ʾҽ��ϴ�.\n"
		"���û����� ���� �� �����ϴ�."
		"�������� ���� ��ũ�� �����ϰڽ��ϴ�.";
}

void ifesleif()
{
	int n;

	cout << "1���� 100���� �������� �ϳ��� ���� �˾Ƹ����� �����Դϴ�.\n";
	cout << "���� �����ϴ� ���� �����ϱ��?";
	do
	{
		cin >> n;
		if (n < Fave)
			cout << "�װͺ��� Ů�ϴ�. �����ϱ��? ";
		else if (n > Fave)
			cout << "�װͺ��� �۽��ϴ�. �����ϱ��? ";
		else
			cout << "�¾ҽ��ϴ�. ������ " << Fave << "�Դϴ�.\n";
	} while (n != Fave);
}

void ifelse()
{
	char ch;

	cout << "Ÿ�����Ͻø�, �ݺ� �����ϰڽ��ϴ�.\n";
	cin.get(ch);
	while (ch != '.')
	{
		if (ch == '\n')
			cout << ch;
		else
			cout << ++ch;
		cin.get(ch);
	}

	cout << "\nȥ�������� �ؼ� �˼��մϴ�.";
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

	cout << "�� ������ �� ���� ���� " << total << "�̰�, ";
	cout << "�� �߿��� ��ĭ�� " << spaces << "���Դϴ�.\n";
}
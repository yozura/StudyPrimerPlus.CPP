#include "main.h"

int main()
{
	exam7();
	return 0;
}

void typecast()
{
	int auks, bats, coots;
	
	auks = 19.99 + 11.99;
	
	bats = (int)19.99 + (int)11.99;
	coots = int(19.99) + int(11.9);
	cout << "�ٴٿ��� = " << auks << ", ���� = " << bats;
	cout << ", �˵տ��� = " << coots << endl;

	char ch = 'Z';
	cout << "�ڵ� " << ch << "�� ���� ";
	cout << int(ch) << endl;
	cout << "��, �ڵ� Z�� ���� ";
	cout << static_cast<int>(ch) << endl;
}

void init()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tree = 3;
	int guess = 3.9832;
	int debt = 7.2E12;
	cout << "tree = " << tree << endl;
	cout << "guess = " << guess << endl;
	cout << "debt = " << debt << endl;
}

void modulus()
{
	const int Lbs_per_stn = 14;
	int lbs;

	cout << "����� ü���� �Ŀ�� ������ �Է��Ͻʽÿ�: ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn;
	int pounds = lbs % Lbs_per_stn;
	cout << lbs << " �Ŀ��� " << stone << " ����, " << pounds << " �Ŀ���Դϴ�.\n";
}

void divide()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "���� ������: 9/5 = " << 9 / 5 << endl;
	cout << "�ε� �Ҽ����� ������: 9.0/5.0 = ";
	cout << 9.0 / 5.0 << endl;
	cout << "ȥ�� ������: 9.0/5 = " << 9.0 / 5 << endl;
	cout << "double�� ���: 1e7/9.0 = ";
	cout << 1.e7 / 9.0 << endl;
	cout << "float�� ���: 1e7f/9.0f = ";
	cout << 1.e7f / 9.0f << endl;
}

void arith()
{
	float hats, heads;

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "���� �ϳ� �Է��Ͻʽÿ�: ";
	cin >> hats;
	cout << "�ٸ� ���� �Է��Ͻʽÿ�: ";
	cin >> heads;

	cout << "hats = " << hats << "; heads = " << heads << endl;
	cout << "hats + heads = " << hats + heads << endl;
	cout << "hats - heads = " << hats - heads << endl;
	cout << "hats * heads = " << hats * heads << endl;
	cout << "hats / heads = " << hats / heads << endl;
}

void fltadd()
{
	float a = 2.34E+22f;
	float b = a + 1.0f;

	cout << "a = " << a << endl;
	cout << "b - a = " << b - a << endl;
}

void floatnum()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);

	float tub = 10.0 / 3.0;
	double mint = 10.0 / 3.0;
	const float million = 1.0e6;

	cout << "tub = " << tub;
	cout << ", a million tubs = " << million * tub;
	cout << ", \nten million tubs = ";
	cout << 10 * million * tub << endl;

	cout << "mint = " << mint << " and a million mints = ";
	cout << million * mint << endl;
}

void bondini()
{
	cout << "\a��ȣ�� \"ȭ���� ����\" ������ ��� ���õǾ����ϴ�!\n";
	cout << "8�ڸ� ��й�ȣ�� �Է��Ͻʽÿ�:________\b\b\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "\a�Է��Ͻ� ��й�ȣ�� " << code << "�Դϴ�.\n";
	cout << "\a��й�ȣ�� �½��ϴ�! Z3 ��ȹ�� �����Ͻʽÿ�!\n";
}

void morechar()
{
	char ch = 'M';
	int i = ch;
	cout << ch << "�� ASCII �ڵ�� " << i << "�Դϴ�." << endl;

	cout << "�� ���� �ڵ忡 1�� ���� ���ڽ��ϴ�. " << endl;
	ch = ch + 1;
	i = ch;
	cout << ch << "�� ASCII �ڵ�� " << i << "�Դϴ�." << endl;

	cout << "cout.put(ch)�� ����Ͽ� char�� ���� ch�� ȭ�鿡 ���: ";
	cout.put(ch);

	cout.put('!');

	cout << endl << "����" << endl;
}

void hexoct2()
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "�մ� ���Ŵ� �Ѹ���� ���� �ݴϴ�!\n";
	cout << "�����ѷ� " << chest << " (10����) " << endl;
	cout << hex;
	cout << "�㸮�ѷ� " << waist << " (16����) " << endl;
	cout << oct;
	cout << "�νɱ��� " << inseam << " (8����) " << endl;

}

void hexoct1()
{
	int chest = 42;
	int waist = 0x42;
	int inseam = 042;

	cout << "�մ� ���Ŵ� �Ѹ���� ���� �ݴϴ�!\n";
	cout << "�����ѷ� " << chest << "\n";
	cout << "�㸮�ѷ� " << waist << "\n";
	cout << "�νɱ��� " << inseam << "\n";

}

void maxmin()
{
	short Dohee = SHRT_MAX;
	unsigned short Insuk = Dohee;

	cout << "������ ���¿��� " << Dohee << "���� ��� �ְ�, ";
	cout << "�μ����� ���¿��� " << Insuk << "���� ��� �ִ�." << endl;
	cout << "������ ���¿� 1���� �Ա��Ѵ�." << endl << "���� ";
	Dohee = Dohee + 1;
	Insuk = Insuk + 1;
	cout << "������ �ܰ�� " << Dohee << "���� �Ǿ���, ";
	cout << "�μ����� �ܰ�� " << Insuk << "���� �Ǿ���." << endl;
	cout << "�̷� ����! ���� �� ���� ������ �߳�?" << endl;
	Dohee = ZERO;
	Insuk = ZERO;

	cout << "������ ���¿��� " << Dohee << "���� ��� �ְ�, ";
	cout << "�μ����� ���¿��� " << Insuk << "���� ��� �ִ�." << endl;
	cout << "������ ���¿� 1���� �����Ѵ�." << endl << "���� ";
	Dohee = Dohee - 1;
	Insuk = Insuk - 1;
	cout << "������ �ܰ�� " << Dohee << "���� �Ǿ���, ";
	cout << "�μ����� �ܰ�� " << Insuk << "���� �Ǿ���." << endl;
	cout << "�̷� ����! �μ��̰� ���ǿ� ��÷�Ǿ���?" << endl;
}

void looksize()
{
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	cout << "int�� " << sizeof(int) << " ����Ʈ�̴�." << endl;
	cout << "short�� " << sizeof n_short << " ����Ʈ�̴�." << endl;
	cout << "long�� " << sizeof n_long << " ����Ʈ�̴�." << endl << endl;
	cout << "long long�� " << sizeof n_llong << " ����Ʈ�̴�." << endl;
	cout << endl;

	cout << "�ִ�:" << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long " << n_llong << endl;
	cout << "int�� �ּڰ� = " << INT_MIN << endl;
	cout << "����Ʈ �� ��Ʈ �� = " << CHAR_BIT << endl;
}
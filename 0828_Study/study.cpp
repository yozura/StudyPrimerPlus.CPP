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
	cout << "바다오리 = " << auks << ", 박쥐 = " << bats;
	cout << ", 검둥오리 = " << coots << endl;

	char ch = 'Z';
	cout << "코드 " << ch << "의 값은 ";
	cout << int(ch) << endl;
	cout << "네, 코드 Z의 값은 ";
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

	cout << "당신의 체중을 파운드 단위로 입력하십시오: ";
	cin >> lbs;
	int stone = lbs / Lbs_per_stn;
	int pounds = lbs % Lbs_per_stn;
	cout << lbs << " 파운드는 " << stone << " 스톤, " << pounds << " 파운드입니다.\n";
}

void divide()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "정수 나눗셈: 9/5 = " << 9 / 5 << endl;
	cout << "부동 소수점수 나눗셈: 9.0/5.0 = ";
	cout << 9.0 / 5.0 << endl;
	cout << "혼합 나눗셈: 9.0/5 = " << 9.0 / 5 << endl;
	cout << "double형 상수: 1e7/9.0 = ";
	cout << 1.e7 / 9.0 << endl;
	cout << "float형 상수: 1e7f/9.0f = ";
	cout << 1.e7f / 9.0f << endl;
}

void arith()
{
	float hats, heads;

	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "수를 하나 입력하십시오: ";
	cin >> hats;
	cout << "다른 수를 입력하십시오: ";
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
	cout << "\a암호명 \"화려한 외출\" 작전이 방금 개시되었습니다!\n";
	cout << "8자리 비밀번호를 입력하십시오:________\b\b\b\b\b\b\b\b";
	long code;
	cin >> code;
	cout << "\a입력하신 비밀번호는 " << code << "입니다.\n";
	cout << "\a비밀번호가 맞습니다! Z3 계획을 진행하십시오!\n";
}

void morechar()
{
	char ch = 'M';
	int i = ch;
	cout << ch << "의 ASCII 코드는 " << i << "입니다." << endl;

	cout << "이 문자 코드에 1을 더해 보겠습니다. " << endl;
	ch = ch + 1;
	i = ch;
	cout << ch << "의 ASCII 코드는 " << i << "입니다." << endl;

	cout << "cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력: ";
	cout.put(ch);

	cout.put('!');

	cout << endl << "종료" << endl;
}

void hexoct2()
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "손님 몸매는 한마디로 끝내 줍니다!\n";
	cout << "가슴둘레 " << chest << " (10진수) " << endl;
	cout << hex;
	cout << "허리둘레 " << waist << " (16진수) " << endl;
	cout << oct;
	cout << "인심길이 " << inseam << " (8진수) " << endl;

}

void hexoct1()
{
	int chest = 42;
	int waist = 0x42;
	int inseam = 042;

	cout << "손님 몸매는 한마디로 끝내 줍니다!\n";
	cout << "가슴둘레 " << chest << "\n";
	cout << "허리둘레 " << waist << "\n";
	cout << "인심길이 " << inseam << "\n";

}

void maxmin()
{
	short Dohee = SHRT_MAX;
	unsigned short Insuk = Dohee;

	cout << "도희의 계좌에는 " << Dohee << "원이 들어 있고, ";
	cout << "인숙이의 계좌에도 " << Insuk << "원이 들어 있다." << endl;
	cout << "각각의 계좌에 1원씩 입금한다." << endl << "이제 ";
	Dohee = Dohee + 1;
	Insuk = Insuk + 1;
	cout << "도희의 잔고는 " << Dohee << "원이 되었고, ";
	cout << "인숙이의 잔고는 " << Insuk << "원이 되었다." << endl;
	cout << "이럴 수가! 도희가 나 몰래 대출을 했나?" << endl;
	Dohee = ZERO;
	Insuk = ZERO;

	cout << "도희의 계좌에는 " << Dohee << "원이 들어 있고, ";
	cout << "인숙이의 계좌에도 " << Insuk << "원이 들어 있다." << endl;
	cout << "각각의 계좌에 1원씩 인출한다." << endl << "이제 ";
	Dohee = Dohee - 1;
	Insuk = Insuk - 1;
	cout << "도희의 잔고는 " << Dohee << "원이 되었고, ";
	cout << "인숙이의 잔고는 " << Insuk << "원이 되었다." << endl;
	cout << "이럴 수가! 인숙이가 복권에 당첨되었나?" << endl;
}

void looksize()
{
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	cout << "int는 " << sizeof(int) << " 바이트이다." << endl;
	cout << "short는 " << sizeof n_short << " 바이트이다." << endl;
	cout << "long은 " << sizeof n_long << " 바이트이다." << endl << endl;
	cout << "long long은 " << sizeof n_llong << " 바이트이다." << endl;
	cout << endl;

	cout << "최댓값:" << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long " << n_llong << endl;
	cout << "int의 최솟값 = " << INT_MIN << endl;
	cout << "바이트 당 비트 수 = " << CHAR_BIT << endl;
}
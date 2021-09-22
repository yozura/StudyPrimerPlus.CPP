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

	cout << "입력 이전에 charr에 있는 문자열의 길이: " << strlen(charr) << endl;
	cout << "입력 이전에 str에 있는 문자열의 길이: " << str.size() << endl;
	cout << "텍스트 한 행을 입력하시오:\n";
	cin.getline(charr, 20);
	cout << "입력한 텍스트: " << charr << endl;
	cout << "또 다른 텍스트 한 행을 입력하시오:\n";
	getline(cin, str);
	cout << "입력한 텍스트: " << str << endl;
	cout << "입력 이후에 charr에 있는 문자열의 길이: ";
	cout << strlen(charr) << endl;
	cout << "입력 이후에 str에 있는 문자열의 길이: ";
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

	cout << str1 << " 문자열에는 " << len1 << "개의 문자가 들어있다.\n";
	cout << charr2 << " 문자열에는 " << len2 << "개의 문자가 들어있다.\n";
}

void strtype2()
{
	string s1 = "penguin";
	string s2, s3;

	cout << "string 객체를 string 객체에 대입할 수 있다: s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << ", s2: " << s2 << endl;
	cout << "string 객체에 C 스타일 문자열을 대입할 수 있다.\n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2: " << s2 << endl;
	cout << "string 객체들을 결합할 수 있다: s3 = s1 + s2\n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "string 객체들을 추가할 수 있다.\n";
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

	cout << "고양이과의 동물 한 종을 입력하시오: ";
	cin >> charr1;
	cout << "고양이과의 또 다른 동물 한 종을 입력하시오: ";
	cin >> str1;
	cout << "아래 동물들은 모두 고양이과입니다:\n";
	cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;
	cout << charr2 << "에서 세 번째 글자: " << charr2[2] << endl;
	cout << str2 << "에서 세 번째 글자 : " << str2[2] << endl;
}

void numstr()
{
	cout << "지금 사시는 아파트에 언제 입주하셨습니까?\n";
	int year;
	(cin >> year).get();
	cout << "사시는 도시를 말씀해 주시겠습니까?\n";
	char address[80];
	cin.getline(address, 80);
	cout << "아파트 입주 연도: " << year << endl;
	cout << "도시: " << address << endl;
	cout << "등록이 완료되었습니다!\n";
}

void instr3()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "이름을 입력하십시오: \n";
	cin.get(name, ArSize).get();
	cout << "좋아하는 디저트를 입력하십시오:\n";
	cin.get(dessert, ArSize).get();
	cout << "맛있는 " << dessert;
	cout << " 디저트를 준비하겠습니다. " << name << "님!\n";
}

void instr2()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "이름을 입력하십시오:\n";
	cin.getline(name, ArSize);
	cout << "좋아하는 디저트를 입력하십시오:\n";
	cin.getline(dessert, ArSize);
	cout << "맛있는 " << dessert;
	cout << " 디저트를 준비하겠습니다. " << name << " 님! \n";
}

void instr1()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "이름을 입력하십시오:\n";
	cin >> name;
	cout << "좋아하는 디저트를 입력하십시오:\n";
	cin >> dessert;
	cout << "맛있는 " << dessert;
	cout << " 디저트를 준비하겠습니다. " << name << " 님! \n";
}

void strings()
{
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	cout << "안녕하세요! 저는 " << name2;
	cout << "입니다! 실례지만 성함이?\n";
	cin >> name1;

	cout << "아, " << name1 << " 씨! 당신의 이름은 ";
	cout << strlen(name1) << "자입니다만 \n";
	cout << sizeof(name1) << "바이트 크기의 배열에 저장되었습니다.\n";
	cout << "이름이 " << name1[0] << "자로 시작하는군요.\n";
	name2[3] = '\0';
	cout << "제 이름의 처음 세 문자는 다음과 같습니다: ";
	cout << name2 << endl;
}

void arrayone()
{
	int yams[3];
	yams[0] = 7;
	yams[1] = 8;
	yams[2] = 6;

	int yamcosts[3] = { 200, 300, 50 };

	cout << "고구마 합계 = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << yams[1] << "개가 들어 있는 포장은 ";
	cout << "개당 " << yamcosts[1] << "원씩입니다.\n";

	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1] + yams[2] * yamcosts[2];
	cout << "세 포장의 총 가격은 " << total << "원 입니다.\n";
	cout << "\nyams 배열의 크기는 " << sizeof yams;
	cout << "바이트입니다.";
	cout << "원소 하나의 크기는 " << sizeof yams[0];
	cout << "바이트입니다.\n";
}
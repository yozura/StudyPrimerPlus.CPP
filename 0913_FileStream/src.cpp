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
	cout << "데이터 파일의 이름을 입력하시오: ";
	cin.getline(fileName, SIZE);
	inFile.open(fileName); // 입력받은 문자열을 파일 이름으로 결정
	if (!inFile.is_open())
	{
		cout << fileName << " 파일을 열 수 없습니다." << endl;
		cout << "프로그램을 종료합니다.\n";
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
		cout << "파일의 끝에 도달했습니다.\n";
	else if (inFile.fail())
		cout << "데이터 불일치로 입력이 종료되었습니다.\n";
	else
		cout << "알 수 없는 이유로 입력이 종료되었습니다.\n";

	if (count == 0)
		cout << "데이터가 없습니다.";
	else
	{
		cout << "읽은 항목의 개수: " << count << endl;
		cout << "합계: " << sum << endl;
		cout << "평균: " << sum / count << endl;
	}

	inFile.close();
}

void outfile()
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile; // 출력을 위한 객체 생성
	outFile.open("carinfo.txt"); // 파일에 연결

	cout << "자동차 메이커와 차종을 입력하시오: ";
	cin.getline(automobile, 50);
	cout << "연식을 입력하시오 : ";
	cin >> year;
	cout << "구입가를 입력하시오 : ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	// cout으로 스크린에 디스플레이
	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "메이커와 차종: " << automobile << endl;
	cout << "연식: " << year << endl;
	cout << "구입가 $" << a_price << endl;
	cout << "중고가 $" << d_price << endl;

	// outFile로 파일에 출력
	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "메이커와 차종: " << automobile << endl;
	outFile << "연식: " << year << endl;
	outFile << "구입가 $" << a_price << endl;
	outFile << "중고가 $" << d_price << endl;
	outFile.close();
}
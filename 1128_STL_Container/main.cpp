#include <iostream>
#include <string>
#include <initializer_list>
#include <list>
#include <valarray>
#include <set>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>
#include <cctype>

typedef int KeyType;
typedef std::pair<const KeyType, std::string> Pair;
typedef std::multimap<KeyType, std::string> MapCode;

template<class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T& t) : cutoff(t) {}
	bool operator()(const T& v) { return v > cutoff; }
};

void outint(int n) { std::cout << n << " "; }
void show(double);
const int LIM = 10;

char toLower(char ch) { return tolower(ch); }
std::string& ToLower(std::string& st);
void display(const std::string& s);

const int SIZE = 12;
typedef std::valarray<int> vint;
void show2(const vint& v, int cols);

double sum(std::initializer_list<double> il);
double average(const std::initializer_list<double>& ril);

bool isPalindrome(std::string& s);

void exam1();
void exam2();

int main()
{
	exam2();
	return 0;
}

void exam2()
{
	std::string input;
	std::cout << "문자열을 입력하세요(끝내려면 quit): ";
	while (std::getline(std::cin, input) && input != "quit")
	{
		if (isPalindrome(input))
			std::cout << "회문입니다.\n";
		else
			std::cout << "회문이 아닙니다.\n";

		std::cout << "다음 문자열을 입력하세요(끝내려면 quit): ";
	}
}

bool isPalindrome(std::string& s)
{
	// 원본을 수정하고 복사본 생성
	// 1. 소문자 변환
	// 2. 특수 문자 삭제
	// 3. 공백 삭제
	
	std::transform(s.begin(), s.end(), s.begin(), toLower);
	std::string tempStr1;
	int size = s.size();
	for (int i = 0; i < size; i++)
		if (isalpha(s[i]))
			tempStr1 += s[i];

	std::string tempStr2;
	std::string::reverse_iterator riter;
	for (riter = tempStr1.rbegin(); riter != tempStr1.rend(); riter++)
		tempStr2 += *riter;

	std::cout << tempStr1 << " : " << tempStr2 << '\n';
	if (tempStr1 == tempStr2)
		return true;
	else
		return false;
}

void exam1()
{
	std::string input;
	std::cout << "문자열을 입력하세요(끝내려면 quit): ";
	while (std::cin >> input && input != "quit")
	{
		if (isPalindrome(input))
			std::cout << "회문입니다.\n";
		else
			std::cout << "회문이 아닙니다.\n";

		std::cout << "다음 문자열을 입력하세요(끝내려면 quit): ";
	}
}

double sum(std::initializer_list<double> il)
{
	double tot = 0;
	for (auto p = il.begin(); p != il.end(); p++)
		tot += *p;
	return tot;
}

double average(const std::initializer_list<double>& ril)
{
	double tot = 0;
	int n = ril.size();
	double ave = 0.0;
	if (n > 0)
	{
		for (auto p = ril.begin(); p != ril.end(); p++)
			tot += *p;
		ave = tot / n;
	}
	return ave;
}

void ilist()
{
	using std::cout;
	cout << "목록 1 : 합계 = " << sum({ 2, 3, 4 }) << ", 평균 = " << average({ 2, 3, 4 }) << '\n';
	std::initializer_list<double> dl = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	cout << "목록 2 : 합계 = " << sum(dl) << ", 평균 = " << average(dl) << '\n';
	dl = { 16.0, 25.0, 36.0, 40.0, 64.0 };
	cout << "목록 3 : 합계 = " << sum(dl) << ", 평균 = " << average(dl) << '\n';
}

void show2(const vint& v, int cols)
{
	using std::cout;
	using std::endl;

	int lim = v.size();
	for (int i = 0; i < lim; i++)
	{
		cout.width(3);
		cout << v[i];
		if (i % cols == cols - 1)
			cout << endl;
		else
			cout << ' ';
	}
	if (lim % cols != 0)
		cout << endl;
}

void vslice()
{
	using std::slice;
	using std::cout;
	vint valint(SIZE);

	srand(time(0));
	int i;
	for (i = 0; i < SIZE; i++)
		valint[i] = std::rand() % 10;
	cout << "원래의 배열:\n";
	show2(valint, 3);
	vint vcol(valint[slice(1, 4, 3)]);
	cout << "제 2 열:\n";
	show2(vcol, 1);
	vint vrow(valint[slice(3, 3, 1)]);
	cout << "제 2 행:\n";
	show2(vrow, 3);
	valint[slice(2, 4, 3)] = 10;
	cout << "마지막 열을 값 10으로 설정:\n";
	show2(valint, 3);
	cout << "제1열을 그 다음 두 열의 합으로 설정:\n";
	valint[slice(0, 4, 3)] = vint(valint[slice(1, 4, 3)]) + vint(valint[slice(2, 4, 3)]);
	show2(valint, 3);
}

void valvect()
{
	using namespace std;
	vector<double> data;
	double temp;

	cout << "수들을 입력하시오(끝내려면 <= 0)\n";
	while (cin >> temp && temp > 0)
		data.push_back(temp);
	sort(data.begin(), data.end());
	int size = data.size();
	valarray<double> numbers(size);
	int i;
	for (i = 0; i < size; i++)
		numbers[i] = data[i];
	valarray<double> sq_rts(size);
	sq_rts = sqrt(numbers);
	valarray<double> results(size);
	results = numbers + 2.0 * sq_rts;
	cout.setf(ios_base::fixed);
	cout.precision(4);
	for (i = 0; i < size; i++)
	{
		cout.width(8);
		cout << numbers[i] << ": ";
		cout.width(8);
		cout << results[i] << endl;
	}
	cout << "프로그램을 종료합니다.";
}

std::string& ToLower(std::string& st)
{
	std::transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}

void display(const std::string& s)
{
	std::cout << s << " ";
}

void usealgo()
{
	using namespace std;

	vector<string> words;
	cout << "단어들을 입력하십시오(끝내려면 quit):\n";
	string input;
	while (cin >> input && input != "quit")
		words.push_back(input);
	cout << "다음과 같은 단어들을 입력하셨습니다.\n";
	for_each(words.begin(), words.end(), display);
	cout << endl;

	// 단어들을 소문자로 변환하여 집합에 삽입
	set<string> wordset;
	transform(words.begin(), words.end(), insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);
	cout << "\n단어들의 알파벳순 리스트:\n";
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	// 단어와 빈도를 맵에 넣는다.
	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin(); si != wordset.end(); si++)
		wordmap[*si] = count(words.begin(), words.end(), *si);

	// 맵의 내용을 출력한다
	cout << "\n단어별 빈도:\n";
	for (si = wordset.begin(); si != wordset.end(); si++)
		cout << *si << ": " << wordmap[*si] << endl;

	map<string, int>::iterator iter;
	cout << "\t키\t값" << endl;
	for (iter = wordmap.begin(); iter != wordmap.end(); iter++)
		cout << (*iter).first << " " << (*iter).second << endl;
}

void removeTest()
{
	using namespace std;
	int ar[LIM] = { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };
	list<int> la(ar, ar + LIM);
	list<int> lb(la);
	cout << "오리지널 리스트의 내용:\n\t";
	for_each(la.begin(), la.end(), show);
	cout << endl;
	la.remove(4);
	cout << "remove() 메서드를 사용한 후:\n";
	cout << "la:\t";
	for_each(la.begin(), la.end(), show);
	cout << endl;
	list<int>::iterator last;
	last = remove(lb.begin(), lb.end(), 4);
	cout << "remove() 함수를 사용한 후:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), show);
	cout << endl;
	lb.erase(last, lb.end());
	cout << "erase() 메서드를 사용한 후:\n";
	cout << "lb:\t";
	for_each(lb.begin(), lb.end(), show);
	cout << endl;
}

void stringSTL()
{
	using namespace std;
	string letters;
	cout << "글자 그룹을 입력하십시오(끝내려면 quit): ";
	while (cin >> letters && letters != "quit")
	{
		cout << letters << "의 모든 치환들: " << endl;
		sort(letters.begin(), letters.end());
		cout << letters << endl;
		while (next_permutation(letters.begin(), letters.end()))
			cout << letters << endl;
		cout << "다음 시퀀스를 입력하십시오(끝내려면 quit): ";
	}

	cout << "프로그램을 종료합니다.\n";
}

void show(double v)
{
	//std::cout.width(6);
	std::cout << v << ' ';
}

void functor2Test()
{
	using namespace std;
	double arr1[LIM] = { 28, 29, 30, 35, 38, 59 };
	double arr2[LIM] = { 63, 65, 69, 75, 80, 99 };
	vector<double> gr8(arr1, arr1 + LIM);
	vector<double> m8(arr2, arr2 + LIM);
	cout.setf(ios_base::fixed);
	cout.precision(1);
	cout << "gr8:\t";
	for_each(gr8.begin(), gr8.end(), show);
	cout << endl;
	cout << "m8:\t";
	for_each(m8.begin(), m8.end(), show);
	cout << endl;

	vector<double> sum(LIM);
	transform(gr8.begin(), gr8.end(), m8.begin(), sum.begin(), plus<double>());
	cout << "sum:\t";
	for_each(sum.begin(), sum.end(), show);
	cout << endl;

	vector<double> prod(LIM);
	transform(gr8.begin(), gr8.end(), prod.begin(), bind1st(multiplies<double>(), 2.5));
	cout << "prod:\t";
	for_each(prod.begin(), prod.end(), show);
	cout << endl;
}

void functorTest()
{
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100); // 제한 = 100
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);
	cout << "원래의 리스트:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);

	yadayada.remove_if(f100); // 이름 있는 함수 객체 사용.
	etcetera.remove_if(TooBig<int>(200)); // 함수 객체 생성

	cout << "\n정비된 리스트:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
}

void MultimapTest()
{
	using namespace std;
	MapCode codes;

	codes.insert(Pair(415, "샌프란시스코"));
	codes.insert(Pair(510, "오클랜드"));
	codes.insert(Pair(718, "브루클린"));
	codes.insert(Pair(718, "스태튼 섬"));
	codes.insert(Pair(415, "샌라파엘"));
	codes.insert(Pair(510, "버클리"));

	cout << "지역 코드가 415인 도시 수: " << codes.count(415) << endl;
	cout << "지역 코드가 718인 도시 수: " << codes.count(718) << endl;
	cout << "지역 코드가 510인 도시 수: " << codes.count(510) << endl;
	cout << "지역 코드 도시\n";
	MapCode::iterator it;
	for (it = codes.begin(); it != codes.end(); it++)
		cout << "    " << (*it).first << "    " << (*it).second << endl;

	pair<MapCode::iterator, MapCode::iterator> range = codes.equal_range(718);
	cout << "지역 코드가 718인 도시들:\n";
	for (it = range.first; it != range.second; it++)
		cout << "    " << (*it).first << "    " << (*it).second << endl;
}

void setTest()
{
	using namespace std;
	const int N = 6;
	string s1[N] = { "buffon", "thinkers", "for", "heavy", "can", "for" };
	string s2[N] = { "metal", "any", "food", "elegant", "deliver", "for" };

	set<string> A(s1, s1 + N);
	set<string> B(s2, s2 + N);

	ostream_iterator<string, char> out(cout, " ");
	cout << "집합 A: ";
	copy(A.begin(), A.end(), out);
	cout << endl;
	cout << "집합 B: ";
	copy(B.begin(), B.end(), out);
	cout << endl;

	cout << "A와 B의 합집합:\n";
	// 집합 A의 범위, 집합 B의 범위, 출력할 위치
	set_union(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "A와 B의 교집합:\n";
	set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "A와 B의 차집합:\n";
	set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
	cout << endl;

	cout << "B와 A의 차집합:\n";
	set_difference(B.begin(), B.end(), A.begin(), A.end(), out);
	cout << endl;

	set<string> C;
	cout << "집합 C:\n";
	set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
	copy(C.begin(), C.end(), out);
	cout << endl;

	string s3("grungy");
	C.insert(s3);
	cout << "삽입한 후의 집합 C:\n";
	copy(C.begin(), C.end(), out);
	cout << endl;

	cout << "특정 범위를 표시:\n";
	copy(C.lower_bound("ghost"), C.upper_bound("spook"), out);
	cout << endl;
}
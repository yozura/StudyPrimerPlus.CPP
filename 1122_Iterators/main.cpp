#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
	



}	

void outint(int n) { cout << n << " "; }

void listit()
{
	list<int> one(5, 2);
	int stuff[5] = { 1, 2, 4, 8, 6 };
	list<int> two;
	two.insert(two.begin(), stuff, stuff + 5);
	int more[6] = { 6, 4, 2, 4, 6, 5 };
	list<int> three(two);
	three.insert(three.end(), more, more + 6);

	cout << "리스트 one : ";
	for_each(one.begin(), one.end(), outint);
	cout << endl << "리스트 two : ";
	for_each(two.begin(), two.end(), outint);
	cout << endl << "리스트 three : ";
	for_each(three.begin(), three.end(), outint);
	three.remove(2);
	cout << endl << "리스트 three에서 2 전부 삭제 : ";
	for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);
	cout << endl << "리스트 one을 접목시킨 리스트 three : ";
	for_each(three.begin(), three.end(), outint);
	cout << endl << "리스트 one : ";
	for_each(one.begin(), one.end(), outint);
	three.unique();
	cout << endl << "단일화 후의 리스트 three : ";
	for_each(three.begin(), three.end(), outint);
	three.sort();
	three.unique();
	cout << endl << "정렬과 단일화 후의 리스트 three : ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);
	cout << endl << "정렬된 리스트 two를 리스트 three에 합병 : ";
	for_each(three.begin(), three.end(), outint);
	cout << endl;
}

void output(const string& s) { cout << s << " "; }

void inserts()
{
	string s1[4] = { "fine", "fish", "fashion", "fate" };
	string s2[2] = { "busy", "bats" };
	string s3[2] = { "silly", "singers" };
	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	for_each(words.begin(), words.end(), output);
	cout << endl;

	copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
	for_each(words.begin(), words.end(), output);
	cout << endl;

	copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
	for_each(words.begin(), words.end(), output);
	cout << endl;
}

void copyit()
{
	int casts[10] = { 6, 7, 2, 9, 4, 11, 8, 7, 10, 5 };
	int temps[10] = { 0 };
	vector<int> dice(10);

	// 배열 casts의 시작 주소에서부터 끝까지 dice 벡터에 복사
	copy(casts, casts + 10, dice.begin());
	copy(casts, casts + 10, temps);
	cout << "주사위를 던져라!\n";
	ostream_iterator<int, char> out_iter(cout, " ");
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "역방향 이터레이터의 암시적 사용:\n";
	copy(dice.rbegin(), dice.rend(), out_iter);

	cout << "\n정방향 이터레이터의 명시적 사용:\n";
	vector<int>::iterator iter;
	for (iter = dice.begin(); iter != dice.end(); iter++)
		cout << *iter << ' ';

	cout << endl;
	cout << "역방향 이터레이터의 명시적 사용:\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ' ';
}
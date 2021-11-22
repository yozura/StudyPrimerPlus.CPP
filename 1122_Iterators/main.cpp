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

	cout << "����Ʈ one : ";
	for_each(one.begin(), one.end(), outint);
	cout << endl << "����Ʈ two : ";
	for_each(two.begin(), two.end(), outint);
	cout << endl << "����Ʈ three : ";
	for_each(three.begin(), three.end(), outint);
	three.remove(2);
	cout << endl << "����Ʈ three���� 2 ���� ���� : ";
	for_each(three.begin(), three.end(), outint);
	three.splice(three.begin(), one);
	cout << endl << "����Ʈ one�� �����Ų ����Ʈ three : ";
	for_each(three.begin(), three.end(), outint);
	cout << endl << "����Ʈ one : ";
	for_each(one.begin(), one.end(), outint);
	three.unique();
	cout << endl << "����ȭ ���� ����Ʈ three : ";
	for_each(three.begin(), three.end(), outint);
	three.sort();
	three.unique();
	cout << endl << "���İ� ����ȭ ���� ����Ʈ three : ";
	for_each(three.begin(), three.end(), outint);
	two.sort();
	three.merge(two);
	cout << endl << "���ĵ� ����Ʈ two�� ����Ʈ three�� �պ� : ";
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

	// �迭 casts�� ���� �ּҿ������� ������ dice ���Ϳ� ����
	copy(casts, casts + 10, dice.begin());
	copy(casts, casts + 10, temps);
	cout << "�ֻ����� ������!\n";
	ostream_iterator<int, char> out_iter(cout, " ");
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "������ ���ͷ������� �Ͻ��� ���:\n";
	copy(dice.rbegin(), dice.rend(), out_iter);

	cout << "\n������ ���ͷ������� ����� ���:\n";
	vector<int>::iterator iter;
	for (iter = dice.begin(); iter != dice.end(); iter++)
		cout << *iter << ' ';

	cout << endl;
	cout << "������ ���ͷ������� ����� ���:\n";
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ' ';
}
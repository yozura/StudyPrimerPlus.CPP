#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

const int NUM = 26;
const string wordlist[NUM] = {
	"apiary", "beetle", "cereasl", "danger", "ensign",
	"florid", "garage", "health", "insult", "jackal",
	"keeper", "loaner", "manage", "nonce", "onset", "plaid",
	"quilt", "remote", "stolid", "train", "useful",
	"valid", "whence", "xenon", "yearn", "zippy"
};
	
int main()
{
	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";
	cout << "ũ��:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	cout << "�뷮:\n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;
	empty.reserve(50);
	cout << "empty.reserve(50) ���� �뷮: " << empty.capacity() << endl;
	
	return 0;
}

void useStringMethodFindNpos()
{
	srand(time(0));
	char play;
	cout << "���ܾ� ������ �����Ͻðڽ��ϱ�? <y/n>";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "�������� �ܾ ������ ���ʽÿ�.\n";
		cout << length << "���� ���ڷ� �̷���� �ֽ��ϴ�.\n";
		cout << "�� ���� �� ���ھ� �����Ͻʽÿ�.\n";
		cout << "Ʋ�� �� �ִ� ��ȸ: " << guesses << "��\n";
		cout << "�����ϴ� �ܾ�: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "���ڸ� �����Ͻʽÿ�: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "�̹� ������ �����Դϴ�. �ٽ� �Ͻʽÿ�.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "��! Ʋ�Ƚ��ϴ�.\n";
				guesses--;
				badchars += letter;
			}
			else
			{
				cout << "������! �¾ҽ��ϴ�.\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}

			cout << "�����ϴ� �ܾ�: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Ʋ���� ������ ���ڵ�: " << badchars << endl;

				cout << "Ʋ�� �� �ִ� ��ȸ: " << guesses << "��\n";
			}
		}
		if (guesses > 0)
			cout << "�׷����ϴ�. �װ��� �������� �ܾ��Դϴ�.\n";
		else
			cout << "��Ÿ�����ϴ�. �������� �ܾ�� " << target << "�Դϴ�.\n";

		cout << "������ �ٽ� �Ͻðڽ��ϱ�? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "���α׷��� �����մϴ�.\n";
}

void useFileInputString()
{
	ifstream fin;
	fin.open("tobuy.txt");
	if (fin.is_open() == false)
	{
		cerr << "������ �� �� �����ϴ�.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, ':');
	while (fin)
	{
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "���α׷��� �����մϴ�.\n";
	fin.close();
}

void useStringCreator()
{
	string one("Lottery Winner!");
	cout << one << endl;
	string two(20, '$');
	cout << two << endl;
	string three(one);
	cout << three << endl;
	one += " Oops!";
	cout << one << endl;
	two = "Sorry ! That was ";
	three[0] = 'P';
	string four;
	four = two + three;
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls, 20);
	cout << five << "!\n";
	string six(alls + 6, alls + 10);
	cout << six << ", ";
	string seven(&five[6], &five[10]);
	cout << seven << "...\n";
	string eight(four, 7, 16);
	cout << eight << " in motion!" << endl;
}
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
	cout << "크기:\n";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	cout << "용량:\n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;
	empty.reserve(50);
	cout << "empty.reserve(50) 이후 용량: " << empty.capacity() << endl;
	
	return 0;
}

void useStringMethodFindNpos()
{
	srand(time(0));
	char play;
	cout << "영단어 게임을 시작하시겠습니까? <y/n>";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[rand() % NUM];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "수수께끼 단어를 추측해 보십시오.\n";
		cout << length << "개의 문자로 이루어져 있습니다.\n";
		cout << "한 번에 한 문자씩 추측하십시오.\n";
		cout << "틀릴 수 있는 기회: " << guesses << "번\n";
		cout << "추측하는 단어: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "문자를 추측하십시오: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos)
			{
				cout << "이미 추측한 문자입니다. 다시 하십시오.\n";
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos)
			{
				cout << "땡! 틀렸습니다.\n";
				guesses--;
				badchars += letter;
			}
			else
			{
				cout << "딩동댕! 맞았습니다.\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}

			cout << "추측하는 단어: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "틀리게 추측한 무자들: " << badchars << endl;

				cout << "틀릴 수 있는 기회: " << guesses << "번\n";
			}
		}
		if (guesses > 0)
			cout << "그렇습니다. 그것이 수수께끼 단어입니다.\n";
		else
			cout << "안타깝습니다. 수수께끼 단어는 " << target << "입니다.\n";

		cout << "게임을 다시 하시겠습니까? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "프로그램을 종료합니다.\n";
}

void useFileInputString()
{
	ifstream fin;
	fin.open("tobuy.txt");
	if (fin.is_open() == false)
	{
		cerr << "파일을 열 수 없습니다.\n";
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
	cout << "프로그램을 종료합니다.\n";
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
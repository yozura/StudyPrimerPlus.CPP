#include <iostream>
#include "tabtenn0.h"

int main()
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";
	player1.Name();
	if (player1.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";
	cout << "이름: ";
	rplayer1.Name();
	cout << "; 랭킹: " << rplayer1.Rating() << endl;
	RatedPlayer rplayer2(1212, player1);
	cout << "이름: ";
	rplayer2.Name();
	cout << "; 랭킹: " << rplayer2.Rating() << endl;

	TableTennisPlayer* player3 = &rplayer2;
	TableTennisPlayer& player4 = rplayer1;
	player3->Name();
	player4.Name();

	return 0;
}

void test1()
{
	using std::cout;
	TableTennisPlayer player1("Chunk", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.Name();
	if (player1.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";
	player2.Name();
	if (player2.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";
}
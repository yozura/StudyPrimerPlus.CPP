#include <iostream>
#include <vector>
#include <string>

const int NUM = 5;

struct Review {
	std::string title;
	int rating;
};

bool FillReview(Review& rr);
void ShowReview(const Review& rr);

int main()
{
	using std::vector;
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;
	
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	int num = books.size();
	if (num > 0)
	{
		cout << "감사합니다. 당신은 다음과 같이 입력하셨습니다.\n";
		cout << "등급\t제목\n";
		for (int i = 0; i < num; i++)
			ShowReview(books[i]);
		cout << "한번 더 출력한다:\n";
		cout << "등급\t제목\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
		vector<Review> oldlist(books);
		if (num > 3)
		{
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "삭제한 후:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
			cout << "삽입한 후:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout << "oldlist와 books를 교환한 후:\n";
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else
		cout << "입력한 것이 없어, 얻은 것이 없소이다.\n";

	return 0;
}

bool FillReview(Review& rr)
{
	std::cout << "책 제목을 입력하십시오(끝내려면 quit을 입력): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "책 등급(0~10)을 입력하시오: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n')
		continue;
	return true;
}

void ShowReview(const Review& rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}

void useVector()
{
	using std::vector;
	using std::string;
	using std::cin;
	using std::cout;
	using std::endl;

	vector<int> ratings(NUM);
	vector<string> titles(NUM);
	cout << NUM << "개의 책 제목과 책 등급(0~10)을 입력하십시오.\n";
	int i;
	for (i = 0; i < NUM; i++)
	{
		cout << i + 1 << "번 책의 제목을 입력하십시오: ";
		getline(cin, titles[i]);
		cout << i + 1 << "번 책의 등급(0~10)을 입력하십시오: ";
		cin >> ratings[i];
		cin.get();
	}
	cout << "감사합니다. 당신은 다음과 같이 입력하셨습니다.\n";
	cout << "등급\t제목\n";
	for (i = 0; i < NUM; i++)
		cout << ratings[i] << "\t" << titles[i] << endl;

}
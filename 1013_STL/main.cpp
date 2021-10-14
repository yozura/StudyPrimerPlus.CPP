#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int NUM = 5;

struct Review {
	std::string title;
	int rating;
};

bool operator<(const Review& r1, const Review& r2);
bool worseThan(const Review& r1, const Review& r2);
bool FillReview(Review& rr);
void ShowReview(const Review& rr);

int main()
{
	

	return 0;
}

bool operator<(const Review& r1, const Review& r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool worseThan(const Review& r1, const Review& r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}

void useAlgorithmShuffleSort()
{
	using namespace std;

	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "�����մϴ�. ����� ������ ���� " << books.size() << "���� å ����� �Է��ϼ̽��ϴ�.\n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end());
		cout << "å ������ �������� ����:\n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end(), worseThan);
		cout << "å ����� �������� ����:\n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);

		random_shuffle(books.begin(), books.end());
		cout << "������ ������ �ٽ� ��ġ:\n���\t����\n";
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "���α׷��� �����մϴ�.";
}

void useIterator()
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
		cout << "�����մϴ�. ����� ������ ���� �Է��ϼ̽��ϴ�.\n";
		cout << "���\t����\n";
		for (int i = 0; i < num; i++)
			ShowReview(books[i]);
		cout << "�ѹ� �� ����Ѵ�:\n";
		cout << "���\t����\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
		vector<Review> oldlist(books);
		if (num > 3)
		{
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "������ ��:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
			cout << "������ ��:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout << "oldlist�� books�� ��ȯ�� ��:\n";
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else
		cout << "�Է��� ���� ����, ���� ���� �����̴�.\n";
}

bool FillReview(Review& rr)
{
	std::cout << "å ������ �Է��Ͻʽÿ�(�������� quit�� �Է�): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "å ���(0~10)�� �Է��Ͻÿ�: ";
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
	cout << NUM << "���� å ����� å ���(0~10)�� �Է��Ͻʽÿ�.\n";
	int i;
	for (i = 0; i < NUM; i++)
	{
		cout << i + 1 << "�� å�� ������ �Է��Ͻʽÿ�: ";
		getline(cin, titles[i]);
		cout << i + 1 << "�� å�� ���(0~10)�� �Է��Ͻʽÿ�: ";
		cin >> ratings[i];
		cin.get();
	}
	cout << "�����մϴ�. ����� ������ ���� �Է��ϼ̽��ϴ�.\n";
	cout << "���\t����\n";
	for (i = 0; i < NUM; i++)
		cout << ratings[i] << "\t" << titles[i] << endl;

}
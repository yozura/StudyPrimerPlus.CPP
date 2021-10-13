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

	return 0;
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
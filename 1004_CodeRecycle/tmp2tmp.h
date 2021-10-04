#include <iostream>

template <typename T> void counts();
template <typename T> void report(T&);

template <typename TT>
class HasFriendT
{
private:
	TT item;
	static int ct;
public:
	HasFriendT(const TT& i) : item(i) { ct++; }
	~HasFriendT() { ct--; }
	friend void counts<TT>();
	friend void report<>(HasFriendT<TT>&);
};

template <typename T>
int HasFriendT<T>::ct = 0;

template <typename T>
void counts()
{
	std::cout << "ÅÛÇÃ¸´ Å©±â: " << sizeof(HasFriendT<T>) << "; ";
	std::cout << "ÅÛÇÃ¸´ counts(): " << HasFriendT<T>::ct << endl;
}

template <typename T>
void report(T& hf)
{
	std::cout << hf.item << endl;
}
#include <iostream>

template <typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T& i) : item(i) { }
	template <typename C, typename D> friend void show2(C&, D&);
};

template <typename C, typename D> void show2(C& c, D& d)
{
	std::cout << c.item << ", " << d.item << std::endl;
}
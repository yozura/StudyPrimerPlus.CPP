#pragma once
#ifndef STACKTP_H_
#define STACKTP_H_
template <typename Type>
class Stack
{
private:
	enum { MAX = 10 };
	int stackSize;
	Type* items;
	int top;
public:
	explicit Stack(int ss = SIZE); // 변환 함수 미사용
	Stack(const Stack& st); // 명시적 복사 생성자
	~Stack() { delete[] items; } // 명시적 파괴자
	bool isempty() { return top == 0; }
	bool isfull() { return top == stackSize; }
	bool push(const Type& item);
	bool pop(Type& item);
	Stack& operator=(const Stack& st);
};

template <typename Type>
Stack<Type>::Stack(int ss)
	: stackSize(ss), top(0)
{
	// 동적 생성
	items = new Type[stackSize];
}

template <typename Type>
Stack<Type>::Stack(const Stack& st)
{
	stackSize = st.stackSize;
	top = st.top;
	items = new Type[stackSize];
	for (int i = 0; i < stackSize; i++)
		items[i] = st.items[i];
}

template <typename Type>
bool Stack<Type>::push(const Type& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <typename Type>
bool Stack<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

template <typename Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& st)
{
	if (this == &st)
		return *this;
	delete[] items;
	stackSize = st.stackSize;
	top = st.top;
	items = new Type[stackSize];
	for (int i = 0; i < stackSize; i++)
		items[i] = st.items[i];
	return *this;
}
#endif // !STACKTP_H_
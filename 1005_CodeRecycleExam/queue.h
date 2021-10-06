#pragma once
#ifndef QUEUE_H_
#define QUEUE_H_
#include "stddef.h"
// ť(Queue) �ڷᱸ���� FIFO(First In First Out)�� �ֵ� Ư¡. �̰��� �� ������Ѵ�.
template <typename T>
class Queue
{
private:
	// �迭�� �ƴ� LinkedList �ڷᱸ���� ť�� �����Ѵ�.
	// �迭�� ���� �̵��� ȿ���� O(N)�̱� ����.
	// �׿� ���� LinkedList�� ��쿡�� �Ӹ��� ������ ���������ָ� �Ǳ� ������ O(1).
	// ���. �������� �����ϰ� ���� ����� �����ϴ� �����͸� ������.
	struct Node { T item; Node* next; };
	enum { Q_SIZE = 10 }; // ť�� ����Ʈ ���� ������
	Node* front; // ť�� �Ӹ��� ���
	Node* rear; // ť�� ������ ���
	int items; // ť�� �� �׸� ����
	const int size; // ť�� �� ������
	Queue(const Queue& q); // ����� ���� ������
	Queue& operator=(const Queue& q); // ����� ���� ������
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isEmpty() const { return items == 0; } // items�� 0�� ���� �׸��� �������� �ʾ� ť�� ����ִ� ��
	bool isFull() const { return items == size; } // items�� size�� ���� �׸��� ť�� �ִ� ������ұ��� ����ߴ� ��, �� ť�� ���� ������.
	int queuecount() const { return items; }
	T& peek() const;
	bool enqueue(const T& item); // ������ �׸��� �߰�
	bool dequeue(T& item); // �Ӹ����� �׸��� ����
};

template <typename T>
Queue<T>::Queue(int qs) : size(qs)
{
	// front, rere node�� ��� NULL�� �ʱ�ȭ
	front = rear = NULL;
	items = 0;
}

template <typename T>
Queue<T>::~Queue()
{
	// temp Node �����͸� ����
	Node* temp;
	// ��ü ����� �����͸� �� ������ front�� null�� �� ������ ����
	while (front != NULL)
	{
		// temp�� front �ּ� ����
		temp = front;
		// front ��ġ�� ���� �ܰ�� �̵�
		front = front->next;
		// ������ ����� front �ּҸ� ��������.
		delete temp;
	}
}

template <typename T>
T& Queue<T>::peek() const
{
	return rear->item;
}

template <typename T>
bool Queue<T>::enqueue(const T& item)
{
	// queue�� ���� ��������
	if (isFull())
		return false;
	// 1. �ӽ� ��� ����
	// 2. �ӽ� ��� item�� �߰��� item �߰�
	// 3. �ӽ� ��� next�� NULL �߰�, �ֳ��ϸ� ���� ���� �߰��Ǳ� ������
	// 4. �׸��� �þ�� ������ itmes ���������ֱ�
	// 5. front�� NULL �̸� �����濡 ��ġ
	// 6. �װ� �ƴ϶�� rear�� next ��, ���Ĺ濡 ��ġ
	// 7. ���������� rear�� ���Ĺ� ���� ������ add�� ����.
	Node* add = new Node;
	add->item = item;
	add->next = NULL;
	items++;
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template<typename T>
bool Queue<T>::dequeue(T& item)
{
	// front�� null�̸� false
	if (front == NULL)
		return false;
	// 1. ���� out�� item ������ front->item ���� �����Ѵ�.
	// 2. ť�� �׸��� �ϳ� ���ش�.
	// 3. �׸��� �ӽ� ��带 �����ؼ� front�� �����Ѵ�.
	// 4. �׸��� ���� front�� �������� front->next�� front�� �Ǿ�� �ϱ� ������ front�� �������ش�.
	// 5. �׸��� temp�� �����صξ��� front �ּҸ� �����Ѵ�.
	// 6. ���������� items�� ���� 0�� �Ǿ��ٸ� rear ���� ����� �����ϱ� ������ NULL�� ������ش�.
	item = front->item;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = NULL;
	return true;
}

#endif
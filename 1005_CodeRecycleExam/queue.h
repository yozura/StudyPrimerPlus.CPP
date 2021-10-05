#pragma once
#ifndef QUEUE_H_
#define QUEUE_H_
#include "stddef.h"
// 큐(Queue) 자료구조는 FIFO(First In First Out)이 주된 특징. 이것을 잘 살려야한다.
template <typename T>
class Queue
{
private:
	// 배열이 아닌 LinkedList 자료구조로 큐를 구성한다.
	// 배열은 원소 이동의 효율이 O(N)이기 때문.
	// 그에 반해 LinkedList의 경우에는 머리만 연결을 해제시켜주면 되기 때문에 O(1).
	// 노드. 아이템을 저장하고 다음 멤버를 지시하는 포인터를 가진다.
	struct Node { T item; Node* next; };
	enum { Q_SIZE = 10 }; // 큐의 디폴트 지정 사이즈
	Node* front; // 큐의 머릿단 노드
	Node* rear; // 큐의 꼬릿단 노드
	int items; // 큐의 현 항목 개수
	const int size; // 큐의 현 사이즈
	Queue(const Queue& q); // 명시적 복사 생성자
	Queue& operator=(const Queue& q); // 명시적 대입 연산자
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isEmpty() const { return items == 0; } // items가 0인 것은 항목이 존재하지 않아 큐가 비어있단 것
	bool isFull() const { return items == size; } // items가 size인 것은 항목이 큐의 최대 저장장소까지 사용했단 뜻, 즉 큐가 가득 차있음.
	int queuecount() const { return items; }
	T& peek() const;
	bool enqueue(const T& item); // 꼬리에 항목을 추가
	bool dequeue(T& item); // 머리에서 항목을 삭제
};

template <typename T>
Queue<T>::Queue(int qs) : size(qs)
{
	// front, rere node를 모두 NULL로 초기화
	front = rear = NULL;
	items = 0;
}

template <typename T>
Queue<T>::~Queue()
{
	// temp Node 포인터를 만들어서
	Node* temp;
	// 전체 노드의 포인터를 다 지워서 front가 null이 될 때까지 진행
	while (front != NULL)
	{
		// temp에 front 주소 대입
		temp = front;
		// front 위치를 다음 단계로 이동
		front = front->next;
		// 이전에 저장된 front 주소를 지워버림.
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
	// queue가 가득 차있으면
	if (isFull())
		return false;
	// 1. 임시 노드 생성
	// 2. 임시 노드 item에 추가할 item 추가
	// 3. 임시 노드 next에 NULL 추가, 왜냐하면 꼬리 끝에 추가되기 때문에
	// 4. 항목이 늘어났기 때문에 itmes 증가시켜주기
	// 5. front가 NULL 이면 최전방에 배치
	// 6. 그게 아니라면 rear의 next 즉, 최후방에 배치
	// 7. 마지막으로 rear은 최후방 노드기 때문에 add를 받음.
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
	// front가 null이면 false
	if (front == NULL)
		return false;
	// 1. 먼저 out할 item 참조에 front->item 값을 대입한다.
	// 2. 큐의 항목을 하나 빼준다.
	// 3. 그리고 임시 노드를 생성해서 front를 대입한다.
	// 4. 그리고 이제 front는 없어지고 front->next가 front가 되어야 하기 때문에 front에 대입해준다.
	// 5. 그리고 temp에 저장해두었던 front 주소를 삭제한다.
	// 6. 마지막으로 items의 값이 0이 되었다면 rear 또한 없어야 마땅하기 때문에 NULL로 만들어준다.
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
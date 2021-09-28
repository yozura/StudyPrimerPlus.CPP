#include <cstdlib>
#include "queue0.h"

Queue::Queue(int qs)
	: qsize(qs), front(NULL), rear(NULL), items(0)
{
}

Queue::~Queue()
{
	Node* temp;
	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

bool Queue::enqueue(const Item& item)
{
	// 1. 큐가 꽉 차있으면 이대로 종료
	if (isfull())
		return false;
	// 2. 새로운 노드 포인터를 생성한다.
	Node* add = new Node;
	// 3. 새로운 노드 포인터에 매개변수로 받은 item을 node.item에 삽입하고
	add->item = item;
	// 4. 새로운 노드 포인터의 next 멤버 변수에는 NULL 값을 삽입한다.
	// 왜냐면 새로운 노드가 추가되는 경우에는 가장 끝에 위치할 것이니까, 자기 스스로가 REAR
	add->next = NULL;
	// 5. 현재 존재하는 큐의 숫자를 추가한다.
	items++;
	// 6. front가 NULL, 즉 비어있는 상태라면 머리 부분에 새 노드 포인터를 넣는다.
	// 6-1. 만일 NULL이 아니라면 새 노드 포인터를 rear이 가르키는 next에 삽입한다.
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	// 7. rear 에 add를 삽입한 뒤 종료.
	rear = add;
	return true;
}

bool Queue::dequeue(Item& item)
{
	// 1. 큐가 비어있으면 이대로 종료.
	if (front == NULL)
		return false;
	// 2. 참조 매개변수에 front가 가리키는 item을 대입한다. 
	item = front->item;
	items--;
	// 3. 새 노드 포인터를 front로 초기화한다.
	Node* temp = front;
	// 4. front 는 front의 next를 가리키도록 변경.
	front = front->next;
	// 5. 새 노드 포인터를 제거한다 이 때, 저장해두었던 이전 front 주소를 함께 파괴한다.
	delete temp;
	// 6. 이후 큐가 비었는지 다시 확인하고 만약 비어있다면 rear에는 NULL을 삽입한다.
	if (items == 0)
		rear = NULL;
	return true;
}

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}

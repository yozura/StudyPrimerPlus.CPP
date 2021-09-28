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
	// 1. ť�� �� �������� �̴�� ����
	if (isfull())
		return false;
	// 2. ���ο� ��� �����͸� �����Ѵ�.
	Node* add = new Node;
	// 3. ���ο� ��� �����Ϳ� �Ű������� ���� item�� node.item�� �����ϰ�
	add->item = item;
	// 4. ���ο� ��� �������� next ��� �������� NULL ���� �����Ѵ�.
	// �ֳĸ� ���ο� ��尡 �߰��Ǵ� ��쿡�� ���� ���� ��ġ�� ���̴ϱ�, �ڱ� �����ΰ� REAR
	add->next = NULL;
	// 5. ���� �����ϴ� ť�� ���ڸ� �߰��Ѵ�.
	items++;
	// 6. front�� NULL, �� ����ִ� ���¶�� �Ӹ� �κп� �� ��� �����͸� �ִ´�.
	// 6-1. ���� NULL�� �ƴ϶�� �� ��� �����͸� rear�� ����Ű�� next�� �����Ѵ�.
	if (front == NULL)
		front = add;
	else
		rear->next = add;
	// 7. rear �� add�� ������ �� ����.
	rear = add;
	return true;
}

bool Queue::dequeue(Item& item)
{
	// 1. ť�� ��������� �̴�� ����.
	if (front == NULL)
		return false;
	// 2. ���� �Ű������� front�� ����Ű�� item�� �����Ѵ�. 
	item = front->item;
	items--;
	// 3. �� ��� �����͸� front�� �ʱ�ȭ�Ѵ�.
	Node* temp = front;
	// 4. front �� front�� next�� ����Ű���� ����.
	front = front->next;
	// 5. �� ��� �����͸� �����Ѵ� �� ��, �����صξ��� ���� front �ּҸ� �Բ� �ı��Ѵ�.
	delete temp;
	// 6. ���� ť�� ������� �ٽ� Ȯ���ϰ� ���� ����ִٸ� rear���� NULL�� �����Ѵ�.
	if (items == 0)
		rear = NULL;
	return true;
}

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}

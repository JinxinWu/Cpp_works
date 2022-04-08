/*9.设计一个用链表保存整型元素的链队列类，要求实现的队列类具有与 STL 整型队列类同样
的功能，可以替换本章第2.1 节样例 Ex2.1里的整型队列类。注意人队列和出队列的运算效率。*/
#include <iostream>
using namespace std;

class CQueue
{
public:
	CQueue();
	~CQueue();
	void push(int x);
	bool empty() const;
	int front() const;
	void pop();
private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* m_sp;
};

CQueue::CQueue()//带头结点的链表
{
	m_sp = new Node;
	m_sp->next = nullptr;
}
CQueue::~CQueue()
{
	while (m_sp != nullptr)
	{
		Node* p = nullptr;
		m_sp = m_sp->next;
		delete p;
	}
}
void CQueue::push(int x)//向前插入数据
{
	Node* p = new Node;
	p->data = x;
	Node* q = m_sp;
	while (q->next != nullptr)
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
}
bool CQueue::empty() const
{
	return (m_sp->next == nullptr);
}
int CQueue::front() const
{
	return m_sp->next->data;
}
void CQueue::pop()
{
	Node* p = m_sp;
	m_sp = p->next;
	delete p;
}

int main()
{
	CQueue C1, C2;
	int v, x;

	cout << "输入若干对整数v、x,1<=v<=2,将元素x存入第v个队列" << endl;

	while (cin >> v >> x)
	{
		if (v == 1)
			C1.push(x);
		else
			C2.push(x);
	}

	cout << "队列1中的元素：";
	while (!C1.empty())
	{
		x = C1.front();
		cout << x << " ";
		C1.pop();
	}
	cout << endl;

	cout << "队列2中的元素：";
	while (!C2.empty())
	{
		x = C2.front();
		cout << x << " ";
		C2.pop();
	}
	cout << endl;
}

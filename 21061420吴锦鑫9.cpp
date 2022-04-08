/*9.���һ��������������Ԫ�ص��������࣬Ҫ��ʵ�ֵĶ���������� STL ���Ͷ�����ͬ��
�Ĺ��ܣ������滻���µ�2.1 ������ Ex2.1������Ͷ����ࡣע���˶��кͳ����е�����Ч�ʡ�*/
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

CQueue::CQueue()//��ͷ��������
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
void CQueue::push(int x)//��ǰ��������
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

	cout << "�������ɶ�����v��x,1<=v<=2,��Ԫ��x�����v������" << endl;

	while (cin >> v >> x)
	{
		if (v == 1)
			C1.push(x);
		else
			C2.push(x);
	}

	cout << "����1�е�Ԫ�أ�";
	while (!C1.empty())
	{
		x = C1.front();
		cout << x << " ";
		C1.pop();
	}
	cout << endl;

	cout << "����2�е�Ԫ�أ�";
	while (!C2.empty())
	{
		x = C2.front();
		cout << x << " ";
		C2.pop();
	}
	cout << endl;
}
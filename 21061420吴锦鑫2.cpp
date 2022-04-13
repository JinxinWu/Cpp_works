/*2. ��Ƶ������ʾ������ջ�࣬Ҫ��ջ������� STL stack ���ƵĽӿں͹��ܣ�����
�п������졢���Ƹ�ֵ���ƶ����졢�ƶ���ֵ���ܡ���д���Գ��򣬲�������Ƶ�������ջ��*/
#include <iostream>
using namespace std;

class CStack
{
public:
	CStack();//���캯��
	~CStack();//��������

	//�������캯��
	CStack(const CStack& rhs);
	// �ƶ����캯��
	CStack(CStack&& rhs) noexcept;
	//���Ƹ�ֵ
	CStack& operator= (const CStack& rhs);
	//�ƶ���ֵ
	CStack& operator=(CStack&& rhs) noexcept;
	//��ʾ����
	void Display();

	void push(int x);//��ջ
	bool empty() const;//�п�
	int top() const;//�ǿ�ȡջ��
	void pop();//�ǿճ�ջ
	void head();//����ͷ�ڵ�Ϊ��
private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* m_phead;//����ͷ�ڵ�
};

CStack::CStack() :m_phead(nullptr) {}
CStack::~CStack()
{
	while (m_phead != nullptr)
	{
		Node* p = m_phead;
		m_phead = m_phead->next;
		delete p;
	}
}

//�������캯��
CStack::CStack(const CStack& rhs)
{
	//����ͷ�ڵ�
	m_phead = new Node;
	Node* last = m_phead;//���ڵ�

	Node* p = rhs.m_phead->next;//�����޸�rhs.m_pHead����������ʱ������
	while (p)
	{
		Node* q = new Node;//����һ�ڵ�
		q->data = p->data;//����Ԫ��
		//�������
		last->next = q;
		last = q;
		// ����һ�ڵ�
		p = p->next;
	}
	last->next = NULL;
}
//�ƶ����캯��
CStack::CStack(CStack&& rhs) noexcept
{
	//�ƶ�ͷ�ڵ�
	m_phead = rhs.m_phead;
	rhs.m_phead = NULL;
}
//���Ƹ�ֵ
CStack& CStack::operator=(const CStack& rhs)
{
	CStack tmp(rhs);

	Node* t = m_phead;
	m_phead = tmp.m_phead;
	tmp.m_phead = t;
	return *this;
}
//�ƶ���ֵ
CStack& CStack:: operator = (CStack&& rhs) noexcept
{
	Node* p = this->m_phead;
	this->m_phead = rhs.m_phead;
	rhs.m_phead = p;

	return *this;
}
//��ʾ����
void CStack::Display()
{
	Node* p = m_phead->next;//��ʱ�ڵ�
	cout << "{";//��ʽ�淶
	while (p)
	{
		cout << p->data;
		p = p->next;
		if (p) cout << ",";
	}
	cout << "}" << endl;//��ʽ�淶
}

void CStack::push(int x)//�Ӻ���ǰ��������
{
	Node* p = new Node;
	p->data = x;
	p->next = m_phead;
	m_phead = p;
}
bool CStack::empty() const
{
	return (m_phead->next == nullptr);
}
int CStack::top() const
{
	return m_phead->next->data;
}
void CStack::pop()
{
	Node* p = m_phead->next;
	m_phead->next = p->next;
	delete p;
}
void CStack::head()
{
	Node* p = new Node;
	p->next = m_phead;
	m_phead = p;
}

int main()
{
	CStack S1, S2;
	int v, x;

	while (cin >> v >> x)
	{
		if (v == 1)
			S1.push(x);
		else
			S2.push(x);
	}
	S1.head();
	S2.head();

	while (!S1.empty())
	{
		x = S1.top();
		cout << x << " ";
		S1.pop();
	}
	cout << endl;

	while (!S2.empty())
	{
		x = S2.top();
		cout << x << " ";
		S2.pop();
	}
	cout << endl;

	CStack C1=S1, C2=S2;
	C1.Display();
	C2.Display();

	return 0;
}

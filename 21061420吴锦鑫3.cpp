/*3��ģ��Stack�����ʵ��CStackջ�� 
ģ��STL stack�����ʵ��CStack�࣬������Ҫ����ջ����ջ���ж�ջ�ա�ȡջ��Ԫ�صȹ��ܡ�
�����ʽ:
�ֱ���������ջ���ٶ������ɶ�����v,x��1<=v<=2����Ԫ��x���v��ջ��
�����ʽ:
�������ջ��Ԫ�س�ջ���������ÿ��ջ���ռһ�У�Ԫ�ؼ��ÿո�ֿ���
���磺����
1 100
2 200
1 300
2 400
1 50
1 60
2 80
�����
60 50 300 100 
80 400 200
*/
#include <iostream>
using namespace std;

class CStack
{
public:
	CStack();//���캯��
	~CStack();//��������
	void push(int x);//��ջ
	bool empty() const;//�п�
	int top() const;//�ǿ�ȡջ��
	void pop();//�ǿճ�ջ
private:
	struct Node
	{
		Node() :next(nullptr);//�ڵ㽨����Node->next��ʼ��Ϊnullptr
		int data;
		Node* next;
	};
	Node* m_phead;//����ͷ�ڵ�
};

CStack::CStack() :m_phead(nullptr) {}
CStack::~CStack()
{
	while (m_phead!=nullptr)
	{
		Node* p = m_phead;
		m_phead = m_phead->next;
		delete p;
	}
}
void CStack::push(int x)
{
	Node* p = new Node;
	p->data = x;
	p->next = m_phead;
	m_phead = p;
}
bool CStack::empty() const
{
	return (m_phead == nullptr);
}
int CStack::top() const
{
	return m_phead->data;
}
void CStack::pop()
{
	Node* p = m_phead;
	m_phead = p->next;
	delete p;
}

int main()
{
	CStack S1, S2;
	int v, x;

	while (cin>>v>>x)
	{
		if (v == 1)
			S1.push(x);
		else
			S2.push(x);
	}

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

	return 0;
}
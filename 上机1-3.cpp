/*3、模拟Stack类设计实现CStack栈类 
模拟STL stack类设计实现CStack类，该类需要有入栈、出栈、判断栈空、取栈顶元素等功能。
输入格式:
分别构造两个空栈，再读入若干对整数v,x，1<=v<=2；将元素x入第v个栈。
输出格式:
最后将两个栈中元素出栈，并输出；每个栈输出占一行，元素间用空格分开。
例如：输入
1 100
2 200
1 300
2 400
1 50
1 60
2 80
输出：
60 50 300 100 
80 400 200
*/
#include <iostream>
using namespace std;

class CStack
{
public:
	CStack();//构造函数
	~CStack();//析构函数
	void push(int x);//入栈
	bool empty() const;//判空
	int top() const;//非空取栈顶
	void pop();//非空出栈
private:
	struct Node
	{
		Node() :next(nullptr);//节点建立后Node->next初始化为nullptr
		int data;
		Node* next;
	};
	Node* m_phead;//建立头节点
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

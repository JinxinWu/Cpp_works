/*2. 设计单链表表示的整型栈类，要求栈类具有与 STL stack 类似的接口和功能，并具
有拷贝构造、复制赋值、移动构造、移动赋值功能。编写测试程序，测试你设计的整型链栈类*/
#include <iostream>
using namespace std;

class CStack
{
public:
	CStack();//构造函数
	~CStack();//析构函数

	//拷贝构造函数
	CStack(const CStack& rhs);
	// 移动构造函数
	CStack(CStack&& rhs) noexcept;
	//复制赋值
	CStack& operator= (const CStack& rhs);
	//移动赋值
	CStack& operator=(CStack&& rhs) noexcept;
	//显示集合
	void Display();

	void push(int x);//入栈
	bool empty() const;//判空
	int top() const;//非空取栈顶
	void pop();//非空出栈
	void head();//建立头节点为空
private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* m_phead;//建立头节点
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

//拷贝构造函数
CStack::CStack(const CStack& rhs)
{
	//复制头节点
	m_phead = new Node;
	Node* last = m_phead;//最后节点

	Node* p = rhs.m_phead->next;//不可修改rhs.m_pHead，故引入临时变量。
	while (p)
	{
		Node* q = new Node;//申请一节点
		q->data = p->data;//复制元素
		//挂在最后
		last->next = q;
		last = q;
		// 后移一节点
		p = p->next;
	}
	last->next = NULL;
}
//移动构造函数
CStack::CStack(CStack&& rhs) noexcept
{
	//移动头节点
	m_phead = rhs.m_phead;
	rhs.m_phead = NULL;
}
//复制赋值
CStack& CStack::operator=(const CStack& rhs)
{
	CStack tmp(rhs);

	Node* t = m_phead;
	m_phead = tmp.m_phead;
	tmp.m_phead = t;
	return *this;
}
//移动赋值
CStack& CStack:: operator = (CStack&& rhs) noexcept
{
	Node* p = this->m_phead;
	this->m_phead = rhs.m_phead;
	rhs.m_phead = p;

	return *this;
}
//显示集合
void CStack::Display()
{
	Node* p = m_phead->next;//临时节点
	cout << "{";//格式规范
	while (p)
	{
		cout << p->data;
		p = p->next;
		if (p) cout << ",";
	}
	cout << "}" << endl;//格式规范
}

void CStack::push(int x)//从后往前插入数据
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

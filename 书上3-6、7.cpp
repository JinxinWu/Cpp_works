/*6.设计一个具有拷贝构造、复制赋值、移动构造和移动赋值功能的 CSamplePart 类，再设计一个含类型为 CSamplePart 
的数据成员的类，让编译器为你合成拷贝构造、移动构造、复制赋值和移动赋值。编写测试程序，测试合成的拷贝控制函数的效果。

7.设计一个具有拷贝构造、复制赋值、移动构造和移动赋值功能的CSamplePart 类，再设计一个含类型为 CSamplePart 的数据成员
的类，重载该类的拷贝构造、移动构造、复制赋值和移动赋值中的部分函数。编写测试程序，测试编译器是否合成其余函数。*/
#include <iostream>
using namespace std;

class CSamplePart
{
public:
	CSamplePart() {
		m_pHead = new Node;//动态分配
		m_pHead->next = NULL;
	}
	//拷贝构造函数
	CSamplePart(const CSamplePart& rhs);
	//移动构造函数
	CSamplePart(CSamplePart&& rhs) noexcept;
	//复制赋值
	CSamplePart& operator= (const CSamplePart& rhs);
	//移动赋值
	CSamplePart& operator=(CSamplePart&& rhs) noexcept;

	void Input(int x);
	void Show();
private:
	struct Node
	{
		int data;
		Node* next;
	}*m_pHead;//集合采用递增排序单链表表示
};

//拷贝构造函数
CSamplePart::CSamplePart(const CSamplePart& rhs)
{
	//复制头节点
	m_pHead = new Node;
	Node* last = m_pHead;//最后节点

	Node* p = rhs.m_pHead->next;//不可修改rhs.m_pHead，故引入临时变量。
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
	cout << "完成CSamplePart的拷贝构造函数" << endl;
}

//移动构造函数
CSamplePart::CSamplePart(CSamplePart&& rhs) noexcept
{
	//移动头节点
	m_pHead = rhs.m_pHead;
	rhs.m_pHead = NULL;
	cout << "完成CSamplePart的移动构造函数" << endl;
}

//复制赋值
CSamplePart& CSamplePart::operator=(const CSamplePart& rhs)
{
	CSamplePart tmp(rhs);

	Node* t = m_pHead;
	m_pHead = tmp.m_pHead;
	tmp.m_pHead = t;
	return *this;
	cout << "完成CSamplePart的复制赋值" << endl;
}

//移动赋值
CSamplePart& CSamplePart:: operator = (CSamplePart&& rhs) noexcept
{
	Node* p = this->m_pHead;
	this->m_pHead = rhs.m_pHead;
	rhs.m_pHead = p;

	return *this;
	cout << "完成CSamplePart的移动赋值" << endl;
}

void CSamplePart::Input(int x)
{
	Node* p = m_pHead;
	while (p->next)
	{
		p = p->next;
	}
	Node* q = new Node;
	q->data = x;
	q->next = nullptr;
	p->next = q;
}

void CSamplePart::Show()
{
	Node* p = m_pHead->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

class CSet
{
public:
	CSet() {}

	void Input(int x)
	{
		S.Input(x);
	}
	void Show();

	//拷贝构造函数
	CSet(const CSet& rhs);
	//移动构造函数
	CSet(CSet&& rhs) noexcept;
	//复制赋值
	CSet& operator= (const CSet& rhs);
	//移动赋值
	CSet& operator=(CSet&& rhs) noexcept;
private:
	CSamplePart S;
};

//拷贝构造函数
CSet::CSet(const CSet& rhs)
{
	S = rhs.S;
	cout << "完成CSet的拷贝构造函数" << endl;
}

//移动构造函数
CSet::CSet(CSet&& rhs) noexcept
{
	S = rhs.S;
	cout << "完成CSet的移动构造函数" << endl;
}

//复制赋值
CSet& CSet::operator= (const CSet& rhs)
{
	S = rhs.S;
	cout << "完成CSet的移动构造函数" << endl;
	return *this;
}
//移动赋值
CSet& CSet::operator=(CSet&& rhs) noexcept
{
	S = rhs.S;
	cout << "完成CSet的移动构造函数" << endl;
	return *this;
}

void CSet::Show()
{
	CSamplePart S1(S), S2 = S1;
	S.Show();
	S1.Show();
	S2.Show();
}

int main()
{
	CSet C1;
	int x;
	while (cin >> x)
	{
		C1.Input(x);
	}
	C1.Show();

	CSet C2(C1), C3 = C1;
	C2.Show();
	C3.Show();

	return 0;
}

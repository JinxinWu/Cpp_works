/*1.编写程序，进一步完善 Ex3.1 中链表表示的集合类，添加集合并、差、删除元素等
成员函数功能，并编写测试程序。*/
#include <iostream>
using namespace std;

class CSet
{
public:
	//构造函数
	CSet();
	//析构函数，释放链表
	~CSet();

	//拷贝构造函数
	CSet(const CSet& rhs);
	// 移动构造函数
	CSet(CSet&& rhs) noexcept;
	//删除元素x
	bool Remove(int x);
	//是否包含元素 x
	bool In(int x);
	//复制赋值
	CSet& operator= (const CSet& rhs);
	//移动赋值
	CSet& operator=(CSet&& rhs) noexcept;

	//增加元素
	bool Add(int x);
	//显示集合
	void Display();
	//结果为A、B交集
	CSet Join(const CSet& rhs) const;
	//结果为A、B并集
	CSet Merge(const CSet& rhs) const;
	//结果为A、B差集
	CSet Differ(const CSet& rhs) const;
private:
	struct Node
	{
		int data;
		Node* next;
	}*m_pHead;//集合采用递增排序单链表表示
};

//构造函数
CSet::CSet()//初始化类的对象
{
	m_pHead = new Node;//动态分配
	m_pHead->next = NULL;
}
//析构函数，释放链表
CSet::~CSet()
{
	while (m_pHead)
	{
		Node* p = m_pHead;
		m_pHead = p->next;
		delete p;
	}
}

//增加元素
bool CSet::Add(int x)
{
	Node* p = m_pHead;//临时节点
	while (p->next && (p->next->data < x))
	{
		p = p->next;
	}
	if (p->next && p->next->data == x)//满足集合互异性
		return false;//元素己在集合中
	Node* q = new Node;//临时节点
	q->data = x;
	q->next = p->next;
	p->next = q;
	return true;
}

//删除元素x(new)
bool CSet::Remove(int x)
{
	Node* p = m_pHead;
	while (p->next && (p->next->data < x))
	{
		p = p->next;
	}
	if (p->next && p->next->data == x)
	{
		Node* q = p->next->next;
		delete p->next;
		p->next = q;
		return true;
	}
	return false;
}

//显示集合
void CSet::Display()
{
	Node* p = m_pHead->next;//临时节点
	cout << "{";//格式规范
	while (p)
	{
		cout << p->data;
		p = p->next;
		if (p) cout << ",";
	}
	cout << "}" << endl;//格式规范
}

//结果为 A、B交集
CSet CSet::Join(const CSet& rhs) const
{
	CSet result;

	Node* last = result.m_pHead;

	Node* p = m_pHead->next;//临时节点
	Node* q = rhs.m_pHead->next;//临时节点
	while (p && q)
	{
		if (p->data == q->data)
		{
			Node* s = new Node;
			s->data = p->data;
			last->next = s;
			last = s;

			p = p->next;
			q = q->next;
		}
		else if (p->data < q->data)
			p = p->next;
		else
			q = q->next;
	}
	last->next = NULL;
	return result;
}

//结果为A、B并集(new)
CSet CSet::Merge(const CSet& rhs) const
{
	CSet result;

	Node* last = result.m_pHead;

	Node* p = m_pHead->next;//临时节点
	Node* q = rhs.m_pHead->next;//临时节点
	while (p && q)
	{
		if (p->data == q->data)
		{
			Node* s = new Node;
			s->data = p->data;
			last->next = s;
			last = s;

			p = p->next;
			q = q->next;
		}
		else if (p->data < q->data)
		{
			Node* s = new Node;
			s->data = p->data;
			last->next = s;
			last = s;

			p = p->next;
		}
		else
		{
			Node* s = new Node;
			s->data = q->data;
			last->next = s;
			last = s;

			q = q->next;
		}
	}
	while (p)
	{
		Node* s = new Node;
		s->data = p->data;
		last->next = s;
		last = s;

		p = p->next;
	}
	while (q)
	{
		Node* s = new Node;
		s->data = q->data;
		last->next = s;
		last = s;

		q = q->next;
	}
	last->next = NULL;
	return result;
}

//结果为A、B差集(new)
CSet CSet::Differ(const CSet& rhs) const
{
	CSet result;

	Node* last = result.m_pHead;

	Node* p = m_pHead->next;//临时节点
	Node* q = rhs.m_pHead->next;//临时节点
	while (p && q)
	{
		if (p->data == q->data)
		{
			p = p->next;
			q = q->next;
		}
		else if (p->data < q->data)
		{
			Node* s = new Node;
			s->data = p->data;
			last->next = s;
			last = s;

			p = p->next;
		}
		else
			q = q->next;
	}
	last->next = NULL;
	return result;
}

//是否包含元素x
bool CSet::In(int x)
{
	Node* p = m_pHead;
	while (p->next && (p->next->data < x))
	{
		p = p->next;
	}
	if (p->next && p->next->data == x)
		return true;
	return false;
}

//拷贝构造函数
CSet::CSet(const CSet& rhs)
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
}

//移动构造函数
CSet::CSet(CSet&& rhs) noexcept
{
	//移动头节点
	m_pHead = rhs.m_pHead;
	rhs.m_pHead = NULL;
}

//复制赋值
CSet& CSet::operator=(const CSet& rhs)
{
	CSet tmp(rhs);

	Node* t = m_pHead;
	m_pHead = tmp.m_pHead;
	tmp.m_pHead = t;
	return *this;
}

//移动赋值
CSet& CSet:: operator = (CSet&& rhs) noexcept
{
	Node* p = this->m_pHead;
	this->m_pHead = rhs.m_pHead;
	rhs.m_pHead = p;

	return *this;
}

int main()
{
	CSet A, B, S, S2, S3;
	int i, m, n, x;
	cin >> m >> n;

	for (i = 0; i < m; i++)
	{
		cin >> x;
		A.Add(x);
	}
	for (i = 0; i < n; i++)
	{
		cin >> x;
		B.Add(x);
	}
	A.Display();
	B.Display();

	S = A.Join(B);
	S.Display();

	S2 = A.Merge(B);
	S2.Display();

	S3 = A.Differ(B);
	S3.Display();
}

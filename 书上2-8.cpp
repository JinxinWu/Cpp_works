/*8.设计一个用数组保存整型元素的整型元素队列类，要求实现的队列类具有与 STL整型队列
类同样的功能，可以替换本章第2.1节样例 Ex2.1 里的整型队列类。注意区分队空和队满状态，
注意入队列和出队列的运算效率。*/
#include<iostream>
using namespace std;
#define N 1000

class CQueue
{
public:
	CQueue();//构造函数，初始化元素个数
	~CQueue();//析构函数，将数组元素清空
	void push(int x);//入队列
	int front();//取队首元素
	bool empty() const;//判断队列非空
	void pop();//出队列
//private:
	int m_num[N];
	int m_count;//记录数组元素个数
};

CQueue::CQueue() :m_count(0)
{
	for (int i = 0; i < N; ++i)
		m_num[i] = 0;
}
CQueue::~CQueue()
{
	for (int i = 0; i < m_count; ++i)
	{
		m_num[i] = 0;
	}
}
void CQueue::push(int x)
{
	m_num[m_count++] = x;
}
bool CQueue::empty() const
{
	return m_count;
}
int CQueue::front()
{
	return m_num[0];
}
void CQueue::pop()
{
	for (int i = 1; i < m_count; ++i)
	{
		m_num[i - 1] = m_num[i];
	}
    --m_count;
}

int main()
{
	CQueue Q1, Q2;
	int v, x;

	cout << "输入若干对整数v、x,1<=v<=2,将元素x存入第v个队列" << endl;

	while (cin >> v >> x)
	{
		if (v == 1)
			Q1.push(x);
		else
            Q2.push(x);
	}

	cout << "队列1中的元素：";
	while (Q1.empty())
	{
		x = Q1.front();
		cout << x << " ";
		Q1.pop();
	}
	cout << endl;

	cout << "队列2中的元素：";
	while (Q2.empty())
	{
		x = Q2.front();
		cout << x << " ";
		Q2.pop();
	}
	cout << endl;

	return 0;
}

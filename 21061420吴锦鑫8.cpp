/*8.���һ�������鱣������Ԫ�ص�����Ԫ�ض����࣬Ҫ��ʵ�ֵĶ���������� STL���Ͷ���
��ͬ���Ĺ��ܣ������滻���µ�2.1������ Ex2.1 ������Ͷ����ࡣע�����ֶӿպͶ���״̬��
ע������кͳ����е�����Ч�ʡ�*/
#include<iostream>
using namespace std;
#define N 1000

class CQueue
{
public:
	CQueue();//���캯������ʼ��Ԫ�ظ���
	~CQueue();//����������������Ԫ�����
	void push(int x);//�����
	int front();//ȡ����Ԫ��
	bool empty() const;//�ж϶��зǿ�
	void pop();//������
//private:
	int m_num[N];
	int m_count;//��¼����Ԫ�ظ���
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

	cout << "�������ɶ�����v��x,1<=v<=2,��Ԫ��x�����v������" << endl;

	while (cin >> v >> x)
	{
		if (v == 1)
			Q1.push(x);
		else
            Q2.push(x);
	}

	cout << "����1�е�Ԫ�أ�";
	while (Q1.empty())
	{
		x = Q1.front();
		cout << x << " ";
		Q1.pop();
	}
	cout << endl;

	cout << "����2�е�Ԫ�أ�";
	while (Q2.empty())
	{
		x = Q2.front();
		cout << x << " ";
		Q2.pop();
	}
	cout << endl;

	return 0;
}

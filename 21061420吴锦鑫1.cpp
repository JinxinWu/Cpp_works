/*1.��д���򣬽�һ������ Ex3.1 �������ʾ�ļ����࣬��Ӽ��ϲ����ɾ��Ԫ�ص�
��Ա�������ܣ�����д���Գ���*/
#include <iostream>
using namespace std;

class CSet
{
public:
	//���캯��
	CSet();
	//�����������ͷ�����
	~CSet();

	//�������캯��
	CSet(const CSet&);
	// �ƶ����캯��
	CSet(CSet&&) noexcept;
	//ɾ��Ԫ��x
	bool Remove(int x);
	//�Ƿ����Ԫ�� x
	bool In(int x);
	//���Ƹ�ֵ
	CSet& operator= (const CSet& rh);
	//�ƶ���ֵ
	CSet& operator=(CSet&& rhs) noexcept;

	//����Ԫ��
	bool Add(int x);
	//��ʾ����
	void Display();
	//���ΪA��B����
	CSet Join(const CSet& rhs) const;
	//���ΪA��B����
	CSet Merge(const CSet& rhs) const;
	//���ΪA��B�
	CSet Differ(const CSet& rhs) const;
private:
	struct Node
	{
		int data;
		Node* next;
	}*m_pHead;//���ϲ��õ������������ʾ
};

//���캯��
CSet::CSet()//��ʼ����Ķ���
{
	m_pHead = new Node;//��̬����
	m_pHead->next = NULL;
}
//�����������ͷ�����
CSet::~CSet()
{
	while (m_pHead)
	{
		Node* p = m_pHead;
		m_pHead = p->next;
		delete p;
	}
}

//����Ԫ��
bool CSet::Add(int x)
{
	Node* p = m_pHead;//��ʱ�ڵ�
	while (p->next && (p->next->data < x))
	{
		p = p->next;
	}
	if (p->next && p->next->data == x)//���㼯�ϻ�����
		return false;//Ԫ�ؼ��ڼ�����
	Node* q = new Node;//��ʱ�ڵ�
	q->data = x;
	q->next = p->next;
	p->next = q;
	return true;
}

//ɾ��Ԫ��x(new)
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

//��ʾ����
void CSet::Display()
{
	Node* p = m_pHead->next;//��ʱ�ڵ�
	cout << "{";//��ʽ�淶
	while (p)
	{
		cout << p->data;
		p = p->next;
		if (p) cout << ",";
	}
	cout << "}" << endl;//��ʽ�淶
}

//���Ϊ A��B����
CSet CSet::Join(const CSet& rhs) const
{
	CSet result;

	Node* last = result.m_pHead;

	Node* p = m_pHead->next;//��ʱ�ڵ�
	Node* q = rhs.m_pHead->next;//��ʱ�ڵ�
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

//���ΪA��B����(new)
CSet CSet::Merge(const CSet& rhs) const
{
	CSet result;

	Node* last = result.m_pHead;

	Node* p = m_pHead->next;//��ʱ�ڵ�
	Node* q = rhs.m_pHead->next;//��ʱ�ڵ�
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

//���ΪA��B�(new)
CSet CSet::Differ(const CSet& rhs) const
{
	CSet result;

	Node* last = result.m_pHead;

	Node* p = m_pHead->next;//��ʱ�ڵ�
	Node* q = rhs.m_pHead->next;//��ʱ�ڵ�
	while (p && q)
	{
		if (p->data == q->data)
		{
			p = p->next;
			q = q->next;
		}
		else if(p->data < q->data)
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

//�Ƿ����Ԫ��x
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

//�������캯��
CSet::CSet(const CSet& rhs)
{
	//����ͷ�ڵ�
	m_pHead = new Node;
	Node* last = m_pHead;//���ڵ�

	Node* p = rhs.m_pHead->next;//�����޸�rhs.m_pHead����������ʱ������
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
CSet::CSet(CSet&& rhs) noexcept
{
	//�ƶ�ͷ�ڵ�
	m_pHead = rhs.m_pHead;
	rhs.m_pHead = NULL;
}

//���Ƹ�ֵ
CSet& CSet::operator=(const CSet& rhs)
{
	CSet tmp(rhs);

	Node* t = m_pHead;
	m_pHead = tmp.m_pHead;
	tmp.m_pHead = t;
	return *this;
}

//�ƶ���ֵ
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
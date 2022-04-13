/*6.���һ�����п������졢���Ƹ�ֵ���ƶ�������ƶ���ֵ���ܵ� CSamplePart �࣬�����һ��������Ϊ CSamplePart 
�����ݳ�Ա���࣬�ñ�����Ϊ��ϳɿ������졢�ƶ����졢���Ƹ�ֵ���ƶ���ֵ����д���Գ��򣬲��ԺϳɵĿ������ƺ�����Ч����

7.���һ�����п������졢���Ƹ�ֵ���ƶ�������ƶ���ֵ���ܵ�CSamplePart �࣬�����һ��������Ϊ CSamplePart �����ݳ�Ա
���࣬���ظ���Ŀ������졢�ƶ����졢���Ƹ�ֵ���ƶ���ֵ�еĲ��ֺ�������д���Գ��򣬲��Ա������Ƿ�ϳ����ຯ����*/
#include <iostream>
using namespace std;

class CSamplePart
{
public:
	CSamplePart() {
		m_pHead = new Node;//��̬����
		m_pHead->next = NULL;
	}
	//�������캯��
	CSamplePart(const CSamplePart& rhs);
	//�ƶ����캯��
	CSamplePart(CSamplePart&& rhs) noexcept;
	//���Ƹ�ֵ
	CSamplePart& operator= (const CSamplePart& rhs);
	//�ƶ���ֵ
	CSamplePart& operator=(CSamplePart&& rhs) noexcept;

	void Input(int x);
	void Show();
private:
	struct Node
	{
		int data;
		Node* next;
	}*m_pHead;//���ϲ��õ������������ʾ
};

//�������캯��
CSamplePart::CSamplePart(const CSamplePart& rhs)
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
	cout << "���CSamplePart�Ŀ������캯��" << endl;
}

//�ƶ����캯��
CSamplePart::CSamplePart(CSamplePart&& rhs) noexcept
{
	//�ƶ�ͷ�ڵ�
	m_pHead = rhs.m_pHead;
	rhs.m_pHead = NULL;
	cout << "���CSamplePart���ƶ����캯��" << endl;
}

//���Ƹ�ֵ
CSamplePart& CSamplePart::operator=(const CSamplePart& rhs)
{
	CSamplePart tmp(rhs);

	Node* t = m_pHead;
	m_pHead = tmp.m_pHead;
	tmp.m_pHead = t;
	return *this;
	cout << "���CSamplePart�ĸ��Ƹ�ֵ" << endl;
}

//�ƶ���ֵ
CSamplePart& CSamplePart:: operator = (CSamplePart&& rhs) noexcept
{
	Node* p = this->m_pHead;
	this->m_pHead = rhs.m_pHead;
	rhs.m_pHead = p;

	return *this;
	cout << "���CSamplePart���ƶ���ֵ" << endl;
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

	//�������캯��
	CSet(const CSet& rhs);
	//�ƶ����캯��
	CSet(CSet&& rhs) noexcept;
	//���Ƹ�ֵ
	CSet& operator= (const CSet& rhs);
	//�ƶ���ֵ
	CSet& operator=(CSet&& rhs) noexcept;
private:
	CSamplePart S;
};

//�������캯��
CSet::CSet(const CSet& rhs)
{
	S = rhs.S;
	cout << "���CSet�Ŀ������캯��" << endl;
}

//�ƶ����캯��
CSet::CSet(CSet&& rhs) noexcept
{
	S = rhs.S;
	cout << "���CSet���ƶ����캯��" << endl;
}

//���Ƹ�ֵ
CSet& CSet::operator= (const CSet& rhs)
{
	S = rhs.S;
	cout << "���CSet���ƶ����캯��" << endl;
	return *this;
}
//�ƶ���ֵ
CSet& CSet::operator=(CSet&& rhs) noexcept
{
	S = rhs.S;
	cout << "���CSet���ƶ����캯��" << endl;
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
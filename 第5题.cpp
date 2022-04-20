/*5.��Ʋ�ʵ��һ�����й��졢����*��/��%��>��<��>=����=��!=�������ȹ��ܵ��޷��Ŵ����ࡣ
��ʾ��Ϊ�������㣬�޷��Ŵ����ڲ��������ʮ����λʱ���õ�λ��ǰ����λ�ں�ķ�ʽ��
ȥ����λ�����0���޷��Ŵ�����Ӧ֧�ָ��ƺ͸�ֵ��*/
#include <iostream>

using namespace std;

class UBigNumber {
public:
	UBigNumber();                //�޲ι��죬�������
	~UBigNumber();          //��������
	UBigNumber& operator = (const UBigNumber&rhs); //���Ƹ�ֵ
	UBigNumber& operator = (UBigNumber&& rhs) noexcept;  //�ƶ���ֵ 
	UBigNumber(const UBigNumber &);  //�������� 
	UBigNumber(UBigNumber&&)noexcept;  //�ƶ�����

	UBigNumber operator +(const UBigNumber& rhs)const;
	UBigNumber operator *(const UBigNumber& rhs)const;
	UBigNumber operator /(const UBigNumber& rhs)const;
	UBigNumber operator %(const UBigNumber& rhs)const;

	bool operator >(const UBigNumber& rhs)const;
	bool operator <(const UBigNumber& rhs)const;
	bool operator >=(const UBigNumber& rhs)const;
	bool operator <=(const UBigNumber& rhs)const;
	bool operator !=(const UBigNumber& rhs)const;

	void Normalize(UBigNumber* pUBN);//�޷��Ŵ����淶��ʾ��ȥ����λ����0�����ٺ�һλ����
	void Input();
	void Print();

	friend ostream& operator <<(ostream& os, UBigNumber& rhs);
private:
	struct Node {
		int data;
		struct Node* next, * prev;
	}*m_pHead, * m_pTail;

	int m_len;
};

//���캯��
UBigNumber::UBigNumber()
{
	m_pHead = new Node;
	m_pHead->next = NULL;
}
//��������
UBigNumber::~UBigNumber()
{
	while (m_pHead) {
		Node* p = m_pHead;
		m_pHead = p->next;
		delete p;
	}
}
//���Ƹ�ֵ 
UBigNumber& UBigNumber::operator = (const UBigNumber& rhs) {
	UBigNumber tmp(rhs);
	Node *t = m_pHead;
	m_pHead = tmp.m_pHead;
	tmp.m_pHead = t;
	return *this;
}
//�ƶ���ֵ
UBigNumber& UBigNumber::operator=(UBigNumber&& rhs)noexcept
{
	Node* p = this->m_pHead;
	this->m_pHead = rhs.m_pHead;
	rhs.m_pHead = p;
	p = this->m_pTail;
	this->m_pTail = p;
	this->m_len = rhs.m_len;
	return *this;
}
//��������
UBigNumber::UBigNumber(const UBigNumber& rhs)
{
	m_pHead = new Node;
	Node* last = m_pHead;
	Node* p = rhs.m_pHead->next;
	while (p) {
		Node* q = new Node;
		q->data = p->data;
		last->next = q;
		q->prev = last;
		last = q;
		p = p->next;
	}
	last->next = NULL;
}
//�ƶ�����
UBigNumber::UBigNumber(UBigNumber&& rhs)noexcept
{
	m_pHead = rhs.m_pHead;
	rhs.m_pHead = NULL;
}

UBigNumber UBigNumber::operator +(const UBigNumber& rhs)const
{
	UBigNumber result;
	Node* front = new Node;
	Node* s = front;	//Ϊ�˺�ԭ�����������һ���Ľṹ������ͷ�����յ�β��㣻 
	Node* p = m_pTail;
	Node* q = rhs.m_pTail;
	int jw = 0;
	for (int i = 0; i < min(m_len, rhs.m_len); i++) {
		Node* newnode = new Node;
		newnode->data = (p->data + q->data + jw) % 10;
		jw = (p->data + q->data + jw) / 10;
		newnode->next = front;
		front->prev = newnode;
		front = newnode;
		p = p->prev;
		q = q->prev;
	}
	if (m_len > min(m_len, rhs.m_len)) {
		for (int i = 0; i < m_len - min(m_len, rhs.m_len); i++) {
			Node* newnode = new Node;
			newnode->data = (p->data + jw) % 10;
			jw = (p->data + jw) / 10;
			newnode->next = front;
			front->prev = newnode;
			front = newnode;
			p = p->prev;
		}
		if (jw > 0) {
			Node* newnode = new Node;
			newnode->data = jw;
			newnode->next = front;
			front->prev = newnode;
			front = newnode;
			result.m_pHead->next = front;
			front->prev = result.m_pHead;
			result.m_len = m_len + 1;
		}
		else {
			result.m_pHead->next = front;
			front->prev = result.m_pHead;
			result.m_len = m_len;
		}
	}
	else if (rhs.m_len > min(m_len, rhs.m_len)) {
		for (int i = 0; i < rhs.m_len - min(m_len, rhs.m_len); i++) {
			Node* newnode = new Node;
			newnode->data = (q->data + jw) % 10;
			jw = (q->data + jw) / 10;
			newnode->next = front;
			front->prev = newnode;
			front = newnode;
			q = q->prev;
		}
		if (jw > 0) {
			Node* newnode = new Node;
			newnode->data = jw;
			newnode->next = front;
			front->prev = newnode;
			front = newnode;
			result.m_pHead->next = front;
			front->prev = result.m_pHead;
			result.m_len = rhs.m_len + 1;
		}
		else {
			result.m_pHead->next = front;
			front->prev = result.m_pHead;
			result.m_len = rhs.m_len;
		}
	}
	else {
		if (jw > 0) {
			Node* newnode = new Node;
			newnode->data = jw;
			newnode->next = front;
			front->prev = newnode;
			front = newnode;
			result.m_pHead->next = front;
			front->prev = result.m_pHead;
			result.m_len = rhs.m_len + 1;
		}
		else {
			result.m_pHead->next = front;
			front->prev = result.m_pHead;
			result.m_len = rhs.m_len;
		}
	}
	result.m_pTail = s->prev;
	s->prev->next = NULL;
	delete s;
	return result;
}

bool UBigNumber::operator >(const UBigNumber& rhs)const
{
	if (m_len < rhs.m_len)
		return 0;
	else if (m_len > rhs.m_len)
		return 1;
	else {
		Node* p1 = m_pTail;
		Node* p2 = rhs.m_pTail;
		int i = 1;
		while (i < m_len && p1->data == p2->data) {
			p1 = p1->prev;
			p2 = p2->prev;
			++i;
		}
		if (p1->data > p2->data)
			return 1;
		else
			return 0;
	}
}
bool UBigNumber::operator <(const UBigNumber& rhs)const
{
	if (*this > rhs == 0 && *this != rhs == 1)
		return 1;
	else
		return 0;
}
bool UBigNumber::operator >=(const UBigNumber& rhs)const
{
	if (*this > rhs || *this != rhs == 0)
		return 1;
	else
		return 0;
}
bool UBigNumber::operator <=(const UBigNumber& rhs)const
{
	if (*this < rhs || *this != rhs == 0)
		return 1;
	else
		return 0;
}
bool UBigNumber::operator !=(const UBigNumber& rhs)const
{
	if (m_len < rhs.m_len)
		return 1;
	else if (m_len > rhs.m_len)
		return 1;
	else {
		Node* p1 = m_pTail;
		Node* p2 = rhs.m_pTail;
		int i = 1;
		while (i < m_len && p1->data == p2->data) {
			p1 = p1->prev;
			p2 = p2->prev;
			++i;
		}
		if (p1->data == p2->data)
			return 0;
		else
			return 1;
	}
}

void UBigNumber::Input()
{
	string s;
	cin >> s;
	Node* p = m_pHead;
	int i = 0;
	while (s[i] != '\0') {
		Node* q = new Node;
		q->data = s[i] - '0';
		p->next = q;
		q->prev = p;
		p = q;
		i++;
	}
	m_pTail = p;
	m_len = i;
}
void UBigNumber::Print()
{
	Node* p = m_pHead->next;
	for (int i = 0; i < m_len; i++) {
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

int main()
{
	UBigNumber B1,B2,B3;
	B1.Input();
	B2.Input();
	B3 = B1 + B2;
	B1.Print();
	cout << " + ";
	B2.Print();
	cout << " = ";
	B3.Print();
}
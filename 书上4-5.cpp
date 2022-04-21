/*5.设计并实现一个具有构造、＋、*、/、%、>、<、>=、＜=、!=、＜＜等功能的无符号大数类。
提示：为便于运算，无符号大数内部存放连续十进制位时采用低位在前、高位在后的方式，
去除高位多余的0。无符号大数类应支持复制和赋值。*/
#include <iostream>

using namespace std;

class UBigNumber {
public:
	UBigNumber();                //无参构造，构造空链
	~UBigNumber();          //析构函数
	UBigNumber& operator = (const UBigNumber&rhs); //复制赋值
	UBigNumber& operator = (UBigNumber&& rhs) noexcept;  //移动赋值 
	UBigNumber(const UBigNumber &);  //拷贝构造 
	UBigNumber(UBigNumber&&)noexcept;  //移动构造

	UBigNumber operator +(const UBigNumber& rhs)const;
	UBigNumber operator *(const UBigNumber& rhs)const;
	UBigNumber operator /(const UBigNumber& rhs)const;
	UBigNumber operator %(const UBigNumber& rhs)const;

	bool operator >(const UBigNumber& rhs)const;
	bool operator <(const UBigNumber& rhs)const;
	bool operator >=(const UBigNumber& rhs)const;
	bool operator <=(const UBigNumber& rhs)const;
	bool operator !=(const UBigNumber& rhs)const;

	void Normalize(UBigNumber* pUBN);//无符号大数规范表示，去除高位多余0，至少含一位数字
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

//构造函数
UBigNumber::UBigNumber()
{
	m_pHead = new Node;
	m_pHead->next = NULL;
}
//析构函数
UBigNumber::~UBigNumber()
{
	while (m_pHead) {
		Node* p = m_pHead;
		m_pHead = p->next;
		delete p;
	}
}
//复制赋值 
UBigNumber& UBigNumber::operator = (const UBigNumber& rhs) {
	UBigNumber tmp(rhs);
	Node *t = m_pHead;
	m_pHead = tmp.m_pHead;
	tmp.m_pHead = t;
	return *this;
}
//移动赋值
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
//拷贝构造
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
//移动构造
UBigNumber::UBigNumber(UBigNumber&& rhs)noexcept
{
	m_pHead = rhs.m_pHead;
	rhs.m_pHead = NULL;
}

UBigNumber UBigNumber::operator +(const UBigNumber& rhs)const
{
	UBigNumber result;
	Node* front = new Node;
	Node* s = front;	//为了和原来的链表具有一样的结构，最后释放这个空的尾结点； 
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

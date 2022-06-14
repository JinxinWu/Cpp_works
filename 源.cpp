/*ģ�� STL stack ��ģ��ӿڣ����ʵ�� CStack ��ģ�壬�����������ջ����ջ����ջ
�ա�ȡջ��Ԫ�صȹ��ܣ���֧�ֿ������ơ����ⲻ��ʹ�� STL stack��������ʹ�� STL ��
��������������ʹ�� CStack ��ģ��Ĳ��Գ��������������н����*/
//��ʾջ���ݺ���ģ�嶨��
#include <iostream>
#include <deque>
using namespace std;
template <class T>
class CStack
{
private:
	deque<T> m_cont;
public:
	inline void push(const T& x);
	inline bool empty()const;
	inline const T& top()const;
	inline void pop();
};
template <class T>
void CStack<T>::push(const T& x)
{
	m_cont.push_back(x);
}
template <class T>
bool CStack<T>::empty()const
{
	return m_cont.empty();
}
template <class T>
const T& CStack<T>::top()const
{
	return m_cont.back();
}
template <class T>
void CStack<T>::pop()
{
	m_cont.pop_back();
}
template <class T>
void Dump(ostream& os, CStack<T>& S)
{
	while (!S.empty())//�൱��!S.empty (),��Ҫ���ڲ�����Ԫ
	{
		os << S.top() << " ";
		S.pop();
	}
	os << endl;
}
int main()
{
	int n, i;
	cin >> n; //����ָ������
	CStack<string> S1, S2; //���� T ģ����� 2 ��ջ����
	for (i = 0; i < n; i++)
	{
		int v;
		string x;
		//ִ������ÿ��ָ��
		cin >> v >> x;
		if (v == 1)
			S1.push(x);
		else
			S2.push(x);
	}
	//��ʾջ����
	Dump(cout, S1);
	Dump(cout, S2);
}
/*模拟 STL stack 类模板接口，设计实现 CStack 类模板，该类需具有入栈、出栈、判栈
空、取栈顶元素等功能，并支持拷贝控制。本题不可使用 STL stack，但可以使用 STL 其
它容器。下面是使用 CStack 类模板的测试程序和输入输出运行结果。*/
//显示栈内容函数模板定义
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
	while (!S.empty())//相当于!S.empty (),主要用于测试友元
	{
		os << S.top() << " ";
		S.pop();
	}
	os << endl;
}
int main()
{
	int n, i;
	cin >> n; //读入指令数量
	CStack<string> S1, S2; //建立 T 模板类的 2 个栈对象
	for (i = 0; i < n; i++)
	{
		int v;
		string x;
		//执行输入每条指令
		cin >> v >> x;
		if (v == 1)
			S1.push(x);
		else
			S2.push(x);
	}
	//显示栈内容
	Dump(cout, S1);
	Dump(cout, S2);
}

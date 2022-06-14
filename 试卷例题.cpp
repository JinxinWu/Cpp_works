/*应用中经常遇到大数运算问题。请在标准容器链表或双端队列基础上，设计实现无符号
大数类 CUBigNumber，要求完成无符号大数类的无参构造、输入、输出、+功能。下述是
使用无符号大数类 CUBigNumber 的样例程序和输入、输出结果。*/
#include <iostream>
#include <list>
#include <assert.h>
using namespace std;
class CUBigNumber
{
public:
	CUBigNumber();
	friend istream& operator >>(istream& is, CUBigNumber& rhs);
	friend ostream& operator <<(ostream& os, CUBigNumber& rhs);
	CUBigNumber operator+(CUBigNumber& rhs)const;
private:
	list<int> _1st;
};
CUBigNumber::CUBigNumber()
{
	_1st.push_back(0);
}
ostream& operator <<(ostream& os, CUBigNumber& rhs)
{
	assert(rhs._1st.size() > 0);
	for (auto it = rhs._1st.begin(); it != rhs._1st.end(); ++it)
		os << *it;
	return os;
}
istream& operator >>(istream& is, CUBigNumber& rhs)
{
	string str;
	is >> str;
	CUBigNumber result;
	result._1st.pop_front();
	for (auto it = str.begin(); it != str.end(); ++it)
		result._1st.push_back(*it - '0');
	rhs = std::move(result);
	return is;
}
CUBigNumber CUBigNumber::operator+(CUBigNumber& rhs)const
{
	CUBigNumber result;
	result._1st.pop_front();
	int iCarry = 0;
	auto it1 = _1st.rbegin();
	auto it2 = rhs._1st.rbegin();
	while (it1 != _1st.rend() && it2 != rhs._1st.rend())
	{
		int digit = *it1 + *it2 + iCarry;
		iCarry = digit / 10;
		digit = digit % 10;
		result._1st.push_front(digit);
		++it1; ++it2;
	}
	while (it1 != _1st.rend())
	{
		int digit = *it1 + iCarry;
		iCarry = digit / 10;
		digit = digit % 10;
		result._1st.push_front(digit);
		++it1;
	}
	while (it2 != rhs._1st.rend())
	{
		int digit = *it2 + iCarry;
		iCarry = digit / 10;
		digit %= 10;
		result._1st.pop_front();
		++it2;
	}
	if (iCarry != 0)
		result._1st.push_front(iCarry);
	return result;
}
int main()
{
	CUBigNumber A, B, C;
	cin >> A >> B; //从标准输入流读入无符号大数
	C = A + B; //无符号大数相加
	cout << A << "+" << B << "=" << C << endl;
}

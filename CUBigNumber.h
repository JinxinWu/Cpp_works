#pragma once
#include <iostream>
#include <list>
#include <string>
#include <assert.h>

using namespace std;

class CUBigNumber {
public:
	//无参构造无符号大数0
	CUBigNumber();

	//从输入流读入一个无符号大数
	friend istream& operator >> (istream& is, CUBigNumber& rhs);
	//显示无符号大数
	friend ostream& operator << (ostream& os, const CUBigNumber& rhs);

	bool    operator > (const CUBigNumber& rhs) const;
	bool    operator < (const CUBigNumber& rhs) const;
	bool    operator == (const CUBigNumber& rhs) const;
	bool    operator != (const CUBigNumber& rhs) const;
	bool    operator >= (const CUBigNumber& rhs) const;
	bool    operator <= (const CUBigNumber& rhs) const;

	//两个无符号大数相加
	CUBigNumber operator + (const CUBigNumber& rhs) const;
	//两个无符号大数相减
	CUBigNumber operator - ( CUBigNumber& rhs);
	//两个无符号大数相乘
	CUBigNumber operator * (const CUBigNumber& rhs) const;
	//两个无符号大数相除
	CUBigNumber operator / (const CUBigNumber& rhs) const;
	//两个无符号大数取余
	CUBigNumber operator % (const CUBigNumber& rhs) const;
	//无符号大数自增 先++，返回新时间
	CUBigNumber& operator ++ ();
private:
	list<int>_1st;//本类没有使用动态分配，无需定义拷贝控制函数
	void _Normalize();
};

void TestCompare(CUBigNumber& C1, CUBigNumber& C2)
{
	int text = C1 > C2;
	cout << "大于判断" << text << " ";
	text = C1 < C2;
	cout << "小于判断" << text << " ";
	text = C1 == C2;
	cout << "等于判断" << text << " ";
	text = C1 != C2;
	cout << "不等于判断" << text << " ";
	text = C1 >= C2;
	cout << "大于或等于判断" << text << " ";
	text = C1 <= C2;
	cout << "小于或等于判断" << text << " ";
	cout << endl;
}

void TextOperation(CUBigNumber& M, CUBigNumber& N)
{
	CUBigNumber A,B,C,D,E;
	//加法测试
	A = M + N;
	cout << M << " + " << N << " = " << A <<endl;
	//减法测试（由于减法运算里直接运用了std::move，函数后无const,可能会改变一些东西，那不如直接重新赋值，不干扰其他函数）
	CUBigNumber C1 = M, C2 = N;
	B = C1 - C2;
	if(M < N)
		cout << M << " - " << N << " = " << "-" << B << endl;
	else
		cout << M << " - " << N << " = " << B << endl;
	//乘法测试
	C = M * N;
	cout << M << " * " << N << " = " << C << endl;
	//除法测试
	D = M / N;
	cout << M << " / " << N << " = " << D << endl;
	//取余测试
	E = M % N;
	cout << M << " % " << N << " = " << E << endl;
	//自增测试
	CUBigNumber T1 = M, _T1 = M, T2 = N, _T2 = N;
	cout << "++" << T1 << " = " << ++_T1 << endl;
	cout << "++" << T2 << " = " << ++_T2 << endl;
}

void CUBigNumber::_Normalize()
{
	list<int>::iterator it;
	for (auto it = _1st.begin(); it != _1st.end() && *it == 0;)
	{
		++it;
		_1st.pop_front();
	}
}

//无参构造无符号大数0
CUBigNumber::CUBigNumber()
{
	_1st.push_back(0);//一位数：0
}
//从输入流读入一个无符号大数
istream& operator >> (istream& is, CUBigNumber& rhs)
{
	string str;
	is >> str;
	CUBigNumber result;//结果先存放在临时对象里
	result._1st.pop_front();//丢弃高位0
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		result._1st.push_back(*it - '0');//添加1位
	}
	if (result._1st.size() != 1)//输入为0时，不能高位去0
		result._Normalize();
	rhs = std::move(result);//读入的无符号大数转移赋值给当前变量
	return is;
}
//显示无符号大数
ostream& operator << (ostream& os, const CUBigNumber& rhs)
{
	assert(rhs._1st.size() > 0);
	list<int>::iterator list_iter;
	for (auto list_iter = rhs._1st.begin(); list_iter != rhs._1st.end(); ++list_iter)
	{
		os << *list_iter;
	}
	return os;
}

bool    CUBigNumber::operator > (const CUBigNumber& rhs) const
{
	if (_1st.size() > rhs._1st.size())
		return 1;
	else if (_1st.size() < rhs._1st.size() || *this == rhs)
		return 0;
	else
	{
		auto it1 = _1st.begin(), it2 = rhs._1st.begin();//从前往后判断
		while (it1 != _1st.end() && it2 != rhs._1st.end() && *it1 == *it2)
		{
			++it1;
			++it2;
		}
		if (*it1 > *it2)
			return 1;
		else
			return 0;
	}
}
bool    CUBigNumber::operator < (const CUBigNumber& rhs) const
{
	if (*this > rhs || *this == rhs)
		return 0;
	else
		return 1;
}
bool    CUBigNumber::operator == (const CUBigNumber& rhs) const
{
	if (_1st == rhs._1st)
		return 1;
	else
		return 0;
}
bool    CUBigNumber::operator != (const CUBigNumber& rhs) const
{
	if (*this == rhs)
		return 0;
	else
		return 1;
}
bool    CUBigNumber::operator >= (const CUBigNumber& rhs) const
{
	if (*this > rhs || *this == rhs)
		return 1;
	else
		return 0;
}
bool    CUBigNumber::operator <= (const CUBigNumber& rhs) const
{
	if (*this < rhs || *this == rhs)
		return 1;
	else
		return 0;
}

//两个无符号大数相加
CUBigNumber CUBigNumber::operator + (const CUBigNumber& rhs) const
{
	CUBigNumber result;
	result._1st.pop_front();
	int iCarry = 0;
	auto it1 = _1st.rbegin(), it2 = rhs._1st.rbegin();//从后往前判断
	while (it1 != _1st.rend() && it2 != rhs._1st.rend())
	{
		int digit = *it1 + *it2 + iCarry;
		iCarry = digit / 10;
		digit %= 10;
		result._1st.push_front(digit);
		++it1; ++it2;
	}
	while (it1 != _1st.rend())
	{
		int digit = *it1 + iCarry;
		iCarry = digit / 10;
		digit %= 10;
		result._1st.push_front(digit);
		++it1;
	}
	while (it2 != rhs._1st.rend())
	{
		int digit = *it2 + iCarry;
		iCarry = digit / 10;
		digit %= 10;
		result._1st.push_front(digit);
		++it2;
	}
	if (iCarry != 0)
		result._1st.push_front(iCarry);
	if (result._1st.size() != 1)
		result._Normalize();
	return result;
}
//两个无符号大数相减
CUBigNumber CUBigNumber::operator - (CUBigNumber& rhs)
{
	if (*this < rhs)
	{
		CUBigNumber temp = std::move(rhs);
		rhs = std::move(*this);
		*this = std::move(temp);
	}
	CUBigNumber result;
	result._1st.pop_front();//弹出高位0
	int iCarry = 0;//借位
	auto it1 = _1st.rbegin(), it2 = rhs._1st.rbegin();//从后往前判断
	while (it1 != _1st.rend() && it2 != rhs._1st.rend())//it2到达最高位时停止
	{
		int digit = *it1 - *it2 + iCarry;
		if (digit < 0)
		{
			digit += 10;
			iCarry = -1;
		}
		else
			iCarry = 0;
		++it1;
		++it2;
		result._1st.push_front(digit);
	}
	while (it1 != _1st.rend())//it1完成剩余位数
	{
		int digit = *it1 + iCarry;
		if (digit < 0)
			iCarry = -1;
		else
			iCarry = 0;
		++it1;
		result._1st.push_front(digit);
	}
	if (result._1st.size() != 1)
		result._Normalize();
	if (result._1st.size() == 0)
		result._1st.push_front(0);
	return result;
}
//两个无符号大数相乘
CUBigNumber CUBigNumber::operator * (const CUBigNumber& rhs) const
{
	CUBigNumber result;
	if (_1st.size() == 1 && _1st.front() == 0 || rhs._1st.size() == 1 && rhs._1st.front() == 0)
		return result;
	result._1st.pop_front();
	int count = 0;
	auto it = rhs._1st.rbegin();
	while (it != rhs._1st.rend())
	{
		CUBigNumber Temp;
		for (int i = 0; i < *it; ++i)
		{
			Temp = Temp + *this;
		}
		for (int j = 0; j < count; ++j)//count记录要多加几个0
		{
			Temp._1st.push_back(0);
		}
		result = result + Temp;
		++it;
		++count;
	}
	if (result._1st.size() != 1)
		result._Normalize();
	return result;
}
//两个无符号大数相除 整数除法
CUBigNumber CUBigNumber::operator / (const CUBigNumber& rhs) const
{
	CUBigNumber result, sum = rhs;
	if (_1st.size() == 1 && _1st.front() == 0)//被除数位0，直接输出0
		return result;
	if (rhs._1st.size() == 1 && rhs._1st.front() == 0)//除数为0，无意义
		return result;
	while (sum <= *this)
	{
		sum = sum + rhs;
		++result;
	}
	return result;
}
//两个无符号大数取余
CUBigNumber CUBigNumber::operator % (const CUBigNumber& rhs) const
{
	CUBigNumber _temp = *this;
	CUBigNumber temp = *this / rhs;
	CUBigNumber temp1 = temp * rhs;
	CUBigNumber result = _temp - (temp1);
	return result;
}
//无符号大数自增 先++，返回新时间
CUBigNumber& CUBigNumber::operator ++ ()
{
	CUBigNumber C1;
	C1._1st.pop_front();
	C1._1st.push_front(1);

	*this = *this + C1;
	return *this;
}
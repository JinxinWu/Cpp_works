#pragma once
#include <iostream>
#include <list>
#include <string>
#include <assert.h>

using namespace std;

class CUBigNumber {
public:
	//�޲ι����޷��Ŵ���0
	CUBigNumber();

	//������������һ���޷��Ŵ���
	friend istream& operator >> (istream& is, CUBigNumber& rhs);
	//��ʾ�޷��Ŵ���
	friend ostream& operator << (ostream& os, const CUBigNumber& rhs);

	bool    operator > (const CUBigNumber& rhs) const;
	bool    operator < (const CUBigNumber& rhs) const;
	bool    operator == (const CUBigNumber& rhs) const;
	bool    operator != (const CUBigNumber& rhs) const;
	bool    operator >= (const CUBigNumber& rhs) const;
	bool    operator <= (const CUBigNumber& rhs) const;

	//�����޷��Ŵ������
	CUBigNumber operator + (const CUBigNumber& rhs) const;
	//�����޷��Ŵ������
	CUBigNumber operator - ( CUBigNumber& rhs);
	//�����޷��Ŵ������
	CUBigNumber operator * (const CUBigNumber& rhs) const;
	//�����޷��Ŵ������
	CUBigNumber operator / (const CUBigNumber& rhs) const;
	//�����޷��Ŵ���ȡ��
	CUBigNumber operator % (const CUBigNumber& rhs) const;
	//�޷��Ŵ������� ��++��������ʱ��
	CUBigNumber& operator ++ ();
private:
	list<int>_1st;//����û��ʹ�ö�̬���䣬���趨�忽�����ƺ���
	void _Normalize();
};

void TestCompare(CUBigNumber& C1, CUBigNumber& C2)
{
	int text = C1 > C2;
	cout << "�����ж�" << text << " ";
	text = C1 < C2;
	cout << "С���ж�" << text << " ";
	text = C1 == C2;
	cout << "�����ж�" << text << " ";
	text = C1 != C2;
	cout << "�������ж�" << text << " ";
	text = C1 >= C2;
	cout << "���ڻ�����ж�" << text << " ";
	text = C1 <= C2;
	cout << "С�ڻ�����ж�" << text << " ";
	cout << endl;
}

void TextOperation(CUBigNumber& M, CUBigNumber& N)
{
	CUBigNumber A,B,C,D,E;
	//�ӷ�����
	A = M + N;
	cout << M << " + " << N << " = " << A <<endl;
	//�������ԣ����ڼ���������ֱ��������std::move����������const,���ܻ�ı�һЩ�������ǲ���ֱ�����¸�ֵ������������������
	CUBigNumber C1 = M, C2 = N;
	B = C1 - C2;
	if(M < N)
		cout << M << " - " << N << " = " << "-" << B << endl;
	else
		cout << M << " - " << N << " = " << B << endl;
	//�˷�����
	C = M * N;
	cout << M << " * " << N << " = " << C << endl;
	//��������
	D = M / N;
	cout << M << " / " << N << " = " << D << endl;
	//ȡ�����
	E = M % N;
	cout << M << " % " << N << " = " << E << endl;
	//��������
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

//�޲ι����޷��Ŵ���0
CUBigNumber::CUBigNumber()
{
	_1st.push_back(0);//һλ����0
}
//������������һ���޷��Ŵ���
istream& operator >> (istream& is, CUBigNumber& rhs)
{
	string str;
	is >> str;
	CUBigNumber result;//����ȴ������ʱ������
	result._1st.pop_front();//������λ0
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		result._1st.push_back(*it - '0');//���1λ
	}
	if (result._1st.size() != 1)//����Ϊ0ʱ�����ܸ�λȥ0
		result._Normalize();
	rhs = std::move(result);//������޷��Ŵ���ת�Ƹ�ֵ����ǰ����
	return is;
}
//��ʾ�޷��Ŵ���
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
		auto it1 = _1st.begin(), it2 = rhs._1st.begin();//��ǰ�����ж�
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

//�����޷��Ŵ������
CUBigNumber CUBigNumber::operator + (const CUBigNumber& rhs) const
{
	CUBigNumber result;
	result._1st.pop_front();
	int iCarry = 0;
	auto it1 = _1st.rbegin(), it2 = rhs._1st.rbegin();//�Ӻ���ǰ�ж�
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
//�����޷��Ŵ������
CUBigNumber CUBigNumber::operator - (CUBigNumber& rhs)
{
	if (*this < rhs)
	{
		CUBigNumber temp = std::move(rhs);
		rhs = std::move(*this);
		*this = std::move(temp);
	}
	CUBigNumber result;
	result._1st.pop_front();//������λ0
	int iCarry = 0;//��λ
	auto it1 = _1st.rbegin(), it2 = rhs._1st.rbegin();//�Ӻ���ǰ�ж�
	while (it1 != _1st.rend() && it2 != rhs._1st.rend())//it2�������λʱֹͣ
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
	while (it1 != _1st.rend())//it1���ʣ��λ��
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
//�����޷��Ŵ������
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
		for (int j = 0; j < count; ++j)//count��¼Ҫ��Ӽ���0
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
//�����޷��Ŵ������ ��������
CUBigNumber CUBigNumber::operator / (const CUBigNumber& rhs) const
{
	CUBigNumber result, sum = rhs;
	if (_1st.size() == 1 && _1st.front() == 0)//������λ0��ֱ�����0
		return result;
	if (rhs._1st.size() == 1 && rhs._1st.front() == 0)//����Ϊ0��������
		return result;
	while (sum <= *this)
	{
		sum = sum + rhs;
		++result;
	}
	return result;
}
//�����޷��Ŵ���ȡ��
CUBigNumber CUBigNumber::operator % (const CUBigNumber& rhs) const
{
	CUBigNumber _temp = *this;
	CUBigNumber temp = *this / rhs;
	CUBigNumber temp1 = temp * rhs;
	CUBigNumber result = _temp - (temp1);
	return result;
}
//�޷��Ŵ������� ��++��������ʱ��
CUBigNumber& CUBigNumber::operator ++ ()
{
	CUBigNumber C1;
	C1._1st.pop_front();
	C1._1st.push_front(1);

	*this = *this + C1;
	return *this;
}
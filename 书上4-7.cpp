/*7.完成如下日期类CDate。*/
#include <iostream>
#include <iomanip>
using namespace std;

class CDate {
public:
	CDate();
	CDate(int year, int month, int day);
	CDate& operator ++();
	CDate& operator --();
	CDate operator ++(int);
	CDate operator +(long days)const;
	CDate operator -(long days)const;
	long operator -(const CDate& rhs)const;
	int MonthDay()const;
	static int ISLeapYear(int year);
	friend ostream& operator<<(ostream&, const CDate&);
private:
	int m_year, m_month, m_day;
};

//若无参数，初始化为2022/4/17
CDate::CDate()
	:m_year(2022), m_month(4), m_day(17)
{}
CDate::CDate(int year, int month, int day)
	: m_year(year), m_month(month), m_day(day)
{}

CDate& CDate::operator ++()
{
	if (++m_day == MonthDay()) {
		m_day = 1;
		if (++m_month == 12) {
			m_month = 1;
			if(++m_year){}
		}
	}
	return *this;
}
CDate& CDate::operator --()
{
	if (--m_day == 0) {
		if (--m_month == 0) {
			m_month = 12;
			m_day = MonthDay();
			--m_year;
		}
		else
			m_day = MonthDay();
	}
	return *this;
}
CDate CDate::operator ++(int)
{
	CDate tmp(*this);
	++(*this);
	return tmp;
}
CDate CDate::operator +(long days)const
{
	CDate tmp(*this);
	for (int i = 0; i < days; i++)
		++tmp;
	return tmp;
}
CDate CDate::operator -(long days)const
{
	CDate tmp(*this);
	for (int i = 0; i < days; i++)
		--tmp;
	return tmp;
}
long CDate::operator -(const CDate& rhs)const
{
	CDate tmp = rhs;
	int count = 0;
	while (tmp.m_year != m_year && tmp.m_month != m_month && tmp.m_day != m_day)
	{
		++tmp;
		++count;
	}
	return count;
}


int CDate::MonthDay()const
{
	if (m_month == 4 || m_month == 6 || m_month == 9 || m_month == 11)
		return 30;
	else if ((m_month == 28 && !ISLeapYear(m_year)))
		return 28;
	else if ((m_month == 29 && ISLeapYear(m_year)))
		return 29;
	else
		return 31;
}
int CDate::ISLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

ostream& operator<<(ostream& os, const CDate& rhs)
{
	cout.fill('0');
	os << setw(4) << rhs.m_year
		<< "-" << setw(2) << rhs.m_month
		<< "-" << setw(2) << rhs.m_day;
	return os;
}

int main()
{
	CDate date1(2022,6,14), date2(2022,4,23), date3, date4;
	cout << date1 << " " << date2 << endl;
	++date1; date2++;
	cout << date1 << " " << date2 << endl;
	date3 = date1 + 200;
	date4 = date2 - 300;
	cout << date3 << " " << date4 << endl;
	cout << date4 - date3 << endl;
}

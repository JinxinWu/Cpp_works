#include <iostream>
using namespace std;
class Date
{
public:
	Date(int year, int month, int day);
	void SetDate(int year, int month, int day);
	void Print();
	bool IsRun();
private:
	int m_year;
	int m_month;
	int m_day;
};
Date::Date(int year = 1990, int month = 1, int day = 1)
{
	m_year = year;
	m_month = month;
	m_day = day;
}
void Date::SetDate(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}
void Date::Print()
{
	cout << m_year << "/" << m_month << "/" << m_day << endl;
}
bool Date::IsRun()
{
	return m_year % 4 == 0 && m_year % 100 != 0 || m_year == 400;
}
int main()
{
	Date date;
	date.Print();
	date.SetDate(2022, 6, 11);
	date.Print();
	if (date.IsRun())
		cout << "a leap year." << endl;
	else
		cout << "not a leap year." << endl;
}
/* 按下列要求编程，实现类的定义，并在主函数中测试这个类。
定义一个描述日期的类 Date，包括的数据成员有年（year）、月（month）和日（day），并实
现如下功能函数；
（1）日期对象初始化；
（2）设置日期；
（3）以 year/month/day 形式输出日期；
（4）判断闰年。*/
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

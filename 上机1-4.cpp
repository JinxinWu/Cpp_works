/*4、友元函数
C++考试正在进行。请设计一个学生类student，学号、本次考试成绩是其私有数据成员，同时有一个计算本次考试平均成绩的友元函数
double average(student *p,int count);
以上类名和友元函数的形式，均须按照题目要求，不得修改。
输入是 学号（[00001,99999]）和成绩，以0结束。（不超过100个学生）
输出是平均成绩。
输入样例：
10001 90
10002 93
0
输出样例：
91.5
*/
#include <iostream>
using namespace std;
#define N 100

class student
{
public:
	void Input(const int num, const double score);
	friend double average(student* p, int count);
private:
	int m_iNum;
	double m_iScore;
};

void student::Input(const int num, const double score)
{
	m_iNum = num;
	m_iScore = score;
}
double average(student* p, int count)
{
	double sum = 0;
	for (int i = 0; i < count; ++i)
	{
		sum += p->m_iScore;
		++p;
	}
	return sum / (count * 1.0);
}

int main()
{
	int count=0, x, y;
	student P[N];
	while (cin >> x)
	{
		cin >> y;
		P[count++].Input(x, y);
	}
	--count;
	cout << average(P, count) << endl;
	return 0;
}

/*4����Ԫ����
C++�������ڽ��С������һ��ѧ����student��ѧ�š����ο��Գɼ�����˽�����ݳ�Ա��ͬʱ��һ�����㱾�ο���ƽ���ɼ�����Ԫ����
double average(student *p,int count);
������������Ԫ��������ʽ�����밴����ĿҪ�󣬲����޸ġ�
������ ѧ�ţ�[00001,99999]���ͳɼ�����0��������������100��ѧ����
�����ƽ���ɼ���
����������
10001 90
10002 93
0
���������
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
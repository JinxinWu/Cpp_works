/*1������һ��Date��
����һ����������Ҫ���Date�ࣺ
�����е����ݸ�ʽ�������
��-��-��
�������룺
1978 5 2
2020 12 12
�����ʽ:
1978-05-02
2020-12-12
*/
#include <iostream>
using namespace std;

class Date
{
public:
	void Format();//��ʽת������
	void Input(int x, int y, int z);//���뺯��
private:
	int year, month, day;
};

void Date::Format()
{
	cout << year << "-";
	if (month < 10)
		cout << "0" << month << "-";
	else
		cout << month << "-";
	if (day < 10)
		cout << "0" << day << endl;
	else
		cout << day << endl;
}
void Date::Input(int x, int y, int z)
{
	year = x;
	month = y;
	day = z;
}

int main()
{
	int x = 0, y = 0, z = 0, count = 0;
	Date A[100];
	while (cin >> x >> y >> z)
	{
		A[count].Input(x, y, z);
		++count;
	}
	for (int i = 0; i < count; i++)
	{
		A[i].Format();
	}
	return 0;
}
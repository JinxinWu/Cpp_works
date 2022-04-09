/*2、设计一个People类
设计一个People 类，该类的数据成员有姓名、年龄、身高、体重和人数，其中人数为静态数据成员，
成员函数有构造函数、显示和显示人数。其中构造函数由参数姓名、年龄、身高和体重来构造对象；
显示函数用于显示人的姓名、年龄、身高和体重；显示人数函数为静态成员函数，用于显示总的人数。
输入格式:
按姓名、年龄、身高和体重依次输入每个人的信息
以exit结束
zhang 18 180 70
li 20 160 50
exit
输出格式:
输出总人数，例如
2
*/
#include <iostream>
using namespace std;
#define N 1000

class People
{
public:
	void Input(const string name, const int age, const int height, const int weight);
	void Show() const;
	static int ShowCount();
private:
	string m_name;
	int m_age,m_height,m_weight;
	static int _iCount;
};

void People::Input(const string name, const int age, const int height, const int weight)
{
	m_name = name;
	m_age = age;
	m_height = height;
	m_weight = weight;
	++_iCount;
}
void People::Show() const
{
	cout << m_name << " " << m_age << " " << m_height << " " << m_weight << endl;
}
int People::ShowCount()
{
	return _iCount;
}

int People::_iCount = 0;//初始化静态数据成员
int main()
{
	string name;
	int age, height, weight, count = 0;
	People A[N];
	while (cin >> name >> age >> height >> weight && name != "exit")
	{
		A[count].Input(name, age, height, weight);
		count++;
	}
	for (int i = 0; i < count; i++)
	{
		A[i].Show();
	}
	return 0;
}
/*题设中要求利用构造函数赋初值后实现，但鄙人用class定义了一个类数组，也就是在赋初值后实现再赋值，不知如何实现构造函数的方法*/


/*设计顺序查找数组元素函数模板，编写测试程序，利用该函数模板，分别完成整型数组查找和字符串数组查找。*/
#include <iostream>
using namespace std;

int num[10] = { 2,5,6,12,15,18,26,27,28,32 };
string str[10] = { "wu","wang","he","chen","an","gao","zeng","huang","zhang","mao" };

template <typename T>
const int Seek(const T a[], const int n, const T& goal)
{
	int i, j = 0, count = 0;
	for (i = 0; i < n; ++i)
	{
		if (a[i] == goal)
		{
			return i + 1;
			j = 1;
		}
	}
	if (j == 0)
		return 0;
}
int main()
{
	int a;
	string b;
	cout << "请输入一个数和一个字符串，并用空格隔开:" << endl;
	cin >> a >> b;
	if (Seek(num, 10, a))
		cout << a << "在第" << Seek(num, 10, a) << "个位置" << endl;
	else
		cout << "查无此数" << endl;
	if (Seek(str, 10, b))
		cout << b << "在第" << Seek(str, 10, b) << "个位置" << endl;
	else
		cout << "查无此字符串" << endl;
}
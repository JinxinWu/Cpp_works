/*���˳���������Ԫ�غ���ģ�壬��д���Գ������øú���ģ�壬�ֱ��������������Һ��ַ���������ҡ�*/
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
	cout << "������һ������һ���ַ��������ÿո����:" << endl;
	cin >> a >> b;
	if (Seek(num, 10, a))
		cout << a << "�ڵ�" << Seek(num, 10, a) << "��λ��" << endl;
	else
		cout << "���޴���" << endl;
	if (Seek(str, 10, b))
		cout << b << "�ڵ�" << Seek(str, 10, b) << "��λ��" << endl;
	else
		cout << "���޴��ַ���" << endl;
}
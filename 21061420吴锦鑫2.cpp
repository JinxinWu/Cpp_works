/*2�����һ��People��
���һ��People �࣬��������ݳ�Ա�����������䡢��ߡ����غ���������������Ϊ��̬���ݳ�Ա��
��Ա�����й��캯������ʾ����ʾ���������й��캯���ɲ������������䡢��ߺ��������������
��ʾ����������ʾ�˵����������䡢��ߺ����أ���ʾ��������Ϊ��̬��Ա������������ʾ�ܵ�������
�����ʽ:
�����������䡢��ߺ�������������ÿ���˵���Ϣ
��exit����
zhang 18 180 70
li 20 160 50
exit
�����ʽ:
���������������
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

int People::_iCount = 0;//��ʼ����̬���ݳ�Ա
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
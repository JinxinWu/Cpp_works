/*5���Զ�����mystringʵ�������=����
�Զ����ַ����� mystring������˽�г�Ա����char *buf����Ա����������
�޲ι��캯�������"construct 0"�������ι��캯�������"construct 1"����
�������������"destruct"������������������������=���ֱ�����mystring 
��strcpy��strcat��������"c++"֮����Ӽ��������ַ�����Ϣ������main����
�зֱ���2�� mystring�����str1��str2��ֱ��ͨ�����str2=str1;ʹstr2��
����Ϣ��ֵΪ��c++����str1���ַ��������ӽ�����ֱ����str1��str2���ַ�����
�����ʽ:
��һ���и����ַ�����������50���ַ�����
�����ʽ:
�ֱ�����������������ʾ��Ϣ����2���зֱ����str1��str2��ֵ��
*/
#include <iostream>
#include <string.h>
using namespace std;
#define N 100

class mystring
{
public:
	mystring() {
		buf = new char[N];
		cout << "construct 0" << endl;
	}
	mystring(char* ch) {
		buf = new char[N];
		strcpy_s(buf, N, ch);
		cout << "construct 1" << endl;
	}
	~mystring() {
		cout << "destruct" << endl;
	}
	void operator=(mystring& s);//&��ʾ����ʵ��
	void show(){
		cout << buf << endl;
	}
private:
	char* buf;//�ַ����͵�ָ��
};
void mystring::operator=(mystring& s)//&��ʾ����ʵ��
{
	strcpy_s(buf, N, "c++");
	strcat_s(buf, N, s.buf);
}

int main()
{
	char* str = new char[N];

	cin >> str;
	mystring str1(str);
	str1.show();
	mystring str2;
	str2 = str1;
	str2.show();

	return 0;
}

/*strcpy_s������ͷ�ļ�<string.h>��
��һ��������Ŀ���ַ���ָ��
�ڶ����������ַ������ȣ���ʹ��strlen()����ֱ��������мǣ���ʹ��strlen()����ַ�������ʱ������+1
�����������������ַ���ָ��*/
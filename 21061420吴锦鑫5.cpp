/*5、自定义类mystring实现运算符=重载
自定义字符串类 mystring，包含私有成员变量char *buf；成员函数包括：
无参构造函数（输出"construct 0"）、带参构造函数（输出"construct 1"）、
析构函数（输出"destruct"），输出函数，并重载运算符=（分别用类mystring 
和strcpy、strcat函数，在"c++"之后添加键盘输入字符串信息）；在main（）
中分别定义2个 mystring类对象str1和str2，直接通过语句str2=str1;使str2中
的信息赋值为“c++”与str1中字符串的连接结果，分别输出str1和str2的字符串。
输入格式:
在一行中给出字符个数不超过50的字符串。
输出格式:
分别输出构造和析构的提示信息，在2行中分别输出str1和str2的值。
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
	void operator=(mystring& s);//&表示引用实参
	void show(){
		cout << buf << endl;
	}
private:
	char* buf;//字符类型的指针
};
void mystring::operator=(mystring& s)//&表示引用实参
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

/*strcpy_s包含在头文件<string.h>中
第一个参数：目标字符串指针
第二个参数：字符串长度，可使用strlen()函数直接求出，切记，在使用strlen()求出字符串长度时，勿忘+1
第三个参数：输入字符串指针*/
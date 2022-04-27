/*5.设计并实现一个具有构造、＋、*、/、%、>、<、>=、＜=、!=、＜＜等功能的无符号大数类。
提示：为便于运算，无符号大数内部存放连续十进制位时采用低位在前、高位在后的方式，
去除高位多余的0。无符号大数类应支持复制和赋值。*/
#include "CUBigNumber.h"

int main()
{
	CUBigNumber C1, C2;
	cin >> C1;
	cin	>> C2;
	//测试比较运算符
	TestCompare(C1, C2);
	//测试加减乘除等运算符
	TextOperation(C1, C2);
}
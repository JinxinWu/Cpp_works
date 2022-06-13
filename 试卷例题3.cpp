/*定义一个矩阵类（Matrix），设计相关的构造函数、析构函数等，采用运算符重载方式
实现矩阵的加、减运算。编写 main 函数，对以上所有功能进行测试。注意：按照实际情况
大小使用内存空间，矩阵的加、减运算不要造成内存浪费。*/
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
class Matrix {
public:
	Matrix(int row, int col); //构造 row x col 大小矩阵
	Matrix operator + (const Matrix& rhs) const;//相同大小矩阵相加
	Matrix operator - (const Matrix& rhs) const;//相同大小矩阵相减
	void Display() const;//显示矩阵
	//矩阵元素，可作为右值
	const int& at(int row, int col) const {
		return _datas[row][col];
	}
	//矩阵元素，可作为左值
	int& at(int row, int col) {
		return _datas[row][col];
	}
	//矩阵行数
	int GetRowCount() const {
		return _datas.size();
	}
	//矩阵列数
	int GetColCount() const {
		return _datas[0].size();
	}
private:
	//存放矩阵元素， 本类没有直接动态分配，无需重载拷贝构造和赋值
	vector<vector<int> > _datas;
};
Matrix::Matrix(int row, int col)
{
	for (int i = 0; i < row; i++) {
		vector<int> dataRow(col); _datas.push_back(dataRow);
	}
}
Matrix Matrix::operator + (const Matrix& rhs) const
{
	Matrix result(this->GetRowCount(), this->GetColCount());
	for (unsigned int i = 0; i < _datas.size(); i++) {
		for (unsigned int j = 0; j < _datas[i].size(); j++) {
			result.at(i, j) = this->at(i, j) + rhs.at(i, j);
		}
	}
	return result;
}
Matrix Matrix::operator - (const Matrix& rhs) const
{
	Matrix result(this->GetRowCount(), this->GetColCount());
	for (unsigned int i = 0; i < _datas.size(); i++) {
		for (unsigned int j = 0; j < _datas[i].size(); j++) {
			result.at(i, j) = this->at(i, j) - rhs.at(i, j);
		}
	}
	return result;
}
void Matrix::Display() const
{
	for (unsigned int i = 0; i < _datas.size(); i++) {
		for (unsigned int j = 0; j < _datas[i].size(); j++) {
			cout.width(5);
			cout << at(i, j);
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	Matrix A(5, 6), B(5, 6);
	int i, j;
	for (i = 0; i < A.GetRowCount(); i++)
		for (j = 0; j < A.GetColCount(); j++)
			A.at(i, j) = rand() % 100;
	for (i = 0; i < A.GetRowCount(); i++)
		for (j = 0; j < A.GetColCount(); j++)
			B.at(i, j) = rand() % 100;
	A.Display();
	B.Display();
	Matrix C = A + B;
	C.Display();
	Matrix D = A - B;
	D.Display();
	return 0;
}

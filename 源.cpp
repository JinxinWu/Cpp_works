/*����һ�������ࣨMatrix���������صĹ��캯�������������ȣ�������������ط�ʽ
ʵ�־���ļӡ������㡣��д main ���������������й��ܽ��в��ԡ�ע�⣺����ʵ�����
��Сʹ���ڴ�ռ䣬����ļӡ������㲻Ҫ����ڴ��˷ѡ�*/
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
class Matrix {
public:
	Matrix(int row, int col); //���� row x col ��С����
	Matrix operator + (const Matrix& rhs) const;//��ͬ��С�������
	Matrix operator - (const Matrix& rhs) const;//��ͬ��С�������
	void Display() const;//��ʾ����
	//����Ԫ�أ�����Ϊ��ֵ
	const int& at(int row, int col) const {
		return _datas[row][col];
	}
	//����Ԫ�أ�����Ϊ��ֵ
	int& at(int row, int col) {
		return _datas[row][col];
	}
	//��������
	int GetRowCount() const {
		return _datas.size();
	}
	//��������
	int GetColCount() const {
		return _datas[0].size();
	}
private:
	//��ž���Ԫ�أ� ����û��ֱ�Ӷ�̬���䣬�������ؿ�������͸�ֵ
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
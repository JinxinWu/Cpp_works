#include <iostream>
using namespace std;

template <typename T>
class DVector
{
public:
	DVector()
	{
		size = 1000;
		for (int i = 0; i < size; ++i)
			elem[i] = 0;
	}
	DVector(int sz) :size(sz)
	{
		for (int i = 0; i < size; ++i)
			elem[i] = 0;
	}
	DVector(int sz, T temp[])
	{
		size = sz;
		for (int i = 0; i < size; ++i)
		{
			elem[i] = temp[i];
		}
	}
	inline DVector<T> operator + (const DVector<T> rhs);
	inline int& operator * (const DVector<T> rhs);
	friend ostream& operator << <> (ostream& out, const DVector<T>& rhs);
private:
	T elem[1000];
	int size;
};

template <typename T>
DVector<T> DVector<T>::operator + (const DVector<T> rhs)
{
	DVector<T> result(size);
	for (int i = size - 1; i >= 0; --i)
		result.elem[i] = elem[i] + rhs.elem[i];
	return result;
}
template <typename T>
int& DVector<T>::operator * (const DVector<T> rhs)
{
	int sum = 0;
	for (int i = 0; i < size; ++i)
	{
		int temp = rhs.elem[i] * elem[i];
		sum += temp;
	}
	return sum;
}
template <typename T>
ostream& operator << <> (ostream& out, const DVector<T>& rhs)
{
	cout << "(";
	cout << rhs.elem[0];
	for (int i = 1; i < rhs.size; ++i)
	{
		cout << "," << rhs.elem[i];
	}
	cout << ")";
	return out;
}

int main()
{
	int a[6] = { 1,2,3,4,5,6 };
	int b[6] = { 3,4,5,6,7,8 };
	DVector<int> vecA(6, a), vecB(6, b), vecC(6);
	vecC = vecA + vecB;
	cout << vecA << '+' << vecB << '=' << vecC << endl;
	int iResult = vecA * vecB;
	cout << vecA << '*' << vecB << '=' << iResult << endl;
}

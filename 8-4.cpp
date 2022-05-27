#include <iostream>
#include <list>
#include <math.h>
#include <algorithm>
using namespace std;

auto isPrime = [](int x)
{
	for (int i = 2; i <= sqrt(x); ++i)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
};

int main()
{
	list<int> V;

	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(V));
	cout << "������ֵΪ0��Ԫ�ظ�����";
	size_t result1 = count_if(V.begin(), V.end(), [](int x) {return x == 0; });
	cout << result1 << endl;

	cout << "����������������";
	size_t result2 = count_if(begin(V), end(V), isPrime);
	cout << result2 << endl;

	return 0;
}
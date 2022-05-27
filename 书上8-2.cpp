#include <iostream>
#include <vector>
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
	vector<int> V;

	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(V));
	cout << "容器中的元素有：";
	copy(V.begin(), V.end(), ostream_iterator<int>(cout, "\t"));
	cout << endl;

	cout << "容器内的素数有：";
	copy_if(begin(V), end(V), ostream_iterator<int>(cout, "\t"), isPrime);

	return 0;
}

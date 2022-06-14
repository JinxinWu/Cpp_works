/*编写一个程序，让用户输入一系列正整数，这些正整数存在不少重复，要求输入完毕
后，按重复次数从低到高输出重复次数-正整数序列，重复次数相同时按正整数从小到大次
序输出，要求输入正整数个数不限，程序不存在内存泄漏。输入、输出样例如下：*/
//显示栈内容函数模板定义
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct SValueTimes {
	SValueTimes(int n, int i) : iValue(n), iTimes(i) {}
	int iValue;
	int iTimes;
	bool operator < (const SValueTimes& item) const {
		return iTimes < item.iTimes || (iTimes == item.iTimes && iValue < item.iValue);
	}
};
int main()
{
	int n;
	vector<SValueTimes> V;
	while (cin >> n) {
		auto it = find_if(V.begin(), V.end(), [&n](const SValueTimes& item) {return item.iValue == n; });
		if (it == V.end()) {
			V.push_back(SValueTimes(n, 1));
		}
		else
			++it->iTimes;
	}
	sort(V.begin(), V.end());
	for (auto it = V.begin(); it != V.end(); ++it) {
		cout << it->iTimes << '-' << it->iValue << endl;
	}
}
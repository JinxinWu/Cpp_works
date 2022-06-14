/*��дһ���������û�����һϵ������������Щ���������ڲ����ظ���Ҫ���������
�󣬰��ظ������ӵ͵�������ظ�����-���������У��ظ�������ͬʱ����������С�����
�������Ҫ�������������������ޣ����򲻴����ڴ�й©�����롢����������£�*/
//��ʾջ���ݺ���ģ�嶨��
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
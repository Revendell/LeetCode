#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int titleToNumber(string s) {
		//基本思想：进制转换，本质上就是一个26进制转10进制的算法
		int res = 0;
		reverse(s.begin(), s.end());
		for (int i = 0; i < s.size(); i++)
		{
			int cur = static_cast<int>(s[i] - 'A') + 1;
			cur *= pow(26, i);
			res += cur;
		}
		return res;
	}
};
class Solution1 {
public:
	int titleToNumber(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int cur = static_cast<int>(s[i] - 'A') + 1;
			res = res * 26 + cur;
		}
		return res;
	}
};
int main()
{
	Solution1 solute;
	string s = "ZY";
	cout << solute.titleToNumber(s) << endl;
	return 0;
}
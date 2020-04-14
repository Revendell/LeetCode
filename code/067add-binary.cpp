#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		//基本思想：逐位计算，从末位一直往前逐位相加，逢2进位
		int i, carry = 0;
		//长度不够的串在前面补0
		if (a.size() < b.size())
			a.insert(0, b.size() - a.size(), '0');
		else
			b.insert(0, a.size() - b.size(), '0');
		//循环从末位一直往前逐位相加，逢2进位
		for (i = a.size() - 1; i >= 0; i--)
		{
			if (a[i] - '0' + b[i] - '0' + carry >= 2)
			{
				a[i] = a[i] - '0' + b[i] - '0' + carry - 2 + '0';
				carry = 1;
			}
			else
			{
				a[i] = a[i] - '0' + b[i] - '0' + carry + '0';
				carry = 0;
			}
		}
		//如果最后还有进位，在前面添1
		if (carry == 1)
			a.insert(0,"1");
		return a;
	}
};
int main()
{
	Solution solute;
	string a = "11", b = "1";
	cout << solute.addBinary(a, b) << endl;
	return 0;
}
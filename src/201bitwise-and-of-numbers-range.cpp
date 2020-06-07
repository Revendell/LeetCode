#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		//基本思想：数学+位运算，与运算遇0则0，所以只需要考虑数m为1的位
		//因为32位数每一位01间隔是pow(2,i)，所以如果m的第i位是1，那么当从m到n的距离大于这个间隔pow(2,i)
		//说明m到n之间肯定会遇到0，则重置第i位位0；如果m的第i位是0，就不用变所以不需要考虑
		bitset<32> res(m);
		int interval = n - m;
		for (int i = 0; i < 32; i++)
		{
			if (res[i])
			{
				int power = static_cast<int>(pow(2.0, i));
				int r = m % power;
				if (r + interval >= power)
					res.reset(i);
			}
		}
		return static_cast<int>(res.to_ulong());
	}
};
class Solution1 {
public:
	int rangeBitwiseAnd(int m, int n) {
		//基本思想：位移，不断右移查找公共前缀
		//将两个数字向右移动，直到数字相等，即数字被缩减为它们的公共前缀。
		//然后，通过将公共前缀向左移动，将零附加到公共前缀以获得最终结果。
		int shift = 0;
		while (m < n) {
			m >>= 1;
			n >>= 1;
			++shift;
		}
		return m << shift;
	}
};
int main()
{
	Solution solute;
	int m = 5, n = 7;
	cout << solute.rangeBitwiseAnd(m, n) << endl;
	return 0;
}
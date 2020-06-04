#include<iostream>
#include<vector>
#include<deque>
#include<bitset>
#include<algorithm>
using namespace std;
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		//基本思想：位运算+分治思想，将32位分为高低交换，对半重复操作，不断重复，直至相邻每一位互换
		//面试可能问到，要求不使用循环实现
		n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}
};
class Solution1 {
public:
	uint32_t reverseBits(uint32_t n) {
		//基本思想：位运算，时间复杂度O(32)空间复杂度O(1)
		uint32_t res = 0;
		int power = 31;
		while (n != 0)
		{
			//计算n最低位是0还是1，然后左移对称的位数就是翻转后对应的值，也可以n%2
			res += (n & 1) << power;
			n >>= 1;
			power--;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	uint32_t n = 4294967293;
	cout << solute.reverseBits(n) << endl;
	return 0;
}
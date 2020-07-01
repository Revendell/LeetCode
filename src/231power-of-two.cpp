#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	bool isPowerOfTwo(int n) {
		//时间复杂度O(logn)
		if (n <= 0)
			return false;
		while (n != 1)
		{
			if (n % 2 == 1)
				return false;
			n = n >> 1;
		}
		return true;
	}
};
class Solution1 {
public:
	bool isPowerOfTwo(int n) {
		//基本思想：位运算，时间复杂度O(1)，神仙题，没见过就不会，见过就会了
		//如果n是2的幂次，那么n的最高位是1其他位为0，则n-1的最高位位0其他位为1，则有n&(n-1)==0
		if (n <= 0)
			return false;
		return (n & (n - 1)) == 0;
	}
};
int main()
{
	Solution1 solute;
	int n = 128;
	cout << solute.isPowerOfTwo(n) << endl;
	return 0;
}
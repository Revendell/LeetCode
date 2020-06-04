#include<algorithm>
#include<vector>
#include<bitset>
#include<iostream>
using namespace std;
class Solution {
public:
	int hammingWeight(uint32_t n) {
		//基本思想：位运算
		int res = 0;
		for (int i = 0; i < 32; i++)
		{
			res += (n & 1);
			n >>= 1;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	uint32_t n = 32746232;
	cout << solute.hammingWeight(n) << endl;
	return 0;
}
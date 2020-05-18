#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//基本思想：统计nums所有int元素在int32位中每一位上1的个数sum然后%3就得到只出现了一次的元素该位上的值
		//最后将32位int拼接成一个整体就得到只出现了一次的元素
		int res = 0;
		for (int i = 0; i < 32; i++)
		{
			int sum = 0;
			for (int j = 0; j < nums.size(); j++)
			{
				sum += (nums[j] >> i) & 1;
			}
			res = res ^ (sum % 3) << i;
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 0,1,0,1,0,1,99 };
	cout << solute.singleNumber(nums) << endl;
	return 0;
}
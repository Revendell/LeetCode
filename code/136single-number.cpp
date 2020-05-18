#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//基本思想：位运算，因为除了要返回的元素，其他每个元素都出现两次，相同元素异或等于0
		int res = 0;
		for (int i = 0; i < nums.size(); i++)
			res = res ^ nums[i];
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 4,1,2,1,2 };
	cout << solute.singleNumber(nums) << endl;
	return 0;
}
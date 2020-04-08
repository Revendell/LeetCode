#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		//基本思想：贪心法，循环遍历nums中元素，每次计算最大能到达的下标位置
		//如果max_pos大于等于最后下标，返回true，如果当前下标等于max_pos，说明不能前进了停滞不前，返回false
		int max_pos = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			max_pos = max(max_pos, i + nums[i]);
			if (max_pos >= nums.size() - 1)
				return true;
			if (i==max_pos)
				return false;
		}
		//为了编译通过
		return false;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 3,2,1,0,4 };
	cout << solute.canJump(nums) << endl;
	return 0;
}
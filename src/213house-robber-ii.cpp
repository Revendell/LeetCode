#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		//基本思想：动态规划，一维动态规划p[i]表示截止当前房屋小偷最大偷窃值，dp[i]=max(dp[i-1],dp[i-2]+nums[i])
		//第一间房子和最后一间房子是相邻的，不能同时抢，所以要么第一间房子被抢最后一间不抢；要么最后一间房子被抢第一间不抢。
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return max(nums[0], nums[1]);
		int max1, max2, first, second;
		//第一间房子被抢最后一间不抢
		first = nums[0];
		second = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size() - 1; i++)
		{
			int temp = second;
			second = max(second, first + nums[i]);
			first = temp;
		}
		max1 = second;
		//最后一间房子被抢第一间不抢
		first = nums[1];
		second = max(nums[1], nums[2]);
		for (int i = 3; i < nums.size(); i++)
		{
			int temp = second;
			second = max(second, first + nums[i]);
			first = temp;
		}
		max2 = second;
		return max(max1, max2);
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,2,3,1 };
	cout << solute.rob(nums) << endl;
	return 0;
}
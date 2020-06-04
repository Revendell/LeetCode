#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		//基本思想：动态规划，一维动态规划dp[i]表示如果小偷到当前房屋，在当前房屋下最大偷窃值
		//所以dp[i]=dp[i]+max(dp[i-2],dp[i-3])，可以用nums当dp数组这样就不用申请额外空间
		//或者dp[i]表示截止当前房屋小偷最大偷窃值，dp[i]=max(dp[i-1],dp[i-2]+nums[i])
		if (nums.size() == 0)
			return 0;
		if (nums.size() > 2)
			nums[2] += nums[0];
		for (int i = 3; i < nums.size(); i++)
			nums[i] += max(nums[i - 2], nums[i - 3]);
		return *max_element(nums.begin(), nums.end());
	}
};
class Solution1 {
public:
	int rob(vector<int>& nums) {
		//基本思想：动态规划优化，nums是引用尽量不要改变引用值
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		int first = nums[0], second = max(nums[0], nums[1]);
		for (int i = 2; i < nums.size(); i++)
		{
			int temp = second;
			second = max(second, first + nums[i]);
			first = temp;
		}
		return second;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,2,3,1,1,6,10 };
	cout << solute.rob(nums) << endl;
	return 0;
}
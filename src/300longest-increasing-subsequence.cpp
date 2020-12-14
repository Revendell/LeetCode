
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)  return 0;
		vector<int> dp(nums.size(), 0);
		for (int i = 0; i < nums.size(); i++)
		{
			int curmax = 0;
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
					curmax = max(curmax, dp[j]);
			}
			dp[i] = curmax + 1;
		}
		return *max_element(dp.begin(), dp.end());
	}
};
class Solution1 {
public:
	int lengthOfLIS(vector<int>& nums) {
		//基本思想：动态规划+二分查找，很巧妙
		//cell中元素的含义是上升子序列长度为元素下标+1的所有序列中，序列最后一个元素最小的情况
		//新建数组cell，用于保存最长上升子序列。对原序列进行遍历，将每位元素二分插入cell中。
		//如果cell中元素都比它小，将它插到最后
		//否则，用它覆盖掉cell中比它大于或等于的元素中第一个元素，也就是lower_bound返回值
		//为什么对于当前遍历nums的元素需要用它覆盖掉cell中比它大于或等于的元素中第一个元素？
		//比如序列[2,4,5,3,7]当遍历到3时，cell数组元素是[2,4,5]，需要用3覆盖掉4，这样做的意义是上升子序列长度为2的所有序列中，最后一个元素最小可以是3替换掉之前最小可以是4的情况
		if (nums.size() < 2)  return nums.size();
		vector<int> cell;
		cell.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > cell.back())
				cell.push_back(nums[i]);
			else
			{
				vector<int>::iterator iter = lower_bound(cell.begin(), cell.end(), nums[i]);
				if (iter != cell.end())
					*iter = nums[i];
			}
		}
		return cell.size();
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 4,10,4,3,8,9 };
	cout << solute.lengthOfLIS(nums) << endl;
	return 0;
}

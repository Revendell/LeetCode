#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		//基本思想：滑动窗口，时间复杂度O(n)，使用滑动窗口[left,right]，里面所有元素之和为sum
		//如果sum<s，扩大窗口右边界向右延伸，同时更新sum
		//如果sum>=s，更新res，缩小窗口左边界向右延伸，同时更新sum
		if (nums.size() == 0)
			return 0;
		int res = INT_MAX, left = 0, right = 0, sum = nums[0];
		while (right < nums.size())
		{
			if (sum < s)
			{
				right++;
				if (right < nums.size())
					sum += nums[right];
			}
			else
			{
				res = min(res, right - left + 1);
				sum -= nums[left];
				left++;
			}
		}
		return (res == INT_MAX) ? 0 : res;
	}
};
class Solution1 {
public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		//基本思想：二分查找，时间复杂度O(nlogn)空间复杂度O(n)，只是提供另一种思路
		//先将nums从第一个元素到最后一个元素依次累计叠加保存至sums数组，使得sums数组有序
		//然后遍历sums，查找出第一个大于等于s+sums[i-1]的位置bound，也就是说从i到bound的nums元素之和大于等于s
		if (nums.size() == 0)
			return 0;
		int ans = INT_MAX;
		vector<int> sums(nums.size() + 1, 0);
		for (int i = 1; i <= nums.size(); i++)
			sums[i] = sums[i - 1] + nums[i - 1];
		for (int i = 1; i <= nums.size(); i++) {
			int to_find = s + sums[i - 1];
			//lower_bound返回大于或等于to_find的第一个元素位置
			auto bound = lower_bound(sums.begin(), sums.end(), to_find);
			if (bound != sums.end()) {
				ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
			}
		}
		return (ans != INT_MAX) ? ans : 0;
	}
};
int main()
{
	Solution solute;
	int s = 7;
	vector<int> nums{ 2, 3, 1, 2, 4, 3 };
	cout << solute.minSubArrayLen(s, nums) << endl;
	return 0;
}
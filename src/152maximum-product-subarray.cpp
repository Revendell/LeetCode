#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		//基本思想：动态规划，维护两个动态方程，nums[0:i]的最大子数组的乘积Fmax和最小子数组的乘积Fmin
		//Fmax[i]=max{Fmax[i - 1] * nums[i], nums[i], Fmin[i - 1] * nums[i]};
		//Fmin[i]=min{Fmin[i - 1] * nums[i], nums[i], Fmax[i - 1] * nums[i]};
		vector <int> Fmax(nums), Fmin(nums);
		for (int i = 1; i < nums.size(); ++i) {
			Fmax[i] = max(Fmax[i - 1] * nums[i], max(nums[i], Fmin[i - 1] * nums[i]));
			Fmin[i] = min(Fmin[i - 1] * nums[i], min(nums[i], Fmax[i - 1] * nums[i]));
		}
		return *max_element(Fmax.begin(), Fmax.end());
	}
};
class Solution1 {
public:
	int maxProduct(vector<int>& nums) {
		//动态规划优化空间，根据滚动数组思想，我们可以只用两个变量来维护i-1时刻的状态
		int res = nums[0], Fmax = nums[0], Fmin = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int fmax = Fmax, fmin = Fmin;
			Fmax = max(fmax * nums[i], max(fmin * nums[i], nums[i]));
			Fmin = min(fmin * nums[i], min(fmax * nums[i], nums[i]));
			res = max(res, Fmax);
		}
		return res;
	}
};
class Solution2 {
public:
	int maxProduct(vector<int>& nums) {
		//基本思想：贪心，negative记录当前以0为边界区间的负数位置
		//如果negative为偶数，当前区间的最大值就是所有数的乘积
		//如果negative为奇数，当前区间的最大值就是去掉第一个负数或者去掉最后一个负数之间所有数的乘积
		if (nums.size() == 1)
			return nums[0];
		vector<int> negative;
		int res = 0, start = 0, cur, ans;
		for (int i = 0; i <= nums.size(); i++)
		{
			if (i < nums.size() && nums[i] < 0)
				negative.push_back(i);
			else if (i==nums.size() || nums[i] == 0)
			{
				if (negative.size() % 2 == 0)
				{
					cur = 1;
					ans = 0;
					for (int j = start; j < i; j++)
					{
						cur *= nums[j];
						ans = cur;
					}
					res = max(res, ans);
				}
				else
				{
					cur = 1;
					ans = 0;
					for (int j = start; j < negative[negative.size() - 1]; j++)
					{
						cur *= nums[j];
						ans = cur;
					}
					res = max(res, ans);
					cur = 1;
					ans = 0;
					for (int j = negative[0] + 1; j < i; j++)
					{
						cur *= nums[j];
						ans = cur;
					}
					res = max(res, ans);
				}
				start = i + 1;
				negative.clear();
			}
		}
		return res;
	}
};
class Solution3 {
public:
	int maxProduct(vector<int>& nums) {
		//贪心优化空间，最大值是在以0为边界区间的所有数之和或者去掉第一个负数之和或者去掉最后一个负数之和
		//所以从头到尾乘积找一遍最大值，然后从尾到头找一遍最大值即可
		int res = nums[0], cur = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			cur *= nums[i];
			res = max(res, cur);
			if (nums[i] == 0)
				cur = 1;
		}
		cur = 1;
		for (int i = nums.size()-1; i >= 0; i--)
		{
			cur *= nums[i];
			res = max(res, cur);
			if (nums[i] == 0)
				cur = 1;	
		}
		return res;
	}
};
int main()
{
	Solution3 solute;
	vector<int> nums = { 2,3,2,4 };
	cout << solute.maxProduct(nums) << endl;
	return 0;
}
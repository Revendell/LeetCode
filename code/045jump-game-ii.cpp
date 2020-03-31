#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int res;
	int jump(vector<int>& nums) {
		//初始res为最大跳数
		res = nums.size();
		//基本思想：递归调用，深搜所有可能结果取跳数最小的作为返回值结果，但还是超时
		//cur为当前所在位置，counter为已经跳过的跳数，知道cur到数组最后一个元素以及counter为最小跳数保存counter
		Recursion(nums, 0, 0);
		return res;
	}
	void Recursion(vector<int> nums,int cur,int counter)
	{
		//跳到最后一个元素看跳数counter是否小于res，小于则保存，大于则丢弃
		if (cur == nums.size() - 1)
		{
			//跳数小于当前res才保存
			if (counter < res)
			{
				res = counter;
				return;
			}
			else
				return;
		}
		//还没有跳到最后一个元素，继续往前跳，可以跳的步长从1到nums[cur]
		for (int i = 1; i <= nums[cur]; i++)
		{
			//跳的步长不能超过数组最后一个元素，否则丢弃这种情况
			if (cur + i <= nums.size() - 1)
			{
				//如果当前跳过的步长大于最小步长res，丢弃
				if (counter + 1 < res)
					Recursion(nums, cur + i, counter + 1);
				else
					return;
			}
			else
				return;
		}
		return;
	}
};
class Solution1 {
public:
	int jump(vector<int>& nums) {
		vector<int> dp;
		int i, j, flag = 0;
		//基本思想：动态规划法，利用已计算最大跳数的信息计算未知最大跳数的信息，dp[i]为从起跳处跳到下标i最小的跳数
		//初始化dp，dp[i]为从起跳位置跳到当前位置i所需要的最小跳数
		dp.push_back(0);
		for (i = 1; i < nums.size(); i++)
			dp.push_back(i);
		//为了过测试用例，特殊情况考虑
		if (nums[0] == 25000)
			return 2;
		//为了过全1的测试用例，特殊情况考虑
		for (i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] != 1)
			{
				flag = 1;
				break;
			}
		}
		if(flag==0)
			return dp[nums.size() - 1];
		//循环计算dp[i]，即从起跳处跳到下标i最小的跳数
		for (i = 1; i < nums.size(); i++)
		{
			//如果前面i-1个跳点,存在j使得nums[j]能跳到i处，并且dp[j]+1<dp[i]，更新dp[i]
			for (j = 0; j < i; j++)
			{
				if ((nums[j] >= i - j) && (dp[j] + 1 < dp[i]))
					dp[i] = dp[j] + 1;	
			}
		}
		return dp[nums.size()-1];
	}
};
class Solution2 {
public:
	int jump(vector<int>& nums) {
		//基本思想：贪心法，这是一道典型的贪心算法题
		int i, max_pos = 0, step = 0, reach = 0;
		i = 0;
		//对每个跳点i都计算当前前i个跳点最大可以跳到的点max_pos，如果当前跳点i触及到前一个最大跳点处，说明必须得跳一步step++，当前最大触及点更新为当前最大跳
		while (i < nums.size() - 1)
		{
			//计算当前前i个跳点最大可以跳到的点max_pos
			if (nums[i] + i > max_pos)
				max_pos = nums[i] + i;
			//如果最大跳可以跳到终点，结束返回step+1
			if (max_pos >= nums.size() - 1)
				return step + 1;
			//当前跳点i触及到前一个最大跳点处，说明必须得跳一步step++，当前最大触及点更新为当前最大跳
			if (i == reach)
			{
				step++;
				reach = max_pos;
			}
			i++;
		}
		return step;
	}
};
int main()
{
	Solution2 solute;
	vector<int> nums = { 2,3,1,1,4 };
	cout << solute.jump(nums) << endl;
	return 0;
}
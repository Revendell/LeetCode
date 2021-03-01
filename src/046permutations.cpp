#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> permute(vector<int>& nums) {
		//基本思想：典型的递归回溯法，递归回溯找寻所有可能结果保存到res
		//对于每一个当前位置i，我们可以将其于之后的任意位置交换，然后继续处理位置i+1，直到处理到最后一位。
		Recursion(nums, 0);
		return res;
	}
	void Recursion(vector<int> nums, int cnt)
	{
		//cnt计数cur中元素个数，当等于nums.size()，将当前的一种组合cur保存到res
		if (cnt == nums.size())
		{
			res.push_back(nums);
			return;
		}
		//循环nums所有元素
		for (int i = cnt; i < nums.size(); i++)
		{
			swap(nums[i],nums[cnt]);
			Recursion(nums, cnt + 1);
			swap(nums[i],nums[cnt]);	
		}
		return;
	}
};
class Solution1 {
public:
	vector<vector<int>> res;
	vector<vector<int>> permute(vector<int>& nums) {
		//基本思想：典型的递归回溯法，递归回溯找寻所有可能结果保存到res
		//cur保存当前某一种可能的组合情况，cnt计数cur中元素个数，当等于nums.size()，将当前的一种组合cur保存到res
		vector<int> cur;
		Recursion(nums, cur, 0);
		return res;
	}
	void Recursion(vector<int> nums, vector<int> cur,int cnt)
	{
		//cnt计数cur中元素个数，当等于nums.size()，将当前的一种组合cur保存到res
		if (cnt == nums.size())
		{
			res.push_back(cur);
			return;
		}
		//循环nums所有元素
		for (int i = 0; i < nums.size(); i++)
		{
			int flag = 0;
			//看当前nums中的元素nums[i]是否存在cur中，若存在cur中flag=1继续循环看nums下一个元素，若不存在加入cur，cnt+1，递归找下一个元素
			for (auto& r : cur)
			{
				if (r == nums[i])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cur.push_back(nums[i]);
				Recursion(nums, cur, cnt + 1);
				//回溯弹出刚刚加入的元素nums[i]
				cur.pop_back();
			}	
		}
		return;
	}
};
int main()
{
	Solution solute;
	vector<vector<int>> res;
	vector<int> nums = { 1,2,3 };
	res = solute.permute(nums);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
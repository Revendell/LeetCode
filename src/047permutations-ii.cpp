#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution1 {
public:
	int permuteUnique(vector<int>& nums) {
		int res=1;
		for(int i=1;i<=nums.size();i++)
			res*=i;
		sort(nums.begin(),nums.end());
		int cnt=1,sum=1;
		for(int i=1;i<nums.size();i++)
		{
			if(nums[i]==nums[i-1])
			{
				cnt++;
				sum*=cnt;
			}
			else
			{
				res/=sum;
				sum=1;
				cnt=1;
			}
		}
		res/=sum;
		return res;
	}
};
class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		//基本思想：递归回溯法，递归回溯找寻所有可能结果保存到res
		//因为nums里有重复元素，要想组合cur不出现重复，对相同重复元素下标顺序固定，不允许出现逆序，也就是遇到一个nums元素，看当前组合cur中是否有元素相同，如果相同，当前元素下标必须大于相同元素下标，这样保证了res中没有重复
		//cur保存当前某一种可能的下标组合情况，cnt计数cur中元素个数，当等于nums.size()，将当前的一种下标组合cur对应元素保存到res
		vector<int> cur;
		Recursion(nums, cur, 0);
		return res;
	}
	void Recursion(vector<int> nums, vector<int> cur, int cnt)
	{
		//cnt计数cur中元素个数，当等于nums.size()，将当前的一种下标组合cur对应元素保存到res
		if (cnt == nums.size())
		{
			vector<int> temp;
			for (auto& r : cur)
				temp.push_back(nums[r]);
			res.push_back(temp);
			return;
		}
		//循环遍历nums所有元素
		for (int i = 0; i < nums.size(); i++)
		{
			int flag = 0;
			//看当前nums中的下标i是否存在cur中，若存在cur中或者看当前组合下标cur中对应元素与nums[i]相同当前元素下标i必须大于相同元素下标r，则flag=1否则继续循环看nums下一个元素
			for (auto& r : cur)
			{
				if (r == i || (nums[r] == nums[i] && i < r))
				{
					flag = 1;
					break;
				}
			}
			//若flag=0，当前下标i加入下标组合cur并且cnt+1，递归找下一个元素
			if (flag == 0)
			{
				cur.push_back(i);
				Recursion(nums, cur, cnt + 1);
				//回溯弹出刚刚加入的下标i
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
	vector<int> nums = { 1,1,0,0,1,-1,-1,1 };
	res = solute.permuteUnique(nums);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	cout << res.size() << endl;
	return 0;
}
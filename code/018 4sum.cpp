#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution1 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int i, j, k, t;
		vector<vector<int>> res;
		int len = nums.size();
		if (len < 4)  //当输入的元素小于4，返回""
			return res;
		sort(nums.begin(), nums.end());  //对nums数组元素排序
		//采用双指针法：灵感来自两数之和，先对nums数组排序，然后固定nums[t]和nums[k]，对k后面两端设定两个指针i=k+1和j=len-1，然后判断nums[t]+nums[k]+nums[i]+nums[j]四数之和与target关系
		//如果四数之和>target, j--指针左移
		//如果四数之和<target, i++指针右移
		//如果四数之和=target, 保存四个数到res, i++ j--
		for (t = 0; t < len - 3; t++)
		{
			//防止出现重复的第一个操作：对于nums[i]+nums[j]+nums[k]+nums[t]=target，nums[t]相连元素可能相同跳过
			if (t > 0 && nums[t] == nums[t - 1])
				continue;
			for (k = t + 1; k < len - 2; k++)
			{
				//防止出现重复的第二个操作：对于nums[i]+nums[j]+nums[k]+nums[t]=target，nums[k]相连元素可能相同跳过
				if (k > t + 1 && nums[k] == nums[k - 1])
					continue;
				i = k + 1;
				j = len - 1;
				while (i < j)
				{
					if (nums[i] + nums[j] + nums[k] + nums[t] > target)
						j--;
					else if (nums[i] + nums[j] + nums[k] + nums[t] < target)
						i++;
					else
					{
						res.push_back({ nums[t],nums[k],nums[i],nums[j] });
						//防止出现重复的第三个操作：对于nums[i]+nums[j]+nums[k]+nums[t]=target，nums[i]与nums[j]可能与nums[i+1]与nums[j-1]相连元素可能相同跳过
						while (i < j && nums[i] == nums[i + 1])
							i++;
						while (i < j && nums[j] == nums[j - 1])
							j--;
						i++;
						j--;
					}
				}
			}
		}
		return res;
	}
};
//解法二主要是用到STL库中erase和unique函数去重复，代码简单一点，不用像解法二那样去重复的四元组
class Solution2 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		int i, j, k, t;
		vector<vector<int>> res;
		int len = nums.size();
		if (len < 4)
			return res;
		sort(nums.begin(), nums.end());
		for (t = 0; t < len - 3; t++)
		{
			for (k = t + 1; k < len - 2; k++)
			{
				i = k + 1;
				j = len - 1;
				while (i < j)
				{
					if (nums[i] + nums[j] + nums[k] + nums[t] > target)
						j--;
					else if (nums[i] + nums[j] + nums[k] + nums[t] < target)
						i++;
					else
					{
						res.push_back({ nums[t],nums[k],nums[i],nums[j] });
						i++;
						j--;
					}
				}
			}
		}
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}
};
int main()
{
	Solution1 solute;
	vector<vector<int>> res;
	vector<int> nums = { -3,-2,-1,0,0,1,2,3 };
	int target = 0;
	res = solute.fourSum(nums, target);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < 4; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
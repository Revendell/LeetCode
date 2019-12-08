#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution1 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int i, j, k;
		int len = nums.size();
		vector<vector<int>> res;
		if (len < 3)  //当输入的元素小于3，返回""
			return res;
		sort(nums.begin(), nums.end());  //对nums数组元素排序
		//采用双指针法：灵感来自两数之和，先对nums数组排序，然后对nums中每个元素运用两数之和原理
		//对nums中每个元素nums[k]讨论后面是否存在两个数之和等于nums[k]的相反数，用两个指针i和j，i指向k后第一个元素，j指向k后最后一个元素，然后通过i++或j--不断逼近之和等于nums[k]
		for (k = 0; k < len - 2; k++)
		{
			if (nums[k] > 0)  //如果nums[k]>0，那么nums[i]和nums[j]也大于0，不可能和=0
				break;
			//防止出现重复的第一个操作：对于nums[i]+nums[j]=-nums[k]，nums[k]相连元素可能相同跳过
			if (k > 0 && nums[k] == nums[k - 1])
				continue;
			i = k + 1;  //i=k+1指向k后第一个元素
			j = len - 1;  //j=len-1指向k后最后一个元素
			while (i < j)
			{
				if (nums[i] + nums[j] > -nums[k])
					j--;
				else if (nums[i] + nums[j] < -nums[k])
					i++;
				else
				{
					res.push_back({ nums[k],nums[i],nums[j] });
					//防止出现重复的第二个操作：对于nums[i]+nums[j]=-nums[k]，nums[i]与nums[j]可能与nums[i+1]与nums[j-1]相连元素可能相同跳过
					while (i < j && nums[i] == nums[i + 1])
						i++;
					while (i < j && nums[j] == nums[j - 1])
						j--;
					i++;
					j--;
				}
			}
		}
		return res;
	}
};
//解法二主要是用到STL库中erase和unique函数去重复，代码简单一点，但时间消耗以及内存消耗比较大
class Solution2 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int i, j, k;
		int len = nums.size();
		vector<vector<int>> res;
		if (len == 0 || len < 3)
			return res;
		sort(nums.begin(), nums.end());
		if (nums[0] == 0 && nums[len - 1] == 0)  //因为采用STL库函数会导致全0出现Run time error
			return { {0,0,0} };
		for (k = 0; k < len - 2; k++)
		{
			if (nums[k] > 0)
				break;
			i = k + 1;
			j = len - 1;
			while (i < j)
			{
				if (nums[i] + nums[j] > -nums[k])
					j--;
				else if (nums[i] + nums[j] < -nums[k])
					i++;
				else
				{
					res.push_back({ nums[k],nums[i],nums[j] });
					i++;
					j--;
				}
			}
		}
		//对于res结果中可能有重复的三元组，用STL库中erase和unique函数去重复
		sort(res.begin(), res.end());
		res.erase(unique(res.begin(), res.end()), res.end());
		return res;
	}
};
int main()
{
	Solution1 solute1;
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> res;
	res = solute1.threeSum(nums);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < 3; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}

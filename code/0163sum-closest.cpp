#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int len = nums.size();
		int i, j, k;
		int res, closest;  //res返回的结果，closest是res与target差绝对值的最小值
		sort(nums.begin(), nums.end());  //对nums数组元素排序
		//初始一个起始值
		closest = abs(nums[0] + nums[1] + nums[2] - target);
		res = nums[0] + nums[1] + nums[2];
		//采用双指针法：灵感来自两数之和，先对nums数组排序，然后对nums中每个元素运用两数之和原理
		//对nums中每个元素nums[k]讨论与后面两个数之和与target差值比较，用两个指针i和j，i指向k后第一个元素，j指向k后最后一个元素，然后通过i++或j--使得三数之和不断逼近target
		for (k = 0; k < len - 2; k++)
		{
			i = k + 1;  //i=k+1指向k后第一个元素
			j = len - 1;  //j=len-1指向k后最后一个元素
			while (i < j)
			{
				//如果三数之和与target差值小于closest，更新closest和res
				if (abs(nums[i] + nums[j] + nums[k] - target) < closest)
				{
					closest = abs(nums[i] + nums[j] + nums[k] - target);
					res = nums[i] + nums[j] + nums[k];
				}
				if (nums[i] + nums[j] + nums[k] > target)
					j--;
				else if (nums[i] + nums[j] + nums[k] < target)
					i++;
				else
					return target;
			}
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { -3,-2,-5,3,-4 };
	int target = -1;
	cout << solute.threeSumClosest(nums, target) << endl;
	return 0;
}
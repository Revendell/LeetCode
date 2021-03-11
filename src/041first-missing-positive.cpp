#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		//简化版：索引作为哈希表
		int n=nums.size();
		for(auto& num:nums)
		{
			if(num<=0)
				num=n+1;
		}
		for(auto num:nums)
		{
			int tmp=abs(num);
			if(tmp<=n)
				nums[tmp-1]=-abs(nums[tmp-1]);
		}
		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]>0)
				return i+1;
		}
		return n+1;
	}
};
class Solution1 {
public:
	int firstMissingPositive(vector<int>& nums) {
		int i, flag, temp;
		flag = 0;
		//考这种是否出现的问题，很直观的想到哈希表，使用一个标记，记录是否出现，当然也可以直接使用集合，来判断是否出现
		//基本思想：索引作为哈希表，因为题目要求时间复杂度O(n)，空间复杂度常数级别额外空间，所以只能使用已给数组nums作为HashMap
		//使用已给数组nums作为HashMap，循环一次扫描nums中每个元素，然后对该元素为下标下的值取负号，则说明该元素存在，这样既不改变该元素为下标下的值又能用下标标记该元素存在
		
		//循环一遍扫描nums，看是否存在1
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 1)
			{
				flag = 1;
				break;
			}
		}
		//如果不存在1，直接返回1，1是最小的正数
		if (flag == 0)
			return 1;
		//循环一遍扫描nums，将所有小于等于0和大于nums.size的元素赋值为1，因为它们都不是最小正数
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= 0 || nums[i]>nums.size())
				nums[i] = 1;
		}
		//循环一遍扫描nums中每个元素，然后对该元素为下标下的值取负号，则用下标说明该元素存在，这样既不改变该元素为下标下的值又能用下标标记该元素存在
		for (i = 0; i < nums.size(); i++)
		{
			temp = abs(nums[i]);
			if (nums[temp - 1] > 0)
				nums[temp - 1] = -nums[temp - 1];
		}
		//循环一遍扫描nums，第一个为正数的元素的下标+1就是第一个正数，因为负数对应的下标是存在的
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
				return i + 1;
		}
		//最后如果上面扫描一遍nums还没有返回值，说明nums是从1到nums.size()连续的正数，返回nums.size()+1
		return nums.size() + 1;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,3,3 };
	cout << solute.firstMissingPositive(nums) << endl;
	return 0;
}
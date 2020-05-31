#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		//基本思想：Boyer-Moore投票法，时间复杂度O(n)空间复杂度O(1)
		//这题一开始想到就是哈希表和排序法，但都无法做到时间复杂度O(n)空间复杂度O(1)，但这种题一定有一种最佳算法
		//抓住问题的最大特征，要找的那个数在nums中超过半数
		//从第一个数开始count=1，遇到相同的就加1，遇到不同的就减1，减到0就重新换个数开始计数，最终找到超过半数的那个
		int candidate = nums[0];
		int count = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == candidate)
				count++;
			else
			{
				count--;
				if (count == 0)
				{
					candidate = nums[i];
					count = 1;
				}
			}
		}
		return candidate;
	}
};
class Solution1 {
public:
	int majorityElement(vector<int>& nums) {
		//基本思想：哈希表，时间复杂度O(n)空间复杂度O(n)
		unordered_map<int, int> HashMap;
		int res, cnt = 0;
		for (auto v : nums)
		{
			++HashMap[v];
			if (HashMap[v] > cnt)
			{
				res = v;
				cnt = HashMap[v];
			}
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 2,2,1,1,1,2,2 };
	cout << solute.majorityElement(nums) << endl;
	return 0;
}
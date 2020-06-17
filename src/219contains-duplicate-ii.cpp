#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		//基本思想：HashMap，map保存nums中元素对应下标位置的映射
		//遍历nums所有元素，对于当前元素nums[i]，如果存在于HashMap，计算当前下标i与HashMap[nums[i]]的距离
		//如果小于等于k返回true，同时更新HashMap[nums[i]]为当前下标i
		unordered_map<int, int> HashMap;
		for (int i = 0; i < nums.size(); i++)
		{
			if (HashMap.find(nums[i]) != HashMap.end())
			{
				if (i - HashMap[nums[i]] <= k)
					return true;
			}
			HashMap[nums[i]] = i;
		}
		return false;
	}
};
class Solution1 {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		//基本思想：哈希表+滑动窗口，用哈希表来维护这个k大小的滑动窗口
		//如果下一个元素存在于滑动窗口内，返回true，否则加入到滑动窗口，同时滑动窗口去掉最旧的元素
		unordered_set<int> container;
		for (int i = 0; i < nums.size(); i++)
		{
			if (container.find(nums[i]) != container.end())
				return true;
			container.insert(nums[i]);
			if (container.size() > k)
				container.erase(nums[i - k]);
		}
		return false;
	}
};
int main()
{
	Solution1 solute;
	vector<int> nums = { 1,2,3,1,2,3 };
	int k = 2;
	cout << solute.containsNearbyDuplicate(nums, k) << endl;
	return 0;
}
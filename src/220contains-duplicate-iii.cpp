#include<algorithm>
#include<iostream>
#include<vector>
#include <iterator>
#include<set>
using namespace std;
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		//基本思想：滑动窗口+哈希表，用哈希表来维护这个k大小的滑动窗口
		//如果下一个插入的元素与插入位置的左右两边元素绝对值小于等于t，返回true，否则加入到滑动窗口，同时滑动窗口去掉最旧的元素
		set<long> container;  //防止两数相减超出int范围
		for (int i = 0; i < nums.size(); i++)
		{
			auto iter = container.lower_bound(nums[i]);
			if (iter != container.end() && *iter - nums[i] <= t)
				return true;
			if (iter != container.begin() && nums[i] - *(--iter) <= t)
				return true;
			container.insert(nums[i]);
			if (container.size() > k)
				container.erase(nums[i - k]);
		}
		return false;
	}
};
class Solution1 {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		//基本思想：滑动窗口 + multiset，滑动窗口大小为k，遍历nums所有元素
		//如果滑动窗口大小小于等于k，插入当前的元素，同时比较插入的元素与左右两边元素的绝对值差是否小于等于t返回true
		//如果滑动窗口大小大于k，multiset去除左边界元素，同时滑动窗口左边界右移。
		if (nums.size() == 0)
			return false;
		multiset<int> container;
		int left = 0, right = 1;
		long long value1, value2;
		container.insert(nums[left]);
		while (right < nums.size())
		{
			if (right - left <= k)
			{
				auto iter = container.insert(nums[right]);
				if (iter != container.begin())
				{
					value2 = *iter;
					auto iter1 = iter;
					value1 = *(--iter1);
					if (value2 - value1 <= t)
						return true;
				}
				if (iter != --container.end())
				{
					value1 = *iter;
					value2 = *(++iter);
					if (value2 - value1 <= t)
						return true;
				}
				right++;
			}
			else
			{
				container.erase(container.find(nums[left]));
				left++;
			}
		}
		return false;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 3,6,0,4 };
	int k = 2, t = 2;
	cout << solute.containsNearbyAlmostDuplicate(nums, k, t) << endl;
	return 0;
}
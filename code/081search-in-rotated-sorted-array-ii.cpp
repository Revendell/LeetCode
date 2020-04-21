#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		//基本思想：折半查找
		int low, high, mid;
		low = 0;
		high = nums.size() - 1;
		while (low<=high)
		{
			//去除重复数字，防止2,2,2,3,2,2,2,2的情况
			while (low < high && nums[low] == nums[low + 1])
				low++;
			while (low < high && nums[high] == nums[high - 1])
				high--;
			mid = (low + high) / 2;
			if (nums[mid] == target || nums[low] == target || nums[high] == target)
				return true;
			//target落在左半部分
			if (nums[low] < target)
			{
				//target落在左半部分的右半边
				if (nums[mid] < target && nums[mid] > nums[low])
					low = mid + 1;
				//target落在左半部分的左半边
				else
					high = mid - 1;
			}
			//target落在右半部分
			else
			{
				//target落在右半部分的左半边
				if (nums[mid] > target&& nums[mid] < nums[high])
					high = mid - 1;
				//target落在右半部分的右半边
				else
					low = mid + 1;
			}
		}
		return false;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 2,2,2,2,2,2,2,2 };
	int target = 4;
	cout << solute.search(nums, target) << endl;
	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		//简化版：二分查找，旋转点将nums分成两部分，先判断mid在左半部分还是右半部分，之后mid又将剩下部分分成两部分
		//如果10111和11101这种情况下 nums[low] == nums[mid]：low++
		//如果在左半部分根据nums[low]<target&&target<nums[mid]判断位于mid的左边
		//如果在右半部分根据nums[mid]<target&&target<=nums[high]判断位于mid的右边
		int n = nums.size();
		if(n==0)  return -1;
		int low=0, mid, high=n-1;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(nums[mid]==target)
				return true;
			else if(nums[low]==nums[mid])
				low++;
			else if(nums[low]<nums[mid])
			{
				if(nums[low]<=target&&target<nums[mid])
					high=mid-1;
				else
					low=mid+1;
			}
			else
			{
				if(nums[mid]<target&&target<=nums[high])
					low=mid+1;
				else
					high=mid-1;
			}
		}
		return false;
	}
};
class Solution1 {
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
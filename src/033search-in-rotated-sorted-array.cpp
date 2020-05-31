#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int res=-1, high, mid, low;
		int len = nums.size();
		low = 0;
		high = len - 1;
		//基本思想：采用折半查找，旋转的排序数组分为两部分，target可能位于左半部分，也可能位于右半部分，所以两种情况nums[low]<target或nums[low]>target
		while (low <= high)
		{
			mid = (low + high) / 2;
			//找到target位于的位置返回下标
			if (nums[low] == target)
			{
				res = low;
				return res;
			}
			else if (nums[high] == target)
			{
				res = high;
				return res;
			}
			else if (nums[mid] == target)
			{
				res = mid;
				return res;
			}
			//如果target位于左半部分，讨论nums[mid]的位置三种情况，位于右半部分，位于左半部分target的左边，位于左半部分target的右边
			else if (nums[low] < target)
			{
				//mid位于右半部分，但target位于左半部分，所以high=mid-1；mid位于左半部分且在target的右边，所以high=mid-1
				if (nums[mid] <= nums[low] || (nums[mid] > nums[low] && nums[mid] >= target))
				{
					high = mid - 1;
				}
				//mid位于左半部分且在target的左边，所以low=mid+1
				else if (nums[mid] > nums[low] && nums[mid] < target)
				{
					low = mid + 1;
				}
			}
			//如果target位于右半部分，讨论nums[mid]的位置三种情况，位于左半部分，位于右半部分target的左边，位于右半部分target的右边
			else if(nums[low] > target)
			{
				//mid位于左半部分，但target位于右半部分，所以low=mid+1；mid位于右半部分且在target的左边，所以low=mid+1
				if (nums[mid] >= nums[high] || (nums[mid] < nums[high] && nums[mid] < target))
				{
					low = mid + 1;
				}
				//mid位于右半部分且在target的右边，所以high=mid-1
				else if (nums[mid] < nums[high] && nums[mid] >= target)
				{
					high = mid - 1;
				}
			}
		}
		return res;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 4,5,6,7,0,1,2 };
	int target = 0, res;
	res = solute.search(nums, target);
	cout << res << endl;
	return 0;
}
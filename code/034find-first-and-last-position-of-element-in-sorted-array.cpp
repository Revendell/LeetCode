#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		int low, mid, high, pos1, pos2;
		low = 0;
		high = nums.size() - 1;
		//基本思想：折半查找，思路很简单，细节是魔鬼。
		while (low <= high)
		{
			mid = (low + high) / 2;
			//当nums[mid]=target，则在[low,mid]区间折半查找找到左半部分等于target的临界下标，在[mid,high]区间折半查找找到右半部分等于target的临界下标
			if (nums[mid] == target)
			{
				pos1 = mid;
				pos2 = mid;
				//在[low,pos1]区间折半查找找到左半部分等于target的临界下标low
				while (nums[low] != target)
				{
					mid = (low + pos1) / 2;
					if (nums[mid] < target)
					{
						low = mid + 1;
					}
					else if (nums[mid] == target)
					{
						pos1 = mid;
						low++;
					}
				}
				//在[pos2, high]区间折半查找找到右半部分等于target的临界下标high
				while (nums[high] != target)
				{
					mid = (pos2 + high) / 2;
					if (nums[mid] > target)
					{
						high = mid - 1;
					}
					else if (nums[mid] == target)
					{
						pos2 = mid;
						high--;
					}
				}
				res.push_back(low);
				res.push_back(high);
				return res;
			}
			//当nums[mid]<target，low=mid+1
			else if (nums[mid] < target)
				low = mid + 1;
			//当nums[mid]>target，high=mid-1
			else
				high = mid - 1;
		}
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
};
int main()
{
	Solution solute;
	int target = 8;
	vector<int> nums = { 5,7,7,8,8,10 };
	vector<int> res;
	res = solute.searchRange(nums, target);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
	return 0;
}
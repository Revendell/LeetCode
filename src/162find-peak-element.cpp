#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1)
			return 0;
		int low = 0, high = nums.size() - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if ((mid == nums.size() - 1 && nums[mid] > nums[mid - 1]) || (mid == 0 && nums[mid] > nums[mid + 1]) || (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]))
				return mid;
			else if (nums[mid] < nums[mid + 1])
				low = mid + 1;
			else
				high = mid - 1;
		}
		return 0;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 5,7,8,9,2 };
	cout << solute.findPeakElement(nums) << endl;
	return 0;
}
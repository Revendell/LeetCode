#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		//基本思想：折半查找
		int low = 0, high = nums.size() - 1;
		while (low < high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] < nums[high])
			{
				high = mid;
			}
			else if (nums[mid] > nums[high])
			{
				low = mid + 1;
			}
		}
		return nums[low];
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,2,3 };
	cout << solute.findMin(nums) << endl;
	return 0;
}
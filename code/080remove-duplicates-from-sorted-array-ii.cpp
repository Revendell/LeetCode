#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		//基本思想：双指针，一个慢指针left一个快指针right，快指针right往右查找满足条件的元素填入慢指针left中
		int left, right, prenum;
		if (nums.size() <= 2)
			return nums.size();
		left = right = 2;
		while(right < nums.size())
		{
			//如果right遇到不相同连续的数字，填入到慢指针left中，否则right一直往右移
			if (nums[right]!=nums[left-2])
			{
				nums[left++] = nums[right];
			}
			right++;
		}
		return left;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 0,0,1,1,1,1,2,3,3,3,4,5,6 };
	int res = solute.removeDuplicates(nums);
	for (int i = 0; i < res; i++)
		cout << nums[i] << " ";
	cout << endl;
	return 0;
}
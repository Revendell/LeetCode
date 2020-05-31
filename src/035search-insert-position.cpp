#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int low = 0, mid, high = nums.size() - 1;
		//�۰����targetֵ
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		//���û���ҵ�targetֵ����λ��high��low֮�䣬���뵽high+1����λ��
		return high + 1;
	}
};
int main()
{
	Solution solute;
	vector<int> nums = { 1,3,5,6 };
	int target = 0;
	cout << solute.searchInsert(nums, target) << endl;
	return 0;
}
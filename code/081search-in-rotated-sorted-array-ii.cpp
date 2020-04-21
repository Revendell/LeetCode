#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		//����˼�룺�۰����
		int low, high, mid;
		low = 0;
		high = nums.size() - 1;
		while (low<=high)
		{
			//ȥ���ظ����֣���ֹ2,2,2,3,2,2,2,2�����
			while (low < high && nums[low] == nums[low + 1])
				low++;
			while (low < high && nums[high] == nums[high - 1])
				high--;
			mid = (low + high) / 2;
			if (nums[mid] == target || nums[low] == target || nums[high] == target)
				return true;
			//target������벿��
			if (nums[low] < target)
			{
				//target������벿�ֵ��Ұ��
				if (nums[mid] < target && nums[mid] > nums[low])
					low = mid + 1;
				//target������벿�ֵ�����
				else
					high = mid - 1;
			}
			//target�����Ұ벿��
			else
			{
				//target�����Ұ벿�ֵ�����
				if (nums[mid] > target&& nums[mid] < nums[high])
					high = mid - 1;
				//target�����Ұ벿�ֵ��Ұ��
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
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
		//����˼�룺�����۰���ң���ת�����������Ϊ�����֣�target����λ����벿�֣�Ҳ����λ���Ұ벿�֣������������nums[low]<target��nums[low]>target
		while (low <= high)
		{
			mid = (low + high) / 2;
			//�ҵ�targetλ�ڵ�λ�÷����±�
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
			//���targetλ����벿�֣�����nums[mid]��λ�����������λ���Ұ벿�֣�λ����벿��target����ߣ�λ����벿��target���ұ�
			else if (nums[low] < target)
			{
				//midλ���Ұ벿�֣���targetλ����벿�֣�����high=mid-1��midλ����벿������target���ұߣ�����high=mid-1
				if (nums[mid] <= nums[low] || (nums[mid] > nums[low] && nums[mid] >= target))
				{
					high = mid - 1;
				}
				//midλ����벿������target����ߣ�����low=mid+1
				else if (nums[mid] > nums[low] && nums[mid] < target)
				{
					low = mid + 1;
				}
			}
			//���targetλ���Ұ벿�֣�����nums[mid]��λ�����������λ����벿�֣�λ���Ұ벿��target����ߣ�λ���Ұ벿��target���ұ�
			else if(nums[low] > target)
			{
				//midλ����벿�֣���targetλ���Ұ벿�֣�����low=mid+1��midλ���Ұ벿������target����ߣ�����low=mid+1
				if (nums[mid] >= nums[high] || (nums[mid] < nums[high] && nums[mid] < target))
				{
					low = mid + 1;
				}
				//midλ���Ұ벿������target���ұߣ�����high=mid-1
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